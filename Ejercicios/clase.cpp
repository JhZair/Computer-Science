#include <iostream>
using namespace std;

int main(){
    int matrix[4][3] = {{9,5,3}, {4,7,2}, {7,8,2},{1,8,4}};
    // cout << *(*(matrix +3)+2) << endl;
    int (*p)[3] = matrix;
    cout << **(p)<< endl;
    
    int a = 5
    int && r = 10;
    r= 5;
    cout << r<< endl;
    return 0;

}
//por qué al declarar array estáticos estos son continuos y dinámicos no son continuos?
//     es por qué se piden en tiempos distintos
//     se tiene que crear al puntero doble como *(p)[3] para poder ser continua??
//diferencia entre ++i y i++ en un for:

//por qué se hace *(p)[3] y no **p?

// entender bien los problemas de matriz lineal y con punteros, tmb dibujar ejercicios para entenderlos

/*! aritmetica de punteros: punteros, referencias, contenido de punteros y direcciones de memoria
    y sus variantes con dobles punteros, */

// capitulo 16 de libro stroupsup 3ra edicion