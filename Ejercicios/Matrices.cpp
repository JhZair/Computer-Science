#include <iostream>
using namespace std;

void multiplicarMatrices(int* a, int* b, int* c) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            *(c + i * 3 + j) = 0;
            for (int k = 0; k < 3; ++k)
                *(c + i * 3 + j) += *(a + i * 3 + k) * *(b + k * 3 + j);
        }
}

void imprimirMatriz(int* M) {
    for (int i = 0; i < 3 * 3; ++i) {
        cout << *(M + i) << " ";
        if ((i + 1) % 3 == 0) cout << "\n";
    }
    cout << "\n";
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    int B[3][3] = {
        {7, 8, 9},
        {1, 2, 3},
        {4, 5, 6}
    };

    int C[3][3];

    multiplicarMatrices(&A[0][0], &B[0][0], &C[0][0]);

    int (*resultado[3])[3] = { A, B, C };
    cout << "Matriz A:\n";
    imprimirMatriz((int*)resultado[0]);
    cout << "Matriz B:\n";
    imprimirMatriz((int*)resultado[1]);
    cout << "Matriz C:\n";
    imprimirMatriz((int*)resultado[2]);

    return 0;
}

