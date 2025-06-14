#include <iostream>
#include <string>
using namespace std;


int Rectangulo(int base, int altura) {
    return base*altura;
}

int Triangulo(int base, int altura) {
    return (base*altura) / 2;
}

int Circulo(int radio,int) {
    return radio*radio * 3.1416;
}

int Cuadrado(int lado, int) {
    return lado*lado;
}

void ejecuta(int (*pfs[])(int,int), int parametros[][2], string nombres[]) {
    for (int i=0;i<4;++i) {
        cout << "Área del " <<nombres[i] << ": ";   
        cout << pfs[i](parametros[i][0], parametros[i][1]) << endl;  
    }
}

int main() {
    int (*pfs[])(int, int) = {Rectangulo, Triangulo, Circulo, Cuadrado};

    int parametros[4][2] = {{6,4}, {3,6}, {4,0}, {6,0}};

    string nombres[] = {"rectángulo", "triángulo", "círculo", "cuadrado"};

    ejecuta(pfs, parametros, nombres);

    return 0;
}
