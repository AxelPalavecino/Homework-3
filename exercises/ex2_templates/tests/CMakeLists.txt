# Crear ejecutable de tests
add_executable(test_figuras 
    test_template_specialization.cpp
    ../src/Punto.cpp
    ../src/Circulo.cpp
    ../src/Elipse.cpp
    ../src/Rectangulo.cpp
)

# Agregar el test a CTest
add_test(NAME FigurasTest COMMAND test_figuras)

# Configurar propiedades del test
set_tests_properties(FigurasTest PROPERTIES
    PASS_REGULAR_EXPRESSION "Todos los tests pasaron exitosamente"
)
