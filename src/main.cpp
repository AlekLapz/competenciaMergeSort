#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "mergeSort.h"
using namespace std;
using namespace std::chrono;

int main() {
    int n;

    cout << "Ingrese la cantidad de elementos a ordenar: ";
    cin >> n;

    // Crear arreglo dinámico
    int* arr = new int[n];

    // Semilla para números aleatorios
    srand(time(0));

    // Llenar el arreglo con valores aleatorios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // valores entre 0 y 999
    }



    // Tomar tiempo de inicio
    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, n - 1);

    // Tomar tiempo de fin
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Mostrar arreglo ordenado  y tiempo de ejecución  
        cout << "\nArreglo ordenado:\n";
        printArray(arr, n);

    cout << "\nTiempo de ejecución: " << duration.count() << " milisegundos\n";

    // Liberar memoria
    delete[] arr;

    return 0;
}
