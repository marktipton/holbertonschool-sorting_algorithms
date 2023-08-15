#include "sort.h"
#include "swap.c"
/**
 * insert_to_sorted - inserts a node in ascending order
 *
 * @head: first node in sorted list
 * @new_node: node to be inserted in list
 * Return: pointer to newly inserted node
 */
listint_t *insert_to_sorted(listint_t **head, listint_t *ins_node)
{
        listint_t *current = ins_node;
	listint_t *back = current->prev;

	back->next = current->next;
	if (current->next != NULL)
		current->next->prev = back;

	current->next = back;
	current->prev = back->prev;
	back->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*head = current;
	return (current);
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 *
 * @list: doubly linked list of integers
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	while (current != NULL)
	{
		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				current = insert_to_sorted(list, current);
				print_list(*list);
			}
			current = current->next;
		}
	}
}
