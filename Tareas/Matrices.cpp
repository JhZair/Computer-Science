#include <iostream>
using namespace std;

const int N = 3;

void multiplicarMatrices(int* A, int* B, int* C) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            *(C + i * N + j) = 0;
            for (int k = 0; k < N; ++k)
                *(C + i * N + j) += *(A + i * N + k) * *(B + k * N + j);
        }
}

void imprimirMatriz(int* M) {
    for (int i = 0; i < N * N; ++i) {
        cout << *(M + i) << " ";
        if ((i + 1) % N == 0) cout << "\n";
    }
    cout << "\n";
}

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    int B[N][N] = {
        {7, 8, 9},
        {1, 2, 3},
        {4, 5, 6}
    };

    int C[N][N];  

    multiplicarMatrices(&A[0][0], &B[0][0], &C[0][0]);

    int (*resultado[3])[N] = { A, B, C };
    cout << "Matriz A" << ":\n";
    imprimirMatriz((int*)resultado[0]);
    cout << "Matriz B" << ":\n";
    imprimirMatriz((int*)resultado[1]);
    cout << "Matriz A*B" << ":\n";
    imprimirMatriz((int*)resultado[2]);

    return 0;
}
