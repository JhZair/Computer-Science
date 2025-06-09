#include <iostream>


class CP
{
    public:
        virtual bool cmp(int a, int b) = 0;
};


class CLess : public CP
{    public:
    bool cmp(int a, int b)
    {    return a < b;    }
};

class CGreater : public CP
{    public:
    bool cmp(int a, int b)
    {    return a > b;    }
};

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n, CP* p)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ( p->cmp(arr[j], arr[j + 1]) )
                swap(arr[j], arr[j + 1]);
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 7;
    CLess l;
    CGreater g;
    CP* p = &l;
    
    bubbleSort(arr, n, p);
    print(arr,n);    
    p = &g;
    bubbleSort(arr, n, p);
    print(arr,n);
   
    return 0;
}
