#include <iostream>
using namespace std;

int main() {
    // Declaración e inicialización del array con 16 elementos
    int arr[16] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160 };

    // Imprimir el array original
    cout << "Array original: ";
    for (int i = 0; i < 16; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Realice las siguientes operaciones:

    // 1. Modifique el elemento 5 (valor 60) utilizando una referencia llamada refA.


    // 2. Modifique el elemento 11 (valor 120) pasándolo a una función Por Dirección de memoria. 
    // La función se debe llamar modificarPorDireccion.


    // 3. Cree una función para modificar el elemento 6, usando la siguiente instrucción F(arr, 6) = 8;


    // 4. Invertir los valores de los elementos 1 (valor 20) y 10 (valor 110) usando swap 
    // con referencia y dirección.
    

    // 5. Modifique el elemento 13 (valor 140) utilizando un puntero ptr1 al inicio del array, 
    // al cual se le debe agregar un desplazamiento.


    // 6. Cree un puntero, llamado ptrW, al elemento 7. Luego cree un puntero ptrZ que apunte a ptrW. 
    // Luego coloque el valor de 51, al elemento 8 utilizando ptrZ.

    // 7. Cree un puntero ptrP al elemento 3. Luego cree una referencia a este puntero llamada refP. 
    // Utilizando esta referencia (sin usar directamente ptrP), modifique el valor del elemento 3 a 42.
    

    // 8. Cree un puntero ptrQ al elemento 9. Luego cree un puntero ptrR que apunte a ptrQ. 
    // Después, cree una referencia refR al puntero ptrR. 
    // Utilice esta referencia refR para modificar, con 77, el valor del elemento 8 
    // (que es anterior al elemento apuntado originalmente).

    // Imprimir el array modificado
    cout << "Array modificado: ";
    for (int i = 0; i < 16; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
