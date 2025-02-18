#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle.
 * @list: Pointer to the head of the list.
 *
 * Return: 1 if there is a cycle, 0 otherwise.
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list, *fast = list;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       /* Move slow pointer one step */
        fast = fast->next->next; /* Move fast pointer two steps */

        if (slow == fast) /* If they meet, there's a cycle */
            return (1);
    }

    return (0); /* No cycle found */
}
