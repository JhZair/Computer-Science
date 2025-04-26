#include <iostream>
using namespace std;

const int n = 3;

void mostrar(int* p) {
    for (int i = 0; i < n * n; ++i)
        cout << (*(p + i) ? to_string(*(p + i)) : " ") << ((i + 1) % n ? "  " : "\n");
}

bool estaOrdenado(int* p) {
    for (int i = 0; i < n*n-1; ++i)
        if (*(p + i) != i + 1) return false;
    return *(p + n * n - 1) == 0;
}

int* encontrarCero(int* p) {
    for (int i = 0; i < n * n; ++i)
        if (*(p + i) == 0) return p + i;
    return nullptr;
}

int main() {
    int arr[n][n] = {{1, 4, 2}, {0, 5, 3}, {6, 7, 8}};
    int* p = &arr[0][0];
    mostrar(p);

    while (!estaOrdenado(p)) {
        int* cero = encontrarCero(p);
        int indice = cero - p;
        int fila_actual = indice / n, columna_actual = indice % n;

        char tecla;
        cout << "\nMovimiento:"; cin >> tecla;

        int nueva_fila = fila_actual + (tecla == 's') - (tecla == 'w');
        int nueva_columna = columna_actual + (tecla == 'd') - (tecla == 'a');
        if (nueva_fila >= 0 && nueva_fila < n && nueva_columna >= 0 && nueva_columna < n)
            swap(*cero, *(p + nueva_fila * n + nueva_columna));

        mostrar(p);
    }
    cout << "\nGanaste\n";
    return 0;
}
