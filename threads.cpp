#include <iostream>
#include <thread>

//using namespace std;

void F1(char c, int n)
{
    for ( int i = 0; i < n; i++ )
        std::cout<<c;
}

int main()
{
    std::thread t(F1,'c',50);// parametros: puntero a función, y parámetros de esta
    
    t.join();
    
    std::cout<<"\n";
}
