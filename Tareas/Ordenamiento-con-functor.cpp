#include <iostream>
using namespace std;

template<typename T>
class iterador {
    T* x;
public:
    iterador(){
        x = nullptr;
    }
    iterador(T* ptr){
        x = ptr;
    }

    iterador& operator=(T* p){
        x = p;
        return *this;
    }
    iterador& operator=(T p){
        *x = p;
        return *this;
    }
    bool operator<(const iterador& other) const {
        return x < other.x;
    }
    bool operator!=(const iterador& other) const {
        return x != other.x;
    }
    iterador& operator++() {
        ++x;
        return *this;
    }
    T& operator*() const {
        return *x;
    }
    T* get() const {
        return x;
    }
    friend ostream& operator<<(ostream& output, const iterador& i) {
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
        quicksort(it(ini), it(fin-1));
    }

private:
    O orden;

    void quicksort(it ini, it fin){
        if (!(ini < fin)) return;

        T pivot = *fin;
        it i = ini;

        for (it j = ini;j<fin;++j){
            if (orden(*j, pivot)) {
                swap(*i, *j);
                ++i;
            }
        }
        swap(*i, *fin);

        quicksort(ini, iterador<T>(i.get()-1));
        quicksort(++i, fin);
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
