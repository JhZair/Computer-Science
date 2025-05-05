#include <iostream>
using namespace std;

// con temaplates:

template <class T>
class matrixL{
    private:
    int dx, dy;
    T* vec;
    
    public:
    matrixL(int _dx,int _dy){
        dx = _dx, dy = _dy;
        vec = new T[dx * dy];
    }
    ~matrixL(){
        delete[] vec;
    }
    const int get(int x, int y){
        return *(vec + x * dy + y);
    }
    void set(int x, int y, T v){
        *(vec + x * dy + y) = v;
    }
    T& gs(int x, int y){
        return *(vec + x * dy + y);
    }
    T& operator()(int x, int y){
        return *(vec + x * dy + y);
    }
};


int main(){
    matrixL<char> m(6,3);
    int t{65};
    for(int i=0;i<6;i++){            
        for(int j=0;j<3;j++){            
            m(i,j) = (char)t++;
        }
    }
    for(int i=0;i<6;i++){            
        for(int j=0;j<3;j++){              
            cout << m(i,j) << ' ';
        }
        cout << '\n';
    }
    return 0;
}


//sin templates
// class matrixL{
//     private:
//     int dx, dy;
//     int* vec;
    
//     public:
//     matrixL(int _dx,int _dy){
//         dx = _dx, dy = _dy;
//         vec = new int[dx * dy];
//     }
//     ~matrixL(){
//         delete[] vec;
//     }
//     const int get(int x, int y){
//         return *(vec + x * dy + y);
//     }
//     void set(int x, int y, int v){
//         *(vec + x * dy + y) = v;
//     }
//     int& gs(int x, int y){
//         return *(vec + x * dy + y);
//     }
//     int& operator()(int x, int y){
//         return *(vec + x * dy + y);
//     }
// };