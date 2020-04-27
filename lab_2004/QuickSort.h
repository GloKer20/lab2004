#pragma once

void QuickSort(int *array, int left, int right)
{
	int pivot;
	int first = left;
	int last = right;
	pivot = array[left];
	while (left < right)
	{
		while ((array[right] >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			array[left] = array[right];
			left++;
		}
		while ((array[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			array[right] = array[left];
			right--;
		}
	}
	array[left] = pivot;
	pivot = left;
	left = first;
	right = last;
	if (left < pivot)
		QuickSort(array, left, pivot - 1);
	if (right > pivot)
		QuickSort(array, pivot + 1, right);
}
static void QuickSortRecurse(int* array, int first, int last)
{
	int left = first;
	int right = last;
	int mid = array[(left + right) / 2];
	int temp;
	while (left < right)
	{
		while (array[left] < mid)
			left++;
		while (array[right] > mid)
			right--;
		if (left <= right)
		{
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	}
	if (first < right)
		QuickSortRecurse(array, first, right);
	if (left < last)
		QuickSortRecurse(array, left, last);
}