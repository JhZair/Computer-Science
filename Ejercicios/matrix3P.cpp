#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class CMatrix3P
{
public:
    CMatrix3P(int _dx, int _dy, int _dz);
    ~CMatrix3P();
    int get(int x, int y, int z);
    void set(int x, int y, int z, int v);
    int& gs(int x, int y, int z);
    int& operator()(int x, int y, int z);
    void print();
private:
    int*** m;
    int dy, dx, dz;
};

CMatrix3P::CMatrix3P(int _dx, int _dy, int _dz)
{
    dy = _dy; dx = _dx;
    m = new int*[dy];
    for ( int i = 0; i < dy; ++i )
        m[i] = new int[dx];
}

CMatrix3P::~CMatrix3P()
{
    for ( int i = 0; i < dy; ++i ){
        for(int j = 0;j < dz;++j){
            delete m[i][j];
        }
        delete m[i]
    }
    delete m;
}

int CMatrix3P::get(int x, int y, int z)
{   return m[y][x][z]; }

void CMatrix3P::set(int x, int y, int z, int v)
{   m[y][x][z] = v;    }

int& CMatrix3P::gs(int x, int y, int z)
{   return m[y][x][z]; }

int& CMatrix3P::operator()(int x, int y, int z)
{   //return m[y][x];
    return *(*(*(m+y)+x)+z);
}

void CMatrix3P::print()
{
    for ( int j = 0; j < dy; ++j ){
        for ( int i = 0; i < dx; ++i ){
            for(int e=0;e<dz;++e){
                cout<<m[j][i][e] <<" ";
                cout<<"\n";
            }
            cout<<"\n";
        }
    }
    cout<<"--------\n";
}

int main()
{
    CMatrix3P m(4,3,2);
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
