#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

constexpr int N = 1000000;

// Comparadores
bool less_than(int a, int b) { return a < b; }

class CMethod {
public:
    bool method(int a, int b) { return a < b; }
};

class CObjectInline {
public:
    inline bool operator()(int a, int b) const { return a < b; }
};

class CObjectNoInline {
public:
    bool operator()(int a, int b) const { return a < b; } // no inline
};

struct PolimorfismoBase {
    virtual bool comparar(int a, int b) const = 0;
    virtual ~PolimorfismoBase() = default;
};

class PolimorfismoDerivado : public PolimorfismoBase {
public:
    bool comparar(int a, int b) const override { return a < b; }
};

// QuickSort con puntero a funcion
void quickSortFunc(int* a, int low, int high, bool (*comp)(int, int)) {
    if (low >= high) return;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (comp(a[j], pivot)) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    quickSortFunc(a, low, i, comp);
    quickSortFunc(a, i + 2, high, comp);
}

// QuickSort con puntero a metodo de clase
void quickSortMethodPtr(int* a, int low, int high, bool (CMethod::*comp)(int, int), CMethod& obj) {
    if (low >= high) return;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if ((obj.*comp)(a[j], pivot)) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    quickSortMethodPtr(a, low, i, comp, obj);
    quickSortMethodPtr(a, i + 2, high, comp, obj);
}

void quickSortObjInline(int* a, int low, int high, const CObjectInline& comp) {
    if (low >= high) return;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (comp(a[j], pivot)) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    quickSortObjInline(a, low, i, comp);
    quickSortObjInline(a, i + 2, high, comp);
}

void quickSortObjNoInline(int* a, int low, int high, const CObjectNoInline& comp) {
    if (low >= high) return;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (comp(a[j], pivot)) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    quickSortObjNoInline(a, low, i, comp);
    quickSortObjNoInline(a, i + 2, high, comp);
}

void quickSortPolimorfismo(int* a, int low, int high, const PolimorfismoBase* comp) {
    if (low >= high) return;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (comp->comparar(a[j], pivot)) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    quickSortPolimorfismo(a, low, i, comp);
    quickSortPolimorfismo(a, i + 2, high, comp);
}

// Medicion
template <typename Func, typename... Args>
long long medirTiempo(Func f, Args&&... args) {
    auto inicio = chrono::high_resolution_clock::now();
    f(forward<Args>(args)...);
    auto fin = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(fin - inicio).count();
}

int main() {
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 1'000'000);

    vector<int> base(N);
    for (int& val : base) val = dist(rng);

    vector<int> tamanos = {10'000, 30'000, 50'000, 70'000, 90'000, 110'000, 200'000, 300'000, 400'000, 500'000, 700'000, 900'000, 1'000'000};
    vector<string> metodos = {"funcion", "metodo_ptr", "obj_inline", "obj_no_inline", "polimorfismo"};
    vector<vector<long long>> resultados(metodos.size(), vector<long long>(tamanos.size()));

    for (size_t i = 0; i < tamanos.size(); ++i) {
        int n = tamanos[i];
        vector<int> subarr(base.begin(), base.begin() + n);

        int* a1 = new int[n];
        int* a2 = new int[n];
        int* a3 = new int[n];
        int* a4 = new int[n];
        int* a5 = new int[n];

        copy(subarr.begin(), subarr.end(), a1);
        copy(subarr.begin(), subarr.end(), a2);
        copy(subarr.begin(), subarr.end(), a3);
        copy(subarr.begin(), subarr.end(), a4);
        copy(subarr.begin(), subarr.end(), a5);

        CMethod objMethod;
        CObjectInline objInline;
        CObjectNoInline objNoInline;
        PolimorfismoDerivado objPoli;

        resultados[0][i] = medirTiempo(quickSortFunc, a1, 0, n - 1, less_than);
        resultados[1][i] = medirTiempo(quickSortMethodPtr, a2, 0, n - 1, &CMethod::method, ref(objMethod));
        resultados[2][i] = medirTiempo(quickSortObjInline, a3, 0, n - 1, ref(objInline));
        resultados[3][i] = medirTiempo(quickSortObjNoInline, a4, 0, n - 1, ref(objNoInline));
        resultados[4][i] = medirTiempo(quickSortPolimorfismo, a5, 0, n - 1, &objPoli);

        cout << "Tamaño " << n << ":\n";
        for (size_t m = 0; m < metodos.size(); ++m) {
            cout << "  Tiempo (" << metodos[m] << "): " << resultados[m][i] << " ms\n";
        }

        delete[] a1;
        delete[] a2;
        delete[] a3;
        delete[] a4;
        delete[] a5;
    }

    ofstream archivo("resultados.csv");
    archivo << "tamaño";
    for (const auto& m : metodos) archivo << "," << m;
    archivo << "\n";

    for (size_t i = 0; i < tamanos.size(); ++i) {
        archivo << tamanos[i];
        for (size_t m = 0; m < metodos.size(); ++m) {
            archivo << "," << resultados[m][i];
        }
        archivo << "\n";
    }
    archivo.close();
    return 0;
}
