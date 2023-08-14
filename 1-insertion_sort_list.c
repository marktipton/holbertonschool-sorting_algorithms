#include "sort.h"
#include "swap.c"
void swap_list(listint_t *a, listint_t *b);

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 *
 * @list: doubly linked list of integers
 *
 */
void insertion_sort_list(listint_t **list) 
{
	listint_t *current = *list;
	bool swapped = true;
	
	while (swapped) 
	{
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_list(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
	}
}

void swap_list(listint_t *a, listint_t *b) 
{
	listint_t *temp_prev;
	listint_t *temp_next;
	
	temp_prev = a->prev;
	a->prev = b->prev;
	b->prev = temp_prev;

	temp_next = a->next;
	a->next = b->next;
	b->next = temp_next;
}
