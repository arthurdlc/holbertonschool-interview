#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * struct word_count - structure to hold word and its count
 * @word: the word
 * @count: number of times it appears
 */
typedef struct word_count
{
    char const *word;
    int count;
} word_count;

/**
 * find_word_index - find index of word in table
 */
static int find_word_index(word_count *table, int size, char const *word, int wlen)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (strncmp(table[i].word, word, wlen) == 0 && table[i].word[wlen] == '\0')
            return i;
    }
    return -1;
}

/**
 * find_substring - finds all starting indices of substring(s)
 * @s: the string to scan
 * @words: array of words
 * @nb_words: number of words
 * @n: output param to store number of indices found
 *
 * Return: array of indices (malloc'd), or NULL if none
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int slen, wlen, total_len, i, j, idx, *res, res_size = 0;
    word_count *dict;

    *n = 0;
    if (!s || !words || nb_words == 0)
        return NULL;

    slen = strlen(s);
    wlen = strlen(words[0]);
    total_len = wlen * nb_words;
    if (slen < total_len)
        return NULL;

    /* build dictionary */
    dict = malloc(sizeof(word_count) * nb_words);
    if (!dict)
        return NULL;

    for (i = 0; i < nb_words; i++)
    {
        idx = find_word_index(dict, i, words[i], wlen);
        if (idx >= 0)
            dict[idx].count++;
        else
        {
            dict[i].word = words[i];
            dict[i].count = 1;
        }
    }

    /* allocate result array (max possible = slen) */
    res = malloc(sizeof(int) * slen);
    if (!res)
    {
        free(dict);
        return NULL;
    }

    for (i = 0; i <= slen - total_len; i++)
    {
        word_count *tmp = malloc(sizeof(word_count) * nb_words);
        if (!tmp)
        {
            free(dict);
            free(res);
            return NULL;
        }
        memcpy(tmp, dict, sizeof(word_count) * nb_words);

        int words_used = 0;
        for (j = 0; j < nb_words; j++)
        {
            char const *sub = s + i + j * wlen;
            idx = find_word_index(tmp, nb_words, sub, wlen);
            if (idx == -1 || tmp[idx].count == 0)
                break;
            tmp[idx].count--;
            words_used++;
        }
        free(tmp);

        if (words_used == nb_words)
            res[res_size++] = i;
    }

    free(dict);

    if (res_size == 0)
    {
        free(res);
        return NULL;
    }

    *n = res_size;
    return res;
}
