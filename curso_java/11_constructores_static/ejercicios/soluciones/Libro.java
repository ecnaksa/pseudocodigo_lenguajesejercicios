/* Ejercicio 3 - Clase Libro con constructor y toString. */
public class Libro {
    private String titulo;
    private String autor;
    private int paginas;

    public Libro(String titulo, String autor, int paginas) {
        this.titulo = titulo;
        this.autor = autor;
        this.paginas = paginas;
    }

    @Override
    public String toString() {
        return "\"" + titulo + "\" de " + autor + " (" + paginas + " paginas)";
    }

    public static void main(String[] args) {
        Libro l = new Libro("El Quijote", "Cervantes", 863);
        System.out.println(l);
    }
}
