#include "regex.h"

/**
 * regex_match - checks if a string matches a regex pattern
 * @str: the string to scan
 * @pattern: the regex pattern
 *
 * Return: 1 if matches, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
    if (!pattern || !str)
        return (0);

    /* Si le pattern est vide, vrai seulement si str est aussi vide */
    if (*pattern == '\0')
        return (*str == '\0');

    /* Vérifie si le premier caractère correspond */
    int first_match = (*str != '\0' &&
        (*pattern == *str || *pattern == '.'));

    /* Cas avec '*' après le premier caractère */
    if (*(pattern + 1) == '*')
    {
        return (regex_match(str, pattern + 2) ||
               (first_match && regex_match(str + 1, pattern)));
    }
    else
    {
        return (first_match && regex_match(str + 1, pattern + 1));
    }
}
