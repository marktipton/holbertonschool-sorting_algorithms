#include "sort.h"
#include "swap.c"
/**
 * insert_to_sorted - inserts a node in ascending order
 *
 * @head: first node in sorted list
 * @ins_node: node to be inserted in list
 * Return: pointer to newly inserted node
 */
listint_t *insert_to_sorted(listint_t **head, listint_t *ins_node)
{
	listint_t *current = ins_node;
	listint_t *prev_n = current->prev;

	if (prev_n != NULL)
	{
		prev_n->next = current->next;
		if (current->next != NULL)
			current->next->prev = prev_n;

		current->next = prev_n;
		current->prev = prev_n->prev;
		prev_n->prev = current;

		if (current->prev != NULL)
			current->prev->next = current;
		else
			*head = current;
	}
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
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		while (temp->prev && temp->prev->n > temp->n)
		{
			temp = insert_to_sorted(list, current);
			print_list(*list);
		}
		current = current->next;
	}
}
