#include <iostream>
using namespace std;

//agregar templates
class iteratorx{

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
	iteratorx operator++(){	//sobrecarga de prefix, para posfix es un int de parámetro.
		iteratorx a;		// probar hacer con puntero this para incrementar el puntero.
		a = ++x;
		return a;
	}
	friend ostream &operator<<( ostream &output, const iteratorx &i ) { 
		output << *(i.x);
		return output;            
	}
};

int main() {
	iteratorx it;
	int A[10] = {1,2,3,4,5,6,7,8,9,0};
	
	for (it = A; it < A+10; ++it) {
		cout << it << ' ';
	}
	
	cout<< endl;
	
	return 0;
}
/*hacer clase, que ordene un array(qick sort, bubble sort, etc) la parte de la condición en el ordenamiento ocnvertir a functor, con template.
el template que tenga tipo y orden. se tiene que llamar de esta forma: OrdenAsc.ordene(ini, fin), ini y fin son punteros.
y recorrer el array con en iterador,*/
