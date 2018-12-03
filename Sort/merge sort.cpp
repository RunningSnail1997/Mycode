#include<iostream>
using namespace std;

void Merge(int* a, int l, int m, int r);
void MergeSort(int* a, int l, int r);



int main(void) {
	cout << "merge sort" << endl;
	int a[8] = { 46,30,82,90,56,17,95,15 };
	cout << "original array:\t" ;
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "sorted array:\t";
	MergeSort(a,0,7);
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	getchar();
}


void Merge(int* a , int l,int m,int r) {
	int l1 = l;
	int m1 = m;
	int r1 = r;
	int num = r - l + 1;
	int k = 0;
	int* temp = new int[num];
	while (l1 < m && m1 <= r) {
		if (a[l1] < a[m1]) {
			temp[k++] = a[l1++];
		}
		else {
			temp[k++] = a[m1++];
		}
	}
	while (m1 <= r) {
		temp[k++] = a[m1++];
	}
	while (l1 < m) {
		temp[k++] = a[l1++];
	}
	for (int n = 0; n < num; n++) {
		a[l+n] = temp[n];
	}
}


void MergeSort(int* a, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m + 1, r);
	}
}





