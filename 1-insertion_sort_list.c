#include "sort.h"

/**
 * swapNodes - swaps two nodes
 * @node1: first node
 * @node2: second node
 */

void swapNodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
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
