#include "sort.h"
#include <stdlib.h>

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: The left node
 * @right: The right node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev)
        left->prev->next = right;
    else
        *list = right;

    if (right->next)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;

    right->next = left;
    left->prev = right;

    print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion Sort
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        temp = current;
        current = current->next;

        while (temp->prev && temp->n < temp->prev->n)
            swap_nodes(list, temp->prev, temp);
    }
}
