#pragma once

int BSearch(int value, int array[], int left, int right)
{
	int mid = 0;
	while (1)
	{
		mid = (left + right) / 2;

		if (value < array[mid])
			right = mid - 1;
		else if (value > array[mid])
			left = mid + 1;
		else
			return mid;
		if (left > right)
			return -1;
	}
}

int BSearchRecursion(int value, int array[], int left, int right)
{
	if (right < left)
		return -1;
	int mid = (left + right) / 2;
	if (array[mid] > value)
		return BSearchRecursion(value, array, left, mid - 1);
	if (array[mid] < value)
		return BSearchRecursion(value, array, mid + 1, right);
	if (array[mid] == value)
		return mid;
	return -1;
}