#include "sort.h"

/**
 * swapNodes - swaps two nodes
 * @a: first node
 * @b: second node
 */

void swapNodes(listint_t *a, listint_t *b)
{
	listint_t *aPrev;
	listint_t *aNext;

	if (a == NULL || b == NULL)
		return;

	aPrev = a->prev;
	aNext = a->next;
	a->prev = b->prev;
	a->next = b->next;
	if (b->prev != NULL)
		b->prev->next = a;
	if (b->next != NULL)
		b->next->prev = a;
	b->prev = aPrev;
	b->next = aNext;
	if (aPrev != NULL)
		b->prev->next = b;
	if (aNext != NULL)
		b->next->prev = b;
}

/**
 * insertion_sort_list - insertion sorts algorithm
 * @list: head of list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *current;

	if (!list || !*list || !(*list)->next)
		return;
	iter = (*list)->next;
	while (iter)
	{
		current = iter;
		while (current && current->prev)
		{
			if (current->prev->n > current->n)
			{
				swapNodes(current->prev, current);
				if (!current->prev)
					*list = current;
				print_list((const listint_t *)*list);
			}
			else
				current = current->prev;
		}
		iter = iter->next;
	}
}
