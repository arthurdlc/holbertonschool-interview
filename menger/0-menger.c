#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_hole - Vérifie si une position donnée doit être un "trou"
 * @row: La ligne actuelle
 * @col: La colonne actuelle
 *
 * Return: 1 si c'est un trou, 0 sinon
 */
int is_hole(int row, int col)
{
    while (row > 0 || col > 0)
    {
        if (row % 3 == 1 && col % 3 == 1)
            return (1);
        row /= 3;
        col /= 3;
    }
    return (0);
}

/**
 * menger - Dessine une éponge de Menger de niveau donné
 * @level: Niveau de l'éponge de Menger à dessiner
 */
void menger(int level)
{
    int size, row, col;

    if (level < 0)
        return;

    size = pow(3, level);

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (is_hole(row, col))
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
