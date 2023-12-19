#include "sort.h"

/**
 *bubble_sort - buble sort algorithm
 *@array: array
 *@size: len of array
 */

void bubble_sort(int *array, size_t size)
{
	int t;
	size_t i, j;

	if (!array || !size)
		return;
	i = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i -1; j++)
		{
			if (array[j] > array[j + 1])
			{
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
				print_array(array, size);
			}
		}
	}
}
