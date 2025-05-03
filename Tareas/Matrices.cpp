#include <iostream>
using namespace std;

void multiplicarMatrices(int** a, int** b, int** c) {
    for (int i=0;i<3;++i)
        for (int j=0; j<3;++j) {
            for (int k=0;k<3;++k){
                *(*(c+i)+j) += *(*(a+i)+k) * *(*(b+k) +j);
            }
        }
}

void imprimirMatriz(int** M) {
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            cout <<*(*(M+i) + j)<< " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int** A = new int*[3];
    int** B = new int*[3];
    int** C = new int*[3]();
    for (int i=0;i<3;++i) {
        *(A+i) = new int[3];
        *(B+i) = new int[3];
        *(C+i) = new int[3];
    }
    for (int i=0;i<3;++i)
        for (int j=0; j<3;++j) {
            *(*(A+i)+j) = i*3+j+1;
            *(*(B+i)+j) = i*3+j+5;
            *(*(C+i)+j) = 0;
        }

    multiplicarMatrices(A, B, C);

    int*** resultado = new int**[3];
    *(resultado+0) = A;
    *(resultado+1) = B;
    *(resultado+2) = C;

    cout << "Matriz A:\n";
    imprimirMatriz(*(resultado+0));
    cout << "Matriz B:\n";
    imprimirMatriz(*(resultado+1));
    cout << "Matriz C:\n";
    imprimirMatriz(*(resultado+2));

    for (int i=0; i<3;++i) {
        delete[] *(A+i);
        delete[] *(B+i);
        delete[] *(C+i);
    }
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] resultado;

    return 0;
}
