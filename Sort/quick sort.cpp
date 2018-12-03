#include<iostream>
using namespace std;
void quicksort(int* s, int l, int r);
void Merge(int* a, int l, int m, int r);
void MergeSort(int* a, int l, int r);
void heap_sort_asc(int a[], int n);
void maxheap_down(int a[], int start, int end);

int main(void) {
	cout << "quick sort" << endl;
	int a[8] = { 46,30,82,90,56,17,95,15 };
	cout << "original array:\t" ;
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "sorted array:\t";
	quicksort(a,0,7);
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	getchar();
}


void quicksort(int* s, int l, int r) {
	if (l < r) {
		int i = l;
		int j = r;
		int x = s[l];
		while (i < j) { 
			while (s[j] >= x) {
				j--;
			}
			if (i < j) {
				s[i] = s[j];
			}
			while (i < j && s[i] < x) {
				i++;
			}
			if (i < j) {
				s[j] = s[i];
			}
		}
		s[i] = x;
		quicksort(s, l, i - 1);
		quicksort(s, i + 1, r);
	}
}



