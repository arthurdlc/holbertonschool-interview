#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the head of the list
 * Return: New head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    if (!head || !*head || !(*head)->next)
        return 1;

    listint_t *slow = *head, *fast = *head, *first_half, *second_half;

    /* Find the middle of the list */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half of the list */
    second_half = reverse_list(slow);
    first_half = *head;

    /* Compare first half and reversed second half */
    listint_t *temp = second_half;
    while (temp)
    {
        if (first_half->n != temp->n)
        {
            reverse_list(second_half); /* Restore the original list */
            return 0;
        }
        first_half = first_half->next;
        temp = temp->next;
    }

    /* Restore the original list before returning */
    reverse_list(second_half);
    return 1;
}
