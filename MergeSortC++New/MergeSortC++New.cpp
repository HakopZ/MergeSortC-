// MergeSortC++New.cpp : Defines the entry point for the console application.
// MergeSort(TORTURE).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


static void Merge(int thing[], int l, int m, int r)
{

	int n1 = m - l + 1;
	int n2 = r - m;
	int *left = new int[n1]; //remember to delete
	int *right = new int[n2]; //remember to delete
							  //int thingIndex = 0;

	for (int i = 0; i < n1; i++)
	{
		left[i] = thing[l + i];
	}
	for (int i = 0; i < n2; i++)
	{
		right[i] = thing[m + 1 + i];
	}
	int a = 0;
	int b = 0;
	int c = l;
	while (a < n1 && b < n2)
	{
		if (left[a] <= right[b])
		{
			thing[c] = left[a];
			a++;
		}
		else
		{
			thing[c] = right[b];
			b++;
		}
		c++;
	}


	while (a < n1)
	{
		thing[c] = left[a];
		a++;
		c++;
	}


	while (b < n2)
	{
		thing[c] = right[b];
		b++;
		c++;
	}
	delete left;
	delete right;
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
void MergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		MergeSort(arr, left, middle);
		MergeSort(arr, middle + 1, right);

		Merge(arr, left, middle, right);
	}
}

int main()
{
	int a[] = { 2, 4, 6, 5, 1, 7 };
	int arr_size = sizeof(a) / sizeof(a[0]);
	printArray(a, arr_size);
	MergeSort(a, 0, arr_size - 1);
	printArray(a, arr_size);
	system("pause");
	return 0;
}


