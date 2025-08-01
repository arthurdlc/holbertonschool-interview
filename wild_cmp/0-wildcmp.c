#include "holberton.h"

/**
 * wildcmp - Compare two strings and allow for wildcard * in s2
 * @s1: First string
 * @s2: Second string, can contain wildcard *
 *
 * Return: 1 if considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
return 1;

if (*s2 == '*')
{
// Try skipping the '*', or using it to match one or more characters
return wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2));
}

if (*s1 == *s2)
return wildcmp(s1 + 1, s2 + 1);

return 0;
}
