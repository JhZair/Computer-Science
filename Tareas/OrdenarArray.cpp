#include <iostream>
using namespace std;

void mostrar(int* p) {
    for (int i=0;i<9;++i)
        cout << (*(p+i) ? to_string(*(p + i)) : " ") 
        << ((i + 1)%3 ?"  ":"\n");
}

bool estaOrdenado(int* p) {
    for (int i =0;i<9 - 1;++i)
        if (*(p + i)!= i+1) return false;
    return *(p+9-1) == 0;
}

int* encontrarCero(int* p) {
    for (int i=0; i<9;++i)
        if (*(p+i)==0) return p + i;
    return nullptr;
}

int main() {
    int** arr = new int*[3];
    for (int i = 0; i < 3; ++i) {
        *(arr+i) = new int[3];
    }

    *(*(arr+0)+0) = 1; *(*(arr+0)+1) = 4; *(*(arr+0)+2) = 2;
    *(*(arr+1)+0) = 0; *(*(arr+1)+1) = 5; *(*(arr+1)+2) = 3;
    *(*(arr+2)+0) = 6; *(*(arr+2)+1) = 7; *(*(arr+2)+2) = 8;

    int* p = *arr;
    mostrar(p);

    while (!estaOrdenado(p)) {
        int* cero = encontrarCero(p);
        int indice = cero - p;
        int fila_actual = indice / 3, columna_actual = indice % 3;

        char tecla;
        cout << "\nMovimiento:"; cin >> tecla;

        int nueva_fila = fila_actual + (tecla == 's') - (tecla == 'w');
        int nueva_columna = columna_actual + (tecla == 'd') - (tecla == 'a');
        if (nueva_fila >= 0 && nueva_fila < 3 && nueva_columna >= 0 && nueva_columna < 3)
            swap(*cero, *(p + nueva_fila * 3 + nueva_columna));

        mostrar(p);
    }
    cout << "\nGanaste\n";
    return 0;
}
