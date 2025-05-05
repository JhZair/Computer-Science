#include <iostream>
using namespace std;
void mostrar(int** a){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout << *(*(a+i)+j) << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool ordenada(int** a){
	int cont{1};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(*(*(a+i)+j) != cont++ % 9)
				return false;
		}
	}
	cout << "Esta ordenado";
	return true;
}

 int* buscarzero(int** a){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(*(*(a+i)+j) == 0)
				return *(a+i);
		}
	}
 }

int main() {

	cout << "Tienes que ordenar esta matriz!!"<< endl;
	int** matrix= new int*[3];
	for(int i=0;i<3;i++){
		*(matrix+i) = new int[3];
	}
	matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
	matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 0;
	matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 6; 
	
	mostrar(matrix);
	while(!ordenada(matrix)){
		int* zero = buscarzero(matrix);
	}

	return 0;
}

//ordenar array 3x3 que tenga un hueco que se mueva con las flechas 
//evitar sumar un iterador a un puntero en un bucle, sino cambiar de lugar los punteros

//tarea de multiplicar matrices funci�n mult(int (*p)[3][3])???
//matriz A=M[0] B=M[1], C=M[2], y m es un array tridimensional
