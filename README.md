# Homework-3: Serialización, Templates y JSON Builder

<div align="center">
    <hr style="height: 2px; background-color: #0066cc; width: 80%;">
    <p><em>Universidad de San Andrés - 2025</em></p>
    <hr style="height: 2px; background-color: #0066cc; width: 80%;">
</div>

## Índice de Contenidos

<div align="center">
    <img src="images/UdeSA.png" alt="UDESA Logo" width="150">
    <h1>Implementaciones Avanzadas de C++</h1>
</div>

<div align="center">
    <table>
        <tr>
            <td>
                <a href="#ejercicio-1-serialización-de-datos-de-vuelo">✈️ Ejercicio 1: Serialización de Datos de Vuelo</a>
            </td>
            <td>
                <a href="#ejercicio-2-templates-con-figuras-geométricas">📐 Ejercicio 2: Templates con Figuras Geométricas</a>
            </td>
        </tr>
        <tr>
            <td colspan="2">
                <a href="#ejercicio-3-constructor-de-json">🗂️ Ejercicio 3: Constructor de JSON</a>
            </td>
        </tr>
    </table>
</div>

---

## Compilación del Proyecto Completo

### Pasos para compilar

1. **Navegar al directorio del proyecto:**
   ```bash
   cd /home/udesa/Homework-3
   ```

2. **Crear directorio de compilación:**
   ```bash
   mkdir build && cd build
   ```

3. **Compilar con CMake:**
   ```bash
   cmake ..
   make
   ```

### Ejecución de ejercicios individuales

Desde el directorio `build/`:

```bash
# Ejercicio 1: Serialización de datos de vuelo
./exercises/ex1_serializacion/ex1_serializacion

# Ejercicio 2: Templates con figuras geométricas  
./exercises/ex2_templates/ex2_templates

# Ejercicio 3: Constructor de JSON
./exercises/ex3_json_builder/ex3_json_builder
```

### Limpiar compilación

Para recompilar desde cero:
```bash
cd /home/udesa/Homework-3
rm -rf build
mkdir build && cd build
cmake ..
make
```

---

## Estructura del proyecto
```
Homework-3/
├── exercises/
│   ├── ex1_serializacion/
│   │   ├── include/ex1/
│   │   │   ├── IMediciones.hpp
│   │   │   ├── MedicionBase.hpp
│   │   │   ├── Posicion.hpp
│   │   │   ├── Presion.hpp
│   │   │   └── SaveFlightData.hpp
│   │   ├── src/
│   │   │   ├── MedicionBase.cpp
│   │   │   ├── Posicion.cpp
│   │   │   ├── Presion.cpp
│   │   │   └── SaveFlightData.cpp
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   ├── ex2_templates/
│   │   ├── include/ex2/
│   │   │   ├── Punto.hpp
│   │   │   ├── Circulo.hpp
│   │   │   ├── Elipse.hpp
│   │   │   ├── Rectangulo.hpp
│   │   │   └── ProcesadorFigura.hpp
│   │   ├── src/
│   │   │   ├── Punto.cpp
│   │   │   ├── Circulo.cpp
│   │   │   ├── Elipse.cpp
│   │   │   └── Rectangulo.cpp
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   └── ex3_json_builder/
│       ├── include/ex3/
│       │   ├── ProcesadorDeDatos.hpp
│       │   └── ConstructorDeJSON.hpp
│       ├── src/
│       │   ├── ProcesadorDeDatos.cpp
│       │   └── ConstructorDeJSON.cpp
│       ├── main.cpp
│       └── CMakeLists.txt
├── build/                    # Directorio de compilación (se crea automáticamente)
├── images/                   # Logo de UdeSA
├── CMakeLists.txt           # Configuración principal de CMake
└── README.md                # Este archivo
```

---

## Ejercicio 1: Serialización de Datos de Vuelo

### Descripción

Este ejercicio implementa un sistema completo de serialización binaria para datos de vuelo, demostrando conceptos avanzados de programación orientada a objetos en C++, incluyendo el tema principal, **Serialización de datos**

### Arquitectura del Sistema

#### 1. Interfaz `IMediciones`
Define el contrato básico para serialización:
```cpp
class IMediciones {
public:
    virtual ~IMediciones() = default;
    virtual void serializar(std::ofstream &out) const = 0;
    virtual void deserializar(std::ifstream &in) = 0;
};
```

#### 2. Clase Base `MedicionBase`
Proporciona funcionalidad común con la dificultad que la gestion de memoria se realiza con `std::unique_ptr` para evitar fugas:
```cpp
class MedicionBase : public IMediciones {
protected:
    std::unique_ptr<float> tiempoMedicion;  // Gestión automática de memoria
public:
    MedicionBase(float t);
    MedicionBase(const MedicionBase& other);  // Constructor de copia personalizado
    // ...
};
```

#### 3. Clases Derivadas Especializadas

