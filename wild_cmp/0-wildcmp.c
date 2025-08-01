#include "holberton.h"

int wildcmp(char *s1, char *s2)
{
    // If both strings reach the end, return 1 (they are identical)
    if (*s1 == '\0' && *s2 == '\0')
        return 1;

    // If s2 is empty but s1 is not, return 0 (they can't match)
    if (*s1 == '\0' && *s2 == '*')
        return wildcmp(s1, s2 + 1); // Skip the '*' in s2 and continue

    // If s2 starts with '*' (wildcard) we have two options:
    if (*s2 == '*')
    {
        // Try skipping '*' in s2 or matching s1 to s2 after skipping '*'
        return wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2));
    }

    // If current characters match, move to the next characters
    if (*s1 == *s2)
        return wildcmp(s1 + 1, s2 + 1);

    // If the characters don't match, return 0
    return 0;
}
