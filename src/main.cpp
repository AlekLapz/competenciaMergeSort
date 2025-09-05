#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "mergeSort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "mergeSort.h"
using namespace std;
using namespace std::chrono;

int main() {
    
        string filename;
    cout << "Ingrese el nombre del archivo CSV (ej: datos.csv): ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return 1;
    }

    vector<int> data;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) {
            try {
                int value = stoi(token);
                data.push_back(value);
            } catch (...) {
                // Ignorar encabezados u otros errores
            }
        }
    }

    file.close();
    int n= data.size();

    // Crear arreglo dinámico
    int* arr = new int[n];

    // Semilla para números aleatorios
    srand(time(0));

    // Llenar el arreglo con valores aleatorios
    for (int i = 0; i < n; i++) {
        arr[i] = data[i]; // valores entre 0 y 999
    }



    // Tomar tiempo de inicio
    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, n - 1);

    // Tomar tiempo de fin
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    // Mostrar arreglo ordenado  y tiempo de ejecución  
        cout << "\nArreglo ordenado:\n";
        printArray(arr, n);

    cout << "\nTiempo de ejecución: " << duration.count() << " nanosegundos\n";

    // Liberar memoria
    delete[] arr;

    return 0;
}
