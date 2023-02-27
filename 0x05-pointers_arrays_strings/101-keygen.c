#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

/**
 * main - entry point for program
 *
 * Return: 0 on success
 */
int main(void)
{
char password[PASSWORD_LENGTH + 1];
const char *valid_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int i;

srand(time(NULL)); /* Seed the random number generator */

/* Generate a random password */
for (i = 0; i < PASSWORD_LENGTH; i++)
{
        password[i] = valid_chars[rand() % 36];
}

password[i] = '\0'; /* Add null terminator to end of password */

printf("Random password: %s\n", password);

return 0;
}

