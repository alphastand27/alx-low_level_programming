#include "main.h"
#include <stdlib.h>

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: Pointer to an array of strings (words)
 *         or NULL if str == NULL or str == ""
 */
char **strtow(char *str)
{
char **words;
int i, j, k, len, wc;

if (str == NULL || *str == '\0')
        return (NULL);

wc = 0;
len = 0;
while (str[len])
{
        if ((str[len] != ' ' && str[len] != '\t') &&
              (str[len + 1] == ' ' || str[len + 1] == '\t' ||
              str[len + 1] == '\n' || str[len + 1] == '\0'))
                wc++;
        len++;
}

words = malloc(sizeof(char *) * (wc + 1));
if (words == NULL)
        return (NULL);

i = 0;
while (*str)
{
        if (*str != ' ' && *str != '\t' && *str != '\n')
        {
                j = 0;
                while (str[j] != ' ' && str[j] != '\t' &&
                        str[j] != '\n' && str[j] != '\0')
                        j++;

                words[i] = malloc(sizeof(char) * (j + 1));
                if (words[i] == NULL)
                {
                        while (i-- >= 0)
                                free(words[i]);
                        free(words);
                        return (NULL);
                }

                for (k = 0; k < j; k++)
                        words[i][k] = *str++;

                words[i][k] = '\0';
                i++;
        }
        else
                str++;
}
words[i] = NULL;
return (words);
}

