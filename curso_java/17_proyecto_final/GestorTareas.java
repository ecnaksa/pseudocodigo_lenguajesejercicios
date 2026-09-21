/*
 * Proyecto final del curso de Java: gestor de tareas (to-do list) por consola.
 *
 * Integra lo esencial del curso:
 *   - POO: la clase Tarea encapsula su estado (campos private) y expone metodos.
 *   - enum: la prioridad (ALTA / MEDIA / BAJA).
 *   - Colecciones: un ArrayList<Tarea> guarda las tareas.
 *   - Excepciones: se validan las entradas del usuario.
 *   - Streams: se calculan estadisticas y se filtran las pendientes.
 *   - switch: dirige el menu principal.
 *
 * Compilar y ejecutar:
 *   javac GestorTareas.java
 *   java GestorTareas
 */
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/* ------------------------------------------------------------------ */
/* Prioridad: un enum con tres valores fijos. Un enum es un tipo cuyo  */
/* conjunto de valores esta cerrado y es conocido en tiempo de        */
/* compilacion; es mas seguro que usar cadenas o numeros "magicos".   */
/* ------------------------------------------------------------------ */
enum Prioridad {
    ALTA, MEDIA, BAJA
}

/* ------------------------------------------------------------------ */
/* Tarea: representa el "dato". Encapsula su estado con campos private */
/* y lo expone mediante metodos. Es responsable solo de UNA tarea.     */
/* ------------------------------------------------------------------ */
class Tarea {
    private final String descripcion;
    private final Prioridad prioridad;
    private boolean completada;

    public Tarea(String descripcion, Prioridad prioridad) {
        this.descripcion = descripcion;
        this.prioridad = prioridad;
        this.completada = false;   // toda tarea nace pendiente
    }

    public void completar() {
        this.completada = true;
    }

    public boolean estaCompletada() {
        return completada;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public Prioridad getPrioridad() {
        return prioridad;
    }

    @Override
    public String toString() {
        String marca = completada ? "[X]" : "[ ]";
        return marca + " (" + prioridad + ") " + descripcion;
    }
}

/* ------------------------------------------------------------------ */
/* GestorTareas: contiene la LOGICA (la lista, el menu, las            */
/* operaciones) y el main. Separar el "dato" (Tarea) de la "logica"    */
/* (GestorTareas) es un patron muy comun y limpio en Java.             */
/* ------------------------------------------------------------------ */
public class GestorTareas {

    private final List<Tarea> tareas = new ArrayList<>();
    private final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new GestorTareas().ejecutar();
    }

    /* Bucle principal: muestra el menu y despacha la opcion elegida. */
    private void ejecutar() {
        boolean salir = false;
        while (!salir) {
            mostrarMenu();
            int opcion = leerEntero("Elige una opcion: ");
            System.out.println();
            switch (opcion) {
                case 1 -> agregar();
                case 2 -> listar();
                case 3 -> marcarCompletada();
                case 4 -> eliminar();
                case 5 -> verPendientes();
                case 6 -> estadisticas();
                case 0 -> {
                    System.out.println("Hasta pronto!");
                    salir = true;
                }
                default -> System.out.println("Opcion no valida. Intenta de nuevo.");
            }
            System.out.println();
        }
    }

    private void mostrarMenu() {
        System.out.println("== GESTOR DE TAREAS ==");
        System.out.println("1) Agregar tarea");
        System.out.println("2) Listar tareas");
        System.out.println("3) Marcar como completada");
        System.out.println("4) Eliminar tarea");
        System.out.println("5) Ver solo pendientes");
        System.out.println("6) Estadisticas");
        System.out.println("0) Salir");
    }

    /* --- Opcion 1: agregar una tarea nueva. --- */
    private void agregar() {
        System.out.print("Descripcion: ");
        String descripcion = sc.nextLine().trim();
        if (descripcion.isEmpty()) {
            System.out.println("La descripcion no puede estar vacia. Cancelado.");
            return;
        }
        Prioridad prioridad = leerPrioridad();
        tareas.add(new Tarea(descripcion, prioridad));
        System.out.println("Tarea agregada.");
    }

