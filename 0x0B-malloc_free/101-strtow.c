#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 *
 * Return: The number of words in str
 */
static int count_words(char *str)
{
    int i, count = 0;

    for (i = 0; str[i]; ++i)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
            ++count;
    }

    return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str)
{
    char **words;
    int i, j, k, len, count;

    if (str == NULL || *str == '\0')
        return (NULL);

    count = count_words(str);

    words = malloc((count + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);

    for (i = 0, j = 0; j < count; ++i)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
        {
            len = 0;
            k = i;
            while (str[k] && str[k] != ' ')
                ++len, ++k;

            words[j] = malloc((len + 1) * sizeof(char));
            if (words[j] == NULL)
            {
                while (--j >= 0)
                    free(words[j]);
                free(words);
                return (NULL);
            }

            strncpy(words[j], &str[i], len);
            words[j][len] = '\0';
            ++j;
        }
    }

    words[count] = NULL;

    return (words);
}

