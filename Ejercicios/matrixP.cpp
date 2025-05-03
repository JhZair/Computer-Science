#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class CMatrixP
{
public:
    CMatrixP(int _dx, int _dy);
    ~CMatrixP();
    int get(int x, int y);
    void set(int x, int y, int v);
    int& gs(int x, int y);
    int& operator()(int x, int y);
    void print();
private:
    int** m;
    int dy, dx;
};

CMatrixP::CMatrixP(int _dx, int _dy)
{
    dy = _dy; dx = _dx;
    m = new int*[dy];
    for ( int i = 0; i < dy; ++i )
        m[i] = new int[dx];
}

CMatrixP::~CMatrixP()
{
    for ( int i = 0; i < dy; ++i )
        delete m[i];
    delete m;
}

int CMatrixP::get(int x, int y)
{   return m[y][x]; }

void CMatrixP::set(int x, int y, int v)
{   m[y][x] = v;    }

int& CMatrixP::gs(int x, int y)
{   return m[y][x]; }

int& CMatrixP::operator()(int x, int y)
{   //return m[y][x];
    return *(*(m+y)+x);
}

void CMatrixP::print()
{
    for ( int j = 0; j < dy; ++j )
    {
        for ( int i = 0; i < dx; ++i )
            cout<<m[j][i] <<" ";
        cout<<"\n";
    }
    cout<<"--------\n";
}

int main()
{
    CMatrixP m(4,3);
    m.print();
    m.set(2,2, 5); m.set(1,1, 2); m.set(1,2, 7);
    m.set(2,1, m.get(2,2));
    m.print();
    m.gs(3,0) = 7;
    m.gs(3,1) = m.gs(3,0);
    m.print();
    m(0,0) = 4;
    m(5,8) = m(0,2) = m.operator()(3,1);
    m.print();
}