    /* --- Opcion 2: listar todas las tareas con su indice. --- */
    private void listar() {
        if (tareas.isEmpty()) {
            System.out.println("No hay tareas.");
            return;
        }
        System.out.println("Tareas:");
        for (int i = 0; i < tareas.size(); i++) {
            System.out.println("  " + (i + 1) + ". " + tareas.get(i));
        }
    }

    /* --- Opcion 3: marcar una tarea como completada por su numero. --- */
    private void marcarCompletada() {
        if (tareas.isEmpty()) {
            System.out.println("No hay tareas.");
            return;
        }
        listar();
        int n = leerEntero("Numero de la tarea a completar: ");
        Tarea t = obtenerTarea(n);
        if (t == null) {
            System.out.println("Numero fuera de rango.");
            return;
        }
        t.completar();
        System.out.println("Tarea marcada como completada.");
    }

    /* --- Opcion 4: eliminar una tarea por su numero. --- */
    private void eliminar() {
        if (tareas.isEmpty()) {
            System.out.println("No hay tareas.");
            return;
        }
        listar();
        int n = leerEntero("Numero de la tarea a eliminar: ");
        if (n < 1 || n > tareas.size()) {
            System.out.println("Numero fuera de rango.");
            return;
        }
        Tarea eliminada = tareas.remove(n - 1);
        System.out.println("Eliminada: " + eliminada.getDescripcion());
    }

    /* --- Opcion 5: ver solo las tareas pendientes (con un stream). --- */
    private void verPendientes() {
        List<Tarea> pendientes = tareas.stream()
                .filter(t -> !t.estaCompletada())
                .toList();
        if (pendientes.isEmpty()) {
            System.out.println("No hay tareas pendientes. Buen trabajo!");
            return;
        }
        System.out.println("Pendientes:");
        pendientes.forEach(t -> System.out.println("  - " + t));
    }

    /* --- Opcion 6: estadisticas (contar con streams). --- */
    private void estadisticas() {
        long total = tareas.size();
        long completadas = tareas.stream().filter(Tarea::estaCompletada).count();
        long pendientes = total - completadas;
        long altas = tareas.stream()
                .filter(t -> t.getPrioridad() == Prioridad.ALTA)
                .count();

        System.out.println("Estadisticas:");
        System.out.println("  Total:        " + total);
        System.out.println("  Completadas:  " + completadas);
        System.out.println("  Pendientes:   " + pendientes);
        System.out.println("  Prioridad ALTA: " + altas);
        if (total > 0) {
            double porcentaje = 100.0 * completadas / total;
            System.out.printf("  Progreso:     %.1f%%%n", porcentaje);
        }
    }

    /* ------------------------- utilidades -------------------------- */

    /* Devuelve la tarea en la posicion 1..n, o null si esta fuera de rango. */
    private Tarea obtenerTarea(int numero) {
        if (numero < 1 || numero > tareas.size()) {
            return null;
        }
        return tareas.get(numero - 1);
    }

    /*
     * Lee un entero con reintento. Envuelve la lectura en try/catch para
     * capturar NumberFormatException si el usuario escribe algo que no es
     * un numero: en vez de romper el programa, vuelve a pedirlo.
     */
    private int leerEntero(String mensaje) {
        while (true) {
            System.out.print(mensaje);
            String linea = sc.nextLine().trim();
            try {
                return Integer.parseInt(linea);
            } catch (NumberFormatException e) {
                System.out.println("  Eso no es un numero entero. Intenta de nuevo.");
            }
        }
    }

    /*
     * Lee una prioridad. Acepta ALTA / MEDIA / BAJA (sin importar
     * mayusculas). Si la entrada no es valida, usa MEDIA por defecto.
     * Valueof lanzaria IllegalArgumentException con un texto desconocido;
     * lo capturamos para no romper el flujo.
     */
    private Prioridad leerPrioridad() {
        System.out.print("Prioridad (ALTA/MEDIA/BAJA): ");
        String texto = sc.nextLine().trim().toUpperCase();
        try {
            return Prioridad.valueOf(texto);
        } catch (IllegalArgumentException e) {
            System.out.println("  Prioridad no reconocida; se usara MEDIA.");
            return Prioridad.MEDIA;
        }
    }
}
