#include <iostream>
using namespace std;

int* rotarMatrx(int* m){
    int* t = new int[9];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            *(t+j*3+(2-i)) = *(m+i*3+j);
        }
    }
    delete[]m;
    return t;
}

int main(){
    int* m= new int[9];
    for(int i=0;i<9;i++){
        cin >> *(m+i);
    }
    cout << '\n';

    m = rotarMatrx(m);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){    
            cout << *(m+i*3+j) << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    delete[] m;
    return 0;
}

/*
Descripción:
Tienes una matriz 3x3 almacenada como un array plano (int*). Usa offset notation para rotarla 90° en sentido horario, sin usar índices como [][].

// Entrada: 1 2 3 4 5 6 7 8 9
1 2 3
4 5 6
7 8 9

// Salida esperada:
7 4 1
8 5 2
9 6 3
*/