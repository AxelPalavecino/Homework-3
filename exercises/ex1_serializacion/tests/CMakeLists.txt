cmake_minimum_required(VERSION 3.10)

include_directories(../include)

add_executable(test_serializacion
    test_serializacion.cpp
    ../src/MedicionBase.cpp
    ../src/Posicion.cpp
    ../src/Presicion.cpp
    ../src/SaveFlightData.cpp
)

target_compile_features(test_serializacion PRIVATE cxx_std_17)

enable_testing()
add_test(NAME SerializationTests COMMAND test_serializacion)
