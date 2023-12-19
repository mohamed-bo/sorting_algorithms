#include "sort.h"

/**
 *selection_sort - selection_sort algorithm
 *@array: array
 *@size: len of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, maxIndex;
	int temp;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		maxIndex = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[maxIndex])
				maxIndex = j;
		if (array[i] > array[maxIndex])
		{
			temp = array[i];
			array[i] = array[maxIndex];
			array[maxIndex] = temp;
			print_array(array, size);
		}
	}
}
