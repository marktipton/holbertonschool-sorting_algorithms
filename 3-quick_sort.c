#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "swap.c"
/**
 * swap_array - swaps array of integers hmmm
 * @array: array
 * @a: el 2
 * @b: el 1
 */
void swap_array(int *array, ssize_t a, ssize_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
/**
 * lomuto_partition - makes last element the pivot element
 *
 * @array: array of integers
 * @low: smaller element
 * @high: larger element
 * @size: size of array
 * Return: partition index
 */
int lomuto_partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;
	int temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			swap_array(array, low, high);
			print_array(array, size);
			i++;
		}
	}
	temp = array[i + 1];
	array[high] = temp;
	return (i + 1);
}
/**
 * quick_sort_help - allows recursive call with three arguments
 *
 * @array: array of integers
 * @low: smaller element
 * @high: larger element
 * @size: size of array
 */
void quick_sort_help(int array[], int low, int high, size_t size)
{
	int pi; /*partition index*/
	int sorted, i;

	for (i = low; i < high; i++)
	{
		if (array[i] > array[i + 1])
		{
			sorted = 0;
			break;
		}
	}
	if (sorted)
		return;
	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_help(array, low, pi - 1, size);
		quick_sort_help(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - sorts array of integers into ascending order
 *
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_help(array, 0, size - 1, size);
}
