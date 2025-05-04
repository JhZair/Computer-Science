#include <iostream>
using namespace std;

int*** multplicar(int*** a, int*** b){
    int*** c = new int** [3];
    for(int i=0;i<3;i++){
        *(c+i) = new int*[3];
        for(int e = 0; e < 3;e++){
            *(*(c+i)+e) = new int[3];
            for(int k=0;k<3;k++){
                *(*(*(c+i)+e)+k) = 0;
            }
        }
    }
        
    for(int i=0;i<3;i++){
        for(int e=0;e<3;e++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    *(*(*(c+i)+e)+j) += *(*(*(a+i)+e)+k) * *(*(*(b+i)+k)+j);
                }
            }
        }
    }
    return c;
}

int main(){
    int*** matrixA = new int ** [3];
    for(int i=0;i<3;i++){
        *(matrixA+i) = new int*[3];
        for(int e = 0; e < 3;e++){
            *(*(matrixA+i)+e) = new int[3];
            for(int k=0;k<3;k++){
                *(*(*(matrixA+i)+e)+k) = k+i+e+2;
            }
        }
    }
    cout << "Matrix A:" << endl;

    for(int i=0;i<3;i++){
        for(int e = 0; e < 3;e++){
            for(int k=0;k<3;k++){
                cout << *(*(*(matrixA+i)+e)+k) << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';

    int*** matrixB = new int ** [3];
    for(int i=0;i<3;i++){
        *(matrixB+i) = new int*[3];
        for(int e = 0; e < 3;e++){
            *(*(matrixB+i)+e) = new int[3];
            for(int k=0;k<3;k++){
                *(*(*(matrixB+i)+e)+k) = k+i+e+4;
            }
        }
    }
    cout << "Matrix B:" << endl;

    for(int i=0;i<3;i++){
        for(int e = 0; e < 3;e++){
            for(int k=0;k<3;k++){
                cout << *(*(*(matrixB+i)+e)+k) << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';

    int*** matrixC = multplicar(matrixA, matrixB);

    cout << "Matrix A*B:" << endl;
    for(int i=0;i<3;i++){
        for(int e = 0; e < 3;e++){
            for(int k=0;k<3;k++){
                cout << *(*(*(matrixC+i)+e)+k) << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}

