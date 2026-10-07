#include <iostream>
using namespace std;

void bestFit(int blockSize[], int m, const int processSize[], int n)
{
    // Arreglo dinámico para guardar el bloque asignado (-1 si no se asigna)
    int* allocation = new int[n];

    for (int i = 0; i < n; ++i)
        allocation[i] = -1;

    // Algoritmo Best-Fit
    for (int i = 0; i < n; ++i) {
        int bestIdx = -1;
        for (int j = 0; j < m; ++j) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // Si se encontró el mejor bloque que puede alojarlo
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i]; // Particionamiento dinámico
        }
    }

    // Salida de resultados
    cout << "\n=== ALGORITMO BEST-FIT (MEJOR AJUSTE) ===\n";
    cout << "No. Proceso\tTamano Proceso\tNo. Bloque\n";
    for (int i = 0; i < n; ++i) {
        cout << " " << (i + 1) << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << (allocation[i] + 1);
        else
            cout << "No Asignado";
        cout << "\n";
    }

    delete[] allocation;
}
