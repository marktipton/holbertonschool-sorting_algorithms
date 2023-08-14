#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 *
 * @list: doubly linked list of integers
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *temp;
	listint_t *sort_node = NULL;

	while (current != NULL)
	{
		temp = current->next;

		while (sort_node != NULL && sort_node->n > current->n)
		{
			sort_node->prev->next = current;
			current->next = sort_node;
			sort_node = current;
			current = temp;
			print_list(*list);
		}
		if (sort_node == NULL)
			sort_node = current;
		else
		{
			current->prev->next = temp;
			temp->prev = current->prev;
			current->prev = sort_node;
			sort_node->next = current;
		}

		current = temp;
	}
	*list = sort_node;
}
