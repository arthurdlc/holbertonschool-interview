#include "slide_line.h"
#include <stddef.h>

/**
 * slide_line - Slide et fusionne une ligne d'entiers selon les règles du jeu 2048
 * @line: tableau d'entiers
 * @size: taille du tableau
 * @direction: direction du slide (SLIDE_LEFT ou SLIDE_RIGHT)
 *
 * Return: 1 en cas de succès, 0 en cas d'échec
 */
int slide_line(int *line, size_t size, int direction)
{
    int i, idx, last_merged;
    int temp[(int)size];

    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    /* Initialiser le tableau temporaire à zéro */
    for (i = 0; i < (int)size; i++)
        temp[i] = 0;

    if (direction == SLIDE_LEFT)
    {
        idx = 0;
        last_merged = -1;
        for (i = 0; i < (int)size; i++)
        {
            if (line[i] == 0)
                continue;
            if (idx > 0 && temp[idx - 1] == line[i] && last_merged != idx - 1)
            {
                temp[idx - 1] *= 2;
                last_merged = idx - 1;
            }
            else
            {
                temp[idx] = line[i];
                idx++;
            }
        }
    }
    else /* SLIDE_RIGHT */
    {
        idx = (int)size - 1;
        last_merged = -1;
        for (i = (int)size - 1; i >= 0; i--)
        {
            if (line[i] == 0)
                continue;
            if (idx < (int)size - 1 && temp[idx + 1] == line[i] && last_merged != idx + 1)
            {
                temp[idx + 1] *= 2;
                last_merged = idx + 1;
            }
            else
            {
                temp[idx] = line[i];
                idx--;
            }
        }
    }

    /* Recopier le résultat dans le tableau original */
    for (i = 0; i < (int)size; i++)
        line[i] = temp[i];

    return (1);
}
