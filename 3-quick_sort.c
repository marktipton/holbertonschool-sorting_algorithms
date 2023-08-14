#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "swap.c"
/**
 * quick_sort - sorts array of integers into ascending order
 *
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int pivot;
	size_t i = 0, j;

	if (array == NULL || size <= 1)
		return;
	print_array(array, size);
	pivot = array[size - 1];
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			i++;
			print_array(array, size);
		}
	}
	swap(&array[i], &array[size - 1]);
	quick_sort(array, i);
	quick_sort(array + i + 1, size - i - 1);
}
