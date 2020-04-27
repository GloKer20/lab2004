#include <iostream>
#include <time.h>
#include <cstdio>
#include <chrono>
#include "BSearch.h"
#include "QuickSort.h"

using namespace std;

const int N = 10000;
const int n = 100;
int arr[N];

int Search(int value)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == value)
			return i;
	}
}

int main()
{
	clock_t start;
	double ns;
	srand(unsigned(time(0)));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 2000 - 1000;
	}

	int arr[n];
	srand(unsigned(time(0)));
	cout << "Random: ";
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 20 - 10;
		cout << arr[i] << " ";
	}
	cout << endl;
	QuickSort(arr, 0, n - 1);
	cout << "Sorted: ";
	for (int i = 0; i < 50; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Binary search of 7: " << BSearch(7, arr, 0, n - 1) << endl;

	start = clock();
	for (int i = 0; i < 1000000; i++)
		BSearch(2, arr, 0, n - 1);
	ns = ((clock() - start) / (double)CLOCKS_PER_SEC) / 1000;
	cout << "Time of search in sorted array: " << ns << " ns" << endl;

	start = clock();
	for (int i = 0; i < 1000000; i++)
		Search(555);
	ns = ((clock() - start) / (double)CLOCKS_PER_SEC) / 1000;
	cout << "Time of search in unsorted array: " << ns << " ns";
}