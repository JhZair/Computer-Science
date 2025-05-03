#include <iostream>
using namespace std;

const int N = 3;

void mostrar(int* p) {
    for (int i = 0; i < N * N; ++i)
        cout << (*(p + i) ? to_string(*(p + i)) : " ") << ((i + 1) % N ? "  " : "\n");
}

bool estaOrdenado(int* p) {
    for (int i = 0; i < N*N-1; ++i)
        if (*(p + i) != i + 1) return false;
    return *(p + N * N - 1) == 0;
}

int* encontrarCero(int* p) {
    for (int i = 0; i < N * N; ++i)
        if (*(p + i) == 0) return p + i;
    return nullptr;
}

int main() {
    int arr[N][N] = {{1, 4, 2}, {0, 5, 3}, {6, 7, 8}};
    int* p = &arr[0][0];
    mostrar(p);

    while (!estaOrdenado(p)) {
        int* cero = encontrarCero(p);
        int indice = cero - p;
        int fila_actual = indice / N, columna_actual = indice % N;

        char tecla;
        cout << "\nMovimiento:"; cin >> tecla;

        int nueva_fila = fila_actual + (tecla == 's') - (tecla == 'w');
        int nueva_columna = columna_actual + (tecla == 'd') - (tecla == 'a');
        if (nueva_fila >= 0 && nueva_fila < N && nueva_columna >= 0 && nueva_columna < N)
            swap(*cero, *(p + nueva_fila * N + nueva_columna));

        mostrar(p);
    }
    cout << "\nGanaste\n";
    return 0;
}
