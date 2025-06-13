#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - merges two subarrays into the original array
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
size_t i = left, j = mid, k = left;

printf("Merging...\n[left]: ");
print_array(array + left, mid - left);
printf("[right]: ");
print_array(array + mid, right - mid);

while (i < mid && j < right)
buffer[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];
while (i < mid)
buffer[k++] = array[i++];
while (j < right)
buffer[k++] = array[j++];

for (i = left; i < right; i++)
array[i] = buffer[i];

printf("[Done]: ");
print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - recursive helper for top-down merge sort
 */
void merge_sort_recursive(int *array, int *buffer, size_t left, size_t right)
{
if (right - left < 2)
return;

size_t mid = left + (right - left) / 2;

merge_sort_recursive(array, buffer, left, mid);
merge_sort_recursive(array, buffer, mid, right);
merge(array, buffer, left, mid, right);
}

/**
 * merge_sort - sorts an array using top-down merge sort
 */
void merge_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

int *buffer = malloc(sizeof(int) * size);
if (!buffer)
return;

merge_sort_recursive(array, buffer, 0, size);
free(buffer);
}