**Posición**: Maneja coordenadas geográficas y altitud
```cpp
class Posicion : public MedicionBase {
public:
    float latitud, longitud, altitud;
    // Serialización específica para datos geográficos
};
```

**Presión**: Gestiona datos atmosféricos
```cpp
class Presion : public MedicionBase {
public:
    float presionEstatica, presionDinamica;
    // Serialización específica para datos de presión
};
```

#### 4. Agregador `SaveFlightData`
Combina múltiples tipos de mediciones:
```cpp
class SaveFlightData {
public:
    Posicion posicion;
    Presion presion;
    
    void serializar(std::ofstream &out) const;
    void deserializar(std::ifstream &in);
};
```

### Características Técnicas

1. **Gestión de Memoria Automática**
   - Uso de `std::unique_ptr` para evitar fugas de memoria
   - Constructor de copia que maneja correctamente la duplicación de smart pointers

2. **Serialización Robusta**
   - Verificación de estado de streams en cada operación
   - Lanzamiento de excepciones descriptivas en caso de error
   - Formato binario para eficiencia de almacenamiento

### Compilación y Ejecución

```bash
cd /home/udesa/Homework-3/build
./exercises/ex1_serializacion/ex1_serializacion
```

El programa genera un archivo `vuelo.bin` con los datos serializados y demuestra la recuperación completa de la información.

---

## Ejercicio 2: Templates con Figuras Geométricas

### Descripción

Este ejercicio implementa un sistema de figuras geométricas utilizando **especialización de templates** para calcular áreas de diferentes formas geométricas, incluyendo para de paradigmas de programación orientados a objetos y programación genérica.

### Sistema de Figuras

#### 1. Clase Base `Punto`
Fundamento para todas las figuras geométricas:
```cpp
class Punto {
private:
    double x, y;
public:
    Punto();                        // Constructor por defecto (0,0)
    Punto(double _x, double _y);    // Constructor con coordenadas
    
    // Getters y setters
    double getX() const;
    double getY() const;
    void setPosicion(double _x, double _y);
};
```

#### 2. Figuras Geométricas Especializadas

**Círculo**: Define un círculo mediante centro y radio
```cpp
class Circulo {
private:
    Punto centro;
    double radio;
public:
    Circulo();                                    // Por defecto: centro(0,0), radio=1
    Circulo(const Punto& _centro, double _radio); // Con punto centro
    Circulo(double _x, double _y, double _radio); // Con coordenadas
};
```

**Elipse**: Extiende el concepto de círculo con dos semiejes
```cpp
class Elipse {
private:
    Punto centro;
    double semieje_mayor, semieje_menor;
public:
    Elipse();  // Por defecto: centro(0,0), semiejes 2 y 1
    Elipse(double _x, double _y, double _semieje_mayor, double _semieje_menor);
    Elipse(const Punto& _centro, double _semieje_mayor = 2, double _semieje_menor = 1);
};
```

**Rectángulo**: Define rectángulos alineados con los ejes
```cpp
class Rectangulo {
private:
    Punto vertice_inferior_izquierdo;
    double ancho, largo;
public:
    Rectangulo();  // Por defecto: vértice(0,0), dimensiones 1x1
    Rectangulo(double _x, double _y, double _ancho, double _largo);
    Rectangulo(const Punto& _vertice, double _ancho = 1, double _largo = 1);
};
```

#### 3. Template Especializado `ProcesadorFigura`

El corazón del sistema utiliza especialización de templates:

```cpp
// Template genérico
template<typename T>
class ProcesadorFigura {
public:
    static double calcularArea(const T& figura) {
        return 0.0;  // Implementación por defecto
    }
};

// Especializaciones para cada figura
template<>
class ProcesadorFigura<Circulo> {
public:
    static double calcularArea(const Circulo& circulo) {
        return M_PI * circulo.getRadio() * circulo.getRadio();
    }
};

template<>
class ProcesadorFigura<Elipse> {
public:
    static double calcularArea(const Elipse& elipse) {
        return M_PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
    }
};

template<>
class ProcesadorFigura<Rectangulo> {
public:
    static double calcularArea(const Rectangulo& rectangulo) {
        return rectangulo.getAncho() * rectangulo.getLargo();
    }
};
```

### Ventajas de la Especialización de Templates

1. **Polimorfismo en Tiempo de Compilación**
   - No hay overhead de runtime como con funciones virtuales
   - El compilador genera código optimizado específico para cada tipo

2. **Type Safety**
   - Cada especialización garantiza que solo se puede usar con el tipo correcto
   - Errores detectados en tiempo de compilación

3. **Extensibilidad**
   - Fácil agregar nuevas figuras sin modificar código existente
   - Solo requiere nueva especialización del template

### Programa de Demostración

El `main.cpp` demuestra todas las funcionalidades:

