#include <iostream>
using namespace std;



void swap(int * p, int * q){
	int * t = p;
	*p = *q;
	*q = *t;
}
	
void merge(int * p, int * q){
	int * f = p + (q-p)*2;
	while( p<q && q<f){
	if (*p < *q){
		p++;
	}
	else{
		for(int * r=p;r<q;r++){
			swap(*r,*q);
			q++;
			p++;
		}
	  }
	}
}

int main() {
	int arr[] = {3,7,9,2,4,8};
	int * p = arr;
	int * q = arr + 3;
	
	for(int e = 0; e < 6; e++){
		cout << *(arr + e) << ' ';
	}
	cout << "\n";
	merge(p ,q);
	cout << "\n";
	
	for(int e = 0; e < 6; e++){
		cout << *(arr + e) << ' ';
	}
	
	return 0;
}

