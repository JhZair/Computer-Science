#include <iostream>
#include <string>

using namespace std;

int Rectangulo(int base, int altura) 
{
	return base*altura;
}

int Triangulo(int base, int altura)   
{
	return (base*altura)/2;
}   

int Circulo(int radio ,int ) 
{  
	return radio*radio * 3.1416;  
}

int Cuadrado(int lado,int )
{
	return lado*lado;
}
	

void ejecuta(int (*pf)(int, int), int parametros[], string nombres[]) 
{
	cout << "Area del " << nombres[0] << ": "; 
	cout << pf(parametros[0], parametros[1]) << endl;
}
	
int main() {
		
	int paramsRectangulo[] = {5, 3};  
	int paramsTriangulo[] = {5, 3};   
	int paramsCirculo[] = {5, 0};    
	int paramsCuadrado[]={5, 5};     
		
	string n[] = {"rectángulo", "triángulo", "circulo", "cuadrado"};
		
	ejecuta(Rectangulo, paramsRectangulo, n);
	ejecuta(Triangulo, paramsTriangulo, n+1); 
	ejecuta(Circulo, paramsCirculo, n+2);     
	ejecuta(Cuadrado, paramsCuadrado,n+3);

}