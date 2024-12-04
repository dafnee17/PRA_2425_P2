#ifndef DYV_H
#define DYV_H

#include <vector>

// Función plantilla para búsqueda binaria en vectores ascendentes
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

// Función plantilla para búsqueda binaria en vectores descendentes
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

#endif // DYV_H

