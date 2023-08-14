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

