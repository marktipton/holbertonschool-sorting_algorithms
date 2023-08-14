#include "sort.h"

/**
 * swap - swaps elements of list
 *
 * @el_1: pointer to one element
 * @el_2: pointer to another element
 */
void swap(int *el_1, int *el_2)
{
	int temp = *el_1;
	*el_1 = *el_2;
	*el_2 = temp;
}

/**
 * bubble_sort - sorts an array of intergers in ascending order
 *
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		print_array(array, size);
		if (swapped == false)
			break;
	}
}
