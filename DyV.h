#ifndef DYV_H
#define DYV_H

#include <vector>
#include <algorithm>
#include <cstdlib> // Para la función rand

// -----------------------------
// Búsqueda Binaria Ascendente
// -----------------------------

template <typename T>
int BusquedaBinaria(T x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // Valor no encontrado
    }

    int medio = (ini + fin) / 2;

    if (v[medio] == x) {
        return medio; // Valor encontrado
    } else if (v[medio] > x) {
        return BusquedaBinaria(x, v, ini, medio - 1); // Busca en la parte izquierda
    } else {
        return BusquedaBinaria(x, v, medio + 1, fin); // Busca en la parte derecha
    }
}

// -----------------------------
// Búsqueda Binaria Descendente
// -----------------------------

template <typename T>
int BusquedaBinaria_INV(T x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // Valor no encontrado
    }

    int medio = (ini + fin) / 2;

    if (v[medio] == x) {
        return medio; // Valor encontrado
    } else if (v[medio] < x) {
        return BusquedaBinaria_INV(x, v, ini, medio - 1); // Busca en la parte izquierda
    } else {
        return BusquedaBinaria_INV(x, v, medio + 1, fin); // Busca en la parte derecha
    }
}

// -----------------------------
// QuickSort con particiones
// -----------------------------

template <typename T, typename PartitionFunc>
void QuickSort(std::vector<T>& v, int ini, int fin, PartitionFunc partitionFunc) {
    if (ini < fin) {
        int pivot = partitionFunc(v, ini, fin);
        QuickSort(v, ini, pivot - 1, partitionFunc);
        QuickSort(v, pivot + 1, fin, partitionFunc);
    }
}

// Función de partición: pivote como el primer elemento
template <typename T>
int Partition_First(std::vector<T>& v, int ini, int fin) {
    T pivot = v[ini];
    int i = ini + 1;
    for (int j = ini + 1; j <= fin; ++j) {
        if (v[j] < pivot) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[ini], v[i - 1]);
    return i - 1;
}

// Función de partición: pivote aleatorio
template <typename T>
int Partition_Random(std::vector<T>& v, int ini, int fin) {
    int randomIndex = ini + rand() % (fin - ini + 1);
    std::swap(v[ini], v[randomIndex]);
    return Partition_First(v, ini, fin); // Reutilizamos Partition_First
}

// Función de partición: pivote central
template <typename T>
int Partition_Mid(std::vector<T>& v, int ini, int fin) {
    int midIndex = ini + (fin - ini) / 2;
    std::swap(v[ini], v[midIndex]);
    return Partition_First(v, ini, fin); // Reutilizamos Partition_First
}

#endif // DYV_H

