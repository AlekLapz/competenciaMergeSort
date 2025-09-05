#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "mergeSort.h"

using namespace std;
using namespace chrono;

bool leerCSV(const string& filename, vector<int>& datos) {
    ifstream file(filename);
    if (!file.is_open()) return false;
    string line, token;
    while (getline(file, line)) {
        stringstream ss(line);
        while (getline(ss, token, ',')) {
            try {
                int num = stoi(token);
                datos.push_back(num);
            } catch (...) {}
        }
    }
    return !datos.empty();
}

int main() {
    string filename;
    cout << "Ingrese el nombre del archivo CSV (ej: prueba1.csv): ";
    cin >> filename;

    vector<int> data;
    if (!leerCSV(filename, data)) {
        cerr << "Error al leer datos válidos del archivo." << endl;
        return 1;
    }

    cout << "\nDatos originales:\n";
    printArray(data);

    auto start = high_resolution_clock::now();
    mergeSort(data, 0, data.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "\nDatos ordenados:\n";
    printArray(data);
    cout << "\nTiempo de ejecución: " << duration.count() << " microsegundos\n";

    // Guardar en CSV
    ofstream salida("ordenado.csv");
    for (size_t i = 0; i < data.size(); ++i) {
        salida << data[i];
        if (i < data.size() - 1) salida << ",";
    }
    salida << endl;
    cout << "Resultado guardado en 'ordenado.csv'\n";

    return 0;
}