#include <iostream>
using namespace std;

//agregar templates
class iterador{

	int *x;
	
public:
	void operator=(int *p){
		x = p;
	}
	void operator=(int p){
		*x = p;
	}
	bool operator<(int *p){
		return(x < p);
	}
	iterador operator++(){	//sobrecarga de prefix, para posfix es un int de par�metro.
		iterador a;		// probar hacer con puntero this para incrementar el puntero.
		a = ++x;
		return a;
	}
	friend ostream &operator<<( ostream &output, const iterador &i ) { 
		output << *(i.x);
		return output;            
	}
};

int main() {
	iterador iterador;
	int A[10] = {1,2,3,4,5,6,7,8,9,0};
	
	for (iterador = A; iterador < A+10; ++iterador) {
		cout << iterador << ' ';
	}
	
	cout<< endl;
	
	return 0;
}
/*hacer clase, que ordene un array(qick sort, bubble sort, etc) la parte de la condicion en el ordenamiento convertir a functor, con template.
el template que tenga tipo y orden. se tiene que llamar de esta forma: OrdenAsc.ordene(ini, fin), ini y fin son punteros.
y recorrer el array con el iterador,*/
