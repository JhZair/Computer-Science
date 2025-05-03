#include <iostream>
using namespace std;

int main(){
    int* arr= new int[100];
    delete arr;
    for(int i=0;i<100;i++)
        cout << *(arr+i) << " ";
    cout << "\n";
        return 0; 
}