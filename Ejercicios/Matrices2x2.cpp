#include <iostream>
using namespace std;

int** multplicar(int** a, int** b){
    int** c = new int* [3];
    for(int i=0;i<3;i++)
        *(c+i) = new int[3];
        
    
    for(int i=0;i<3;i++){
        for(int e=0;e<3;e++){
            int t{0};
            for(int j=0;j<3;j++){
                t += *(*(a+i)+j) * *(*(b+j)+e);
            }
            *(*(c+e)+i) = t;
        }
    }
    return c;
}


int main(){
    int** matrixA = new int * [3];
    for(int i=0;i<3;i++){
        *(matrixA+i) = new int[3];
        for(int e = 0; e < 3;e++){
            *(*(matrixA+i)+e) = (e+i)*4;
        }
    }

    int** matrixB = new int * [3];
    for(int i=0;i<3;i++){
        *(matrixB+i) = new int[3];
        for(int e = 0; e < 3;e++){
            *(*(matrixB+i)+e) = (e+i)*3;
        }
    }

    int** matrixC = multplicar(matrixA, matrixB);

    int*** matrix3d = new int** [3];
    *(matrix3d) = matrixA;
    *(matrix3d+1) = matrixB;
    *(matrix3d+2) = matrixC;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout << *(*(*(matrix3d+i)+j)+k) << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }


    // for(int i=0;i<3;i++){
    //     for(int e=0;e<3;e++){
    //         cout << *(*(matrixA+i)+e) << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for(int i=0;i<3;i++){
    //     for(int e=0;e<3;e++){
    //         cout << *(*(matrixB+i)+e) << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for(int i=0;i<3;i++){
    //     for(int e=0;e<3;e++){
    //         cout << *(*(matrixC+i)+e) << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}