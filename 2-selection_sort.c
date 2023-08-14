#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sorts array of integers into ascending order
 *
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_idx;
 
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		if(min_idx != i)
			swap(&arr[min_idx], &arr[i]);
		print_array(array, size);
	}
}

