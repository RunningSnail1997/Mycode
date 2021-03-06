// quicksort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<fstream>
#include<iostream>
using namespace std;
void quicksort(int* s, int l, int r);
void Merge(int* a, int l, int m, int r);
void MergeSort(int* a, int l, int r);
void heap_sort_asc(int a[], int n);
void maxheap_down(int a[], int start, int end);
/*
void quickSort(int* s , int l, int r);
void Merge(int *a, int p, int q, int r);
void MergeSort(int *a, int l, int r);
int main()
{
	ifstream in_stream;
	ofstream out_stream1,out_stream2,outstream3;
	in_stream.open("input1-data.txt");
	int data[7];
	int i = 0;
	while (!in_stream.eof() ) {
		in_stream >> data[i];
		i++;
	}
	in_stream.close();
	int data2[7];
	for (int k = 0; k < 7; k++) {
		data2[k] = data[k];
	}
	quickSort(data, 0, 6);
	MergeSort(data2, 0, 6);
	out_stream1.open("output1-data.txt");
	out_stream2.open("output2-data.txt");
	for (int j = 0 ; j < 7 ; j++) {
		out_stream1 << data[j]  << " " ;
		out_stream2 << data2[j] << " ";
	}
	out_stream1.close();
	out_stream2.close();
    return 0;
}
void quicksort(int* a, int right, int left) {
	int flag = a[right];//以最右边元素为基准
	int i = right;
	int j = left;
	int mid;
	while (i < j) {
		while (i < j && flag > a[j]) {
			j++;
		}
		if (i < j) {
			mid = a[j];
			a[j] = a[i];
			a[i] = mid;
			
		}
		while (i < j && flag < a[j]) {
			i--;
		}
		if (i < j) {
			mid = a[i];
			a[i] = a[j];
			a[j] = mid;
		}
		
	}
}
void quickSort(int* s, int l, int r){
	if (l < r){
		int i = l;
		j = r;
		x = s[l];
		while (i < j){ //如果i<j
			while (i < j && s[j] >= x){
				j--;
			}
			if (i < j){
				s[i++] = s[j];
			}
			while (i < j && s[i] < x){
				i++;
			}
			if (i < j) {
				s[j--] = s[i];
			}
		}
		s[i] = x;
		quickSort(s,l,i-1);
		quickSort(s,i+1,r);
	}
}





void Merge(int* a, int p, int q, int r){
	int n1 = q-p+1;      
	int n2 = r-q;          
	int i, j, k;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	for (i = 0 ; i<n1; i++)
		L[i] = a[p + i];
	for (j = 0; j<n2; j++)
		R[j] = a[q + j + 1];
	L[n1] = 11111111;
	R[n2] = 11111111;
	for (i = 0, j = 0, k = p; k <= r; k++){
		if (L[i] <= R[j])
			a[k] = L[i++];
		else
			a[k] = R[j++];
	}
	delete[] L;
	delete[] R;
}

void MergeSort(int* a, int l, int r){
	if (l<r){
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m, r);
	}
}
*/

int main(void) {
	cout << "heap sort" << endl;
	int a[8] = { 46,30,82,90,56,17,95,15 };
	cout << "original array:\t" ;
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	//quicksort(a, 0, 78);
	cout << "sorted array:\t";
	MergeSort(a,0,7);
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	getchar();
}
/*
void quicksort(int* a, int right, int left) {
	int flag = a[right];//以最右边元素为基准
	int i = right;
	int j = left;
	int mid;
	while (i < j) {
		while (i < j && flag > a[j]) {
			j++;
		}
		if (i < j) {
			mid = a[j];
			a[j] = a[i];
			a[i] = mid;

		}
		while (i < j && flag < a[j]) {
			i--;
		}
		if (i < j) {
			mid = a[i];
			a[i] = a[j];
			a[j] = mid;
		}

	}
}

*/


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


void maxheap_down(int a[], int start, int end)
{
	int c = start;         
	int l = 2 * c + 1;      
	int tmp = a[c];            
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		if (l < end && a[l] < a[l + 1])
			l++;       
		if (tmp >= a[l])
			break;   
		else           
		{
			a[c] = a[l];
			a[l] = tmp;
		}
	}
}


void heap_sort_asc(int a[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		maxheap_down(a, i, n - 1);
	for (i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		maxheap_down(a, 0, i - 1);
	}
}