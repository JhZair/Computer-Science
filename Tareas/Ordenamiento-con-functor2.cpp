#include <iostream>
using namespace std;

template<typename T>
class iterador {
    T* x;
public:
    void operator=(T* p){
        x = p;
    }
    void operator=(T p){
        *x = p;
    }
    bool operator<(T* p){
        return x < p;
    }
    iterador operator++(){
        iterador a;
        a = ++x;
        return a;
    }
    friend ostream& operator<<(ostream& output, const iterador& i){
        output << *(i.x);
        return output;
    }
};

class ascendente {
public:
    template<typename T>
    bool operator()(T a, T b) const {
        return a < b;
    }
};

class descendente {
public:
    template<typename T>
    bool operator()(T a, T b) const {
        return a > b;
    }
};

template<class T, class O>
class ordena {
public:
    typedef iterador<T> it;

    void ordenar(T* ini, T* fin){
        quicksort(ini, fin - 1);
    }

private:
    O orden;

    void quicksort(T* ini, T* fin){
        if (ini >= fin) return;

        T* pivot = fin;
        T* i = ini-1;

        for (T* j = ini;j<fin;++j){
            if (orden(*j, *pivot)){
                ++i;
                swap(*i, *j);
            }
        }
        ++i;
        swap(*i, *fin);

        quicksort(ini, i-1);
        quicksort(i+1,fin);
    }
};

int main() {
    int arr[] = {5,2,9,1,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    ordena<int, ascendente> ordenasc;
    ordenasc.ordenar(arr, arr+n);

    iterador<int> it;
    for (it = arr;it<arr+n;++it){
        cout << it << " ";
    }
    cout<<endl;

    ordena<int, descendente> ordendesc;
    ordendesc.ordenar(arr, arr + n);

    for (it = arr;it<arr+n;++it){
        cout << it << " ";
    }
    cout<<endl;

    return 0;
}
