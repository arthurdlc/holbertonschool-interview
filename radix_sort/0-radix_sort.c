#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Get the maximum number in the array
 * @array: The array
 * @size: Size of the array
 * Return: The max number
 */
int get_max(int *array, size_t size)
{
size_t i;
int max = array[0];

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
 * counting_sort_digit - A stable counting sort based on a digit place
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The exponent (1, 10, 100...) to get the current digit
 */
void counting_sort_digit(int *array, size_t size, int exp)
{
int *output = malloc(sizeof(int) * size);
int count[10] = {0}; /* count est une liste de */
/* 10 element [0,0,0,0,0,0,0,0,0,0]*/
size_t i;

if (!output) /* verifier qu'ill y a bien eu une allocation avec malloc*/
return;

/* Store count of occurrences of digits */
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++; /* foutre les premiere digits dans*/
/* la liste a la place des 0
[9, 5, 6, 0, 1, 4, 0, 2, 0, 1] */

/* Change count[i] so that count[i] contains the actual
* position of this digit in output[]
*/
for (i = 1; i < 10; i++)
count[i] += count[i - 1];/* tri les element de la liste count dans */
/* l'ordre croissant 
[0, 0, 0, 1, 1, 2, 4, 5, 6, 9]*/

/* Build the output array (go backward for stability) */
for (i = size; i-- > 0;)
{
/* on fou les elements de count dans l'output (malloc)*/
int digit = (array[i] / exp) % 10;
output[count[digit] - 1] = array[i];
count[digit]--;
}

/* Copy output[] to array[] */
for (i = 0; i < size; i++) /*obn prends le malloc et on le met dans l'array*/
array[i] = output[i];

print_array(array, size);
free(output);
}

/**
 * radix_sort - Sort an array using LSD Radix Sort
 * @array: The array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size) 
/* dans ce void on vas repeter la fonction precedente autant 
de fois qu'il y a de "colonnes" en gros 2 fois si c'est un nombre a 2 chiffre*/
{
int max, exp;

if (!array || size < 2)
return;

max = get_max(array, size);

for (exp = 1; max / exp > 0; exp *= 10)
counting_sort_digit(array, size, exp);
}
