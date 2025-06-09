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

// QuickSort
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

void quickSortMethod(int* a, int low, int high, CMethod& obj) {
    if (low >= high) return;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (obj.method(a[j], pivot)) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    quickSortMethod(a, low, i, obj);
    quickSortMethod(a, i + 2, high, obj);
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


// Medición
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

    int* a1 = new int[N];
    int* a2 = new int[N];
    int* a3 = new int[N];
    int* a4 = new int[N];
    int* a5 = new int[N];

    copy(base.begin(), base.end(), a1);
    copy(base.begin(), base.end(), a2);
    copy(base.begin(), base.end(), a3);
    copy(base.begin(), base.end(), a4);
    copy(base.begin(), base.end(), a5);

    CMethod objMethod;
    CObjectInline objInline;
    CObjectNoInline objNoInline;
    PolimorfismoDerivado objPoli;

    cout << "Tiempo (puntero a funcion): "
         << medirTiempo(quickSortFunc, a1, 0, N - 1, less_than) << " ms\n";
    cout << "Tiempo (metodo de objeto): "
         << medirTiempo(quickSortMethod, a2, 0, N - 1, ref(objMethod)) << " ms\n";
    cout << "Tiempo (objeto inline): "
         << medirTiempo(quickSortObjInline, a3, 0, N - 1, ref(objInline)) << " ms\n";
    cout << "Tiempo (objeto no-inline): "
         << medirTiempo(quickSortObjNoInline, a4, 0, N - 1, ref(objNoInline)) << " ms\n";
    cout << "Tiempo (polimorfismo): "
         << medirTiempo(quickSortPolimorfismo, a5, 0, N - 1, &objPoli) << " ms\n";

    ofstream archivo("resultados.csv");
    archivo << "tamaño,metodo,tiempo_ms\n";

    vector<int> tamaños = {10'000, 30'000, 50'000, 70'000, 90'000, 110'000, 200'000, 300'000, 400'000, 500'000, 700'000, 900'000, 1'000'000};

    for (int n : tamaños) {
        vector<int> base(n);
        for (int& val : base) val = dist(rng);

        int* a1 = new int[n];
        int* a2 = new int[n];
        int* a3 = new int[n];
        int* a4 = new int[n];
        int* a5 = new int[n];

        copy(base.begin(), base.end(), a1);
        copy(base.begin(), base.end(), a2);
        copy(base.begin(), base.end(), a3);
        copy(base.begin(), base.end(), a4);
        copy(base.begin(), base.end(), a5);

        CMethod objMethod;
        CObjectInline objInline;
        CObjectNoInline objNoInline;
        PolimorfismoDerivado objPoli;

        archivo << n << ",funcion," << medirTiempo(quickSortFunc, a1, 0, n - 1, less_than) << "\n";
        archivo << n << ",metodo," << medirTiempo(quickSortMethod, a2, 0, n - 1, ref(objMethod)) << "\n";
        archivo << n << ",obj_inline," << medirTiempo(quickSortObjInline, a3, 0, n - 1, ref(objInline)) << "\n";
        archivo << n << ",obj_no_inline," << medirTiempo(quickSortObjNoInline, a4, 0, n - 1, ref(objNoInline)) << "\n";
        archivo << n << ",polimorfismo," << medirTiempo(quickSortPolimorfismo, a5, 0, n - 1, &objPoli) << "\n";

        delete[] a1;
        delete[] a2;
        delete[] a3;
        delete[] a4;
        delete[] a5;
    }

    archivo.close();
    return 0;
}