```cpp
// Creación con diferentes constructores
Circulo circulo1;                    // Constructor por defecto
Circulo circulo2(punto2, 5.0);       // Con punto y radio
Circulo circulo3(2.0, 3.0, 4.0);     // Con coordenadas y radio

// Cálculo de áreas usando templates especializados
double area1 = ProcesadorFigura<Circulo>::calcularArea(circulo1);
double area2 = ProcesadorFigura<Elipse>::calcularArea(elipse2);
double area3 = ProcesadorFigura<Rectangulo>::calcularArea(rect3);
```

### Compilación y Ejecución

```bash
cd /home/udesa/Homework-3/build
./exercises/ex2_templates/ex2_templates
```

---

## Ejercicio 3: Constructor de JSON

### Descripción

Este ejercicio implementa un sistema de procesamiento de datos en programación generica que utiliza **templates con `constexpr if`** para generar archivos JSON estructurados.

### Arquitectura del Sistema

#### 1. Clase Template `ProcesadorDeDatos`

```cpp
class ProcesadorDeDatos {
private:
    std::vector<double> doubles;
    std::vector<std::string> cadenas;
    std::vector<std::vector<int>> matrizEnteros;

public:
    template <typename T>
    void agregarDato(const T& dato) {
        if constexpr (std::is_same_v<T, double>) {
            doubles.push_back(dato);
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            cadenas.push_back(dato);
        }
        else if constexpr (std::is_same_v<T, std::vector<int>>) {
            matrizEnteros.push_back(dato);
        }
    }

    template <typename T>
    std::string procesarDatos() const {
        if constexpr (std::is_same_v<T, double>) {
            return formatoDoubles();
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            return formatoStrings();
        }
        else if constexpr (std::is_same_v<T, std::vector<int>>) {
            return formatoMatrizInts();
        }
        return "";
    }
};
```

#### 2. Formateadores Especializados

Cada tipo de dato tiene su propio formateador para JSON:

**Formateo de Doubles**:
```cpp
std::string formatoDoubles() const {
    std::string result = "[";
    for (size_t i = 0; i < doubles.size(); ++i) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << doubles[i];
        result += oss.str();
        if (i < doubles.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}
```

**Formateo de Strings**:
```cpp
std::string formatoStrings() const {
    std::string result = "[";
    for (size_t i = 0; i < cadenas.size(); ++i) {
        result += "\"" + cadenas[i] + "\"";  // Escapado JSON
        if (i < cadenas.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}
```

**Formateo de Matrices**:
```cpp
std::string formatoMatrizInts() const {
    std::string result = "[\n";
    for (size_t i = 0; i < matrizEnteros.size(); ++i) {
        result += "           [";
        for (size_t j = 0; j < matrizEnteros[i].size(); ++j) {
            result += std::to_string(matrizEnteros[i][j]);
            if (j < matrizEnteros[i].size() - 1) result += ", ";
        }
        result += "]";
        if (i < matrizEnteros.size() - 1) result += ",";
        result += "\n";
    }
    result += "           ]";
    return result;
}
```

#### 3. Constructor de JSON

La clase `ConstructorDeJSON` ensambla las partes formateadas:

```cpp
class ConstructorDeJSON {
private:
    std::vector<std::pair<std::string, std::string>> partesJSON;

public:
    void agregarSeccion(const std::string& etiqueta, const std::string& contenido);
    void PrintearJSON() const;
    void guardarEnArchivo(const std::string& nombreArchivo = "output.json") const;
};
```

### Características Técnicas de Programación Genérica

#### Uso de `constexpr if` (C++17)

La característica clave del ejercicio es el uso de `constexpr if` que permite:

- **Evaluación en tiempo de compilación**: Las condiciones se resuelven durante la compilación
- **Eliminación de código muerto**: Solo se genera código para las ramas que se ejecutarán

### Ejemplo de Uso y Salida

```cpp
ProcesadorDeDatos processor;

// Agregar datos de diferentes tipos
processor.agregarDato(1.3);
processor.agregarDato(2.1);
processor.agregarDato(3.2);

processor.agregarDato(std::string("Hola, Mundo"));

processor.agregarDato(std::vector<int>{1, 2});
processor.agregarDato(std::vector<int>{3, 2});

// Crear JSON
ConstructorDeJSON builder;
builder.agregarSeccion("vec_doubles", processor.procesarDatos<double>());
builder.agregarSeccion("palabras", processor.procesarDatos<std::string>());
builder.agregarSeccion("listas", processor.procesarDatos<std::vector<int>>());

builder.PrintearJSON();
builder.guardarEnArchivo("output.json");
```

**Salida JSON generada**:
```json
{
  "vec_doubles" : [1.3, 2.1, 3.2],
  "palabras" : ["Hola, Mundo"],
  "listas" : [
           [1, 2],
           [3, 2]
           ]
}
```

### Compilación y Ejecución

```bash
cd /home/udesa/Homework-3/build
./exercises/ex3_json_builder/ex3_json_builder
```

El programa genera un archivo `output.json` con los datos formateados y muestra el resultado por consola.

---