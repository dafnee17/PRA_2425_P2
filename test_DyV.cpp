#include "DyV.h" // Incluir el archivo de cabecera
#include <iostream>
#include <vector>

void probarBusquedaBinaria() {
    // Prueba con enteros (ascendente)
    std::vector<int> enteros = {1, 3, 5, 7, 9, 11};
    std::cout << "Prueba con enteros (ascendente):" << std::endl;
    std::cout << "Buscando 7: " << BusquedaBinaria(7, enteros, 0, enteros.size() - 1) << std::endl;
    std::cout << "Buscando 4 (no está): " << BusquedaBinaria(4, enteros, 0, enteros.size() - 1) << std::endl;

    // Prueba con floats (ascendente)
    std::vector<float> flotantes = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::cout << "\nPrueba con floats (ascendente):" << std::endl;
    std::cout << "Buscando 3.3: " << BusquedaBinaria(3.3f, flotantes, 0, flotantes.size() - 1) << std::endl;
    std::cout << "Buscando 6.6 (no está): " << BusquedaBinaria(6.6f, flotantes, 0, flotantes.size() - 1) << std::endl;

    // Prueba con caracteres (ascendente)
    std::vector<char> caracteres = {'a', 'c', 'e', 'g', 'i'};
    std::cout << "\nPrueba con caracteres (ascendente):" << std::endl;
    std::cout << "Buscando 'e': " << BusquedaBinaria('e', caracteres, 0, caracteres.size() - 1) << std::endl;
    std::cout << "Buscando 'b' (no está): " << BusquedaBinaria('b', caracteres, 0, caracteres.size() - 1) << std::endl;
}

void probarBusquedaBinaria_INV() {
    // Prueba con enteros (descendente)
    std::vector<int> enteros = {11, 9, 7, 5, 3, 1};
    std::cout << "\nPrueba con enteros (descendente):" << std::endl;
    std::cout << "Buscando 7: " << BusquedaBinaria_INV(7, enteros, 0, enteros.size() - 1) << std::endl;
    std::cout << "Buscando 4 (no está): " << BusquedaBinaria_INV(4, enteros, 0, enteros.size() - 1) << std::endl;

    // Prueba con floats (descendente)
    std::vector<float> flotantes = {5.5f, 4.4f, 3.3f, 2.2f, 1.1f};
    std::cout << "\nPrueba con floats (descendente):" << std::endl;
    std::cout << "Buscando 3.3: " << BusquedaBinaria_INV(3.3f, flotantes, 0, flotantes.size() - 1) << std::endl;
    std::cout << "Buscando 6.6 (no está): " << BusquedaBinaria_INV(6.6f, flotantes, 0, flotantes.size() - 1) << std::endl;

    // Prueba con caracteres (descendente)
    std::vector<char> caracteres = {'i', 'g', 'e', 'c', 'a'};
    std::cout << "\nPrueba con caracteres (descendente):" << std::endl;
    std::cout << "Buscando 'e': " << BusquedaBinaria_INV('e', caracteres, 0, caracteres.size() - 1) << std::endl;
    std::cout << "Buscando 'b' (no está): " << BusquedaBinaria_INV('b', caracteres, 0, caracteres.size() - 1) << std::endl;
}

int main() {
    probarBusquedaBinaria();
    probarBusquedaBinaria_INV();
    return 0;
}

