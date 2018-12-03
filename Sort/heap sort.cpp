#include<fstream>
#include<iostream>
using namespace std;

void heap_sort_asc(int a[], int n);
void maxheap_down(int a[], int start, int end);

int main(void) {
	cout << "heap sort" << endl;
	int a[8] = { 46,30,82,90,56,17,95,15};
	cout << "original array:\t" ;
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "sorted array:\t";
	heap_sort_asc(a,8);
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	getchar();
}

/*a为待排序数组，start为0，end为length(a)-1,改函数用于执行构建堆*/
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
 
/*a为待排序数组，n为length(a)-1*/
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

