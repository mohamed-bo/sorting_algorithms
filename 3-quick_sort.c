#include "sort.h"

/**
 * swap - swap 2 case value without using temp
 * @array: arrray
 * @size: len
 * @a: first value
 * @b: second value
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * partition - partition
 * @array: arrray
 * @size: len
 * @low: the low index
 * @high: the high index
 */

size_t partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j;
    int pivot = array[high];

	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quicksort - quicksorts real algorithm
 * @array: arrray
 * @size: len
 * @low: the low index
 * @high: the high index
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivotI = partition(array, size, low, high);
		quicksort(array, size, low, pivotI - 1);
		quicksort(array, size, pivotI + 1, high);
	}
}

/**
 * quick_sort - check and call quicksort
 * @array: arrray
 * @size: len
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
