#include <iostream>
#include <vector>
#include <chrono>
#include "DyV.h" // Incluir el archivo de cabecera que contiene las implementaciones

// Función para medir y mostrar el tiempo de ejecución de QuickSort
template <typename T, typename PartitionFunc>
void medirQuickSort(std::vector<T> vec, const std::string& descripcion, PartitionFunc partitionFunc) {
    auto start = std::chrono::system_clock::now();
    QuickSort(vec, 0, vec.size() - 1, partitionFunc);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout << descripcion << " Time: " << duration.count() << " ms" << std::endl;
}

// Función para probar QuickSort con varios tipos de datos
void probarQuickSort() {
    // Datos de prueba
    std::vector<int> enteros = {10, 7, 8, 9, 1, 5};
    std::vector<float> flotantes = {4.5, 2.2, 5.1, 3.3, 1.1};
    std::vector<char> caracteres = {'z', 'e', 'a', 'r', 'm'};

    // Medir tiempos con diferentes estrategias de partición
    medirQuickSort(enteros, "Enteros - Pivote primero", Partition_First<int>);
    medirQuickSort(enteros, "Enteros - Pivote aleatorio", Partition_Random<int>);
    medirQuickSort(enteros, "Enteros - Pivote central", Partition_Mid<int>);

    medirQuickSort(flotantes, "Flotantes - Pivote primero", Partition_First<float>);
    medirQuickSort(flotantes, "Flotantes - Pivote aleatorio", Partition_Random<float>);
    medirQuickSort(flotantes, "Flotantes - Pivote central", Partition_Mid<float>);

    medirQuickSort(caracteres, "Caracteres - Pivote primero", Partition_First<char>);
    medirQuickSort(caracteres, "Caracteres - Pivote aleatorio", Partition_Random<char>);
    medirQuickSort(caracteres, "Caracteres - Pivote central", Partition_Mid<char>);
}

// Función para probar la búsqueda binaria ascendente
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

// Función para probar la búsqueda binaria descendente
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
    // Probar QuickSort
    probarQuickSort();

    // Probar Búsqueda Binaria Ascendente
    probarBusquedaBinaria();

    // Probar Búsqueda Binaria Descendente
    probarBusquedaBinaria_INV();

    return 0;
}
