# Lección 06 — Herencia y polimorfismo

Dos pilares de la POO. La **herencia** permite crear una clase **a partir de otra**, reutilizando
su código. El **polimorfismo** permite tratar objetos de distintas clases relacionadas **de forma
uniforme**.

## Herencia: reutilizar y extender

Imagina que tienes una clase `Animal` y quieres `Perro` y `Gato`, que **comparten** cosas
(nombre, comer) pero **añaden** o **cambian** otras. En vez de repetir código, `Perro` y `Gato`
**heredan** de `Animal`:

```cpp
class Animal {                 // clase base (o "padre")
protected:
    string nombre;
public:
    Animal(const string &n) : nombre(n) {}
    void comer() { cout << nombre << " esta comiendo\n"; }
};

class Perro : public Animal {  // Perro HEREDA de Animal
public:
    Perro(const string &n) : Animal(n) {}    // llama al constructor de la base
    void ladrar() { cout << nombre << " dice guau\n"; }
};
```

- `class Perro : public Animal` significa "`Perro` es un `Animal`" (herencia pública).
- `Perro` **hereda** los miembros de `Animal` (`nombre`, `comer`) y **añade** los suyos
  (`ladrar`).
- El constructor de `Perro` llama al de `Animal` en la lista de inicialización: `: Animal(n)`.

```cpp
Perro p("Rex");
p.comer();     // heredado de Animal
p.ladrar();    // propio de Perro
```

### `protected`

Un tercer nivel de acceso, entre `public` y `private`:
- **`private`**: solo la propia clase.
- **`protected`**: la propia clase **y sus clases derivadas** (pero no desde fuera).
- **`public`**: todos.

Por eso `nombre` es `protected` en `Animal`: para que `Perro` pueda usarlo, pero no el código
externo.

## Redefinir métodos (override)

Una clase derivada puede **cambiar** el comportamiento de un método heredado, definiéndolo de
nuevo:

```cpp
class Animal {
public:
    void hacerSonido() { cout << "Sonido generico\n"; }
};
class Gato : public Animal {
public:
    void hacerSonido() { cout << "Miau\n"; }   // redefine el de Animal
};
```

Pero aquí aparece un problema sutil que resuelve el **polimorfismo**.

## Polimorfismo y funciones `virtual`

El **polimorfismo** ("muchas formas") permite que **un puntero o referencia a la clase base**
llame al método de la clase derivada **correcta** en tiempo de ejecución. Para activarlo, el método
de la base debe declararse **`virtual`**:

```cpp
class Animal {
public:
    virtual void hacerSonido() {     // virtual: se resolvera en tiempo de ejecucion
        cout << "Sonido generico\n";
    }
    virtual ~Animal() {}             // destructor virtual (ver nota abajo)
};

class Perro : public Animal {
public:
    void hacerSonido() override {    // override documenta que redefine un virtual
        cout << "Guau\n";
    }
};
class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "Miau\n";
    }
};
```

Ahora la magia: podemos guardar distintos animales en un arreglo de **punteros a `Animal`** y
llamar `hacerSonido()` sin saber cuál es cuál; cada uno responde según su tipo real:

```cpp
Animal *animales[2];
animales[0] = new Perro();
animales[1] = new Gato();
for (int i = 0; i < 2; i++) {
    animales[i]->hacerSonido();    // Guau, luego Miau (¡el correcto de cada uno!)
}
for (int i = 0; i < 2; i++) delete animales[i];   // liberar
```

**Sin `virtual`**, `animales[i]->hacerSonido()` llamaría siempre al de `Animal` (el tipo del
puntero). **Con `virtual`**, llama al de la clase real del objeto. Eso es el polimorfismo, y es la
base de diseños flexibles y extensibles.

- **`override`** (opcional pero recomendado) le dice al compilador "esto redefine un método
  virtual"; si te equivocas en la firma, te avisa.
- **Destructor `virtual`:** si vas a borrar objetos derivados a través de un puntero a la base
  (`delete animalPtr`), la base **debe** tener un destructor `virtual`, o no se llamará al
  destructor correcto. Regla: **toda clase base polimórfica lleva destructor virtual**.

## Clases abstractas (funciones virtuales puras)

A veces la clase base representa un **concepto** que no tiene una implementación concreta (¿qué
sonido hace un "Animal" genérico?). Puedes declarar un método **virtual puro** con `= 0`, lo que
hace la clase **abstracta**: no se puede instanciar, y **obliga** a las derivadas a implementar ese
método.

```cpp
class Figura {
public:
    virtual double area() = 0;       // virtual pura: sin cuerpo
    virtual ~Figura() {}
};
// Figura f;   // ERROR: es abstracta
class Circulo : public Figura {
    double r;
public:
    Circulo(double radio) : r(radio) {}
    double area() override { return 3.14159 * r * r; }
};
```
Es una forma de definir una **interfaz**: "todo lo que sea `Figura` debe tener `area()`".

## Errores típicos

- Olvidar `virtual` en la base → no hay polimorfismo (se llama al método equivocado).
- Olvidar el **destructor virtual** en una base polimórfica → fugas al borrar por la base.
- No llamar al constructor de la base cuando esta no tiene constructor por defecto.
- Confundir herencia ("es un") con composición ("tiene un"): un `Coche` **tiene un** motor (no
  hereda de Motor).

## Resumen

- **Herencia** (`class Derivada : public Base`): reutiliza y extiende; `protected` es visible para
  las derivadas.
- El constructor de la derivada llama al de la base en la lista de inicialización.
- **`virtual`** + puntero/referencia a la base = **polimorfismo**: se llama al método de la clase
  real. Usa `override` en las derivadas.
- Base polimórfica → **destructor virtual**.
- Método **virtual puro** (`= 0`) → clase **abstracta** (interfaz).

## Ejemplos

- [`ejemplos/animales.cpp`](ejemplos/animales.cpp)
- [`ejemplos/figuras.cpp`](ejemplos/figuras.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 5 ("Class Hierarchies").
- **learncpp.com**, capítulos de "Inheritance" y "Virtual Functions".
- **cppreference**, "Derived classes", "virtual function".
  https://en.cppreference.com/w/cpp/language/derived_class
