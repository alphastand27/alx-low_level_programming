#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 60

int main(void)
{
    srand(time(NULL)); // initialize the random number generator with the current time
    
    char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator
    
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int rand_num = rand() % 62; // generate a random number between 0 and 61
        
        if (rand_num < 26) { // if it's between 0 and 25, add a lowercase letter
            password[i] = 'a' + rand_num;
        } else if (rand_num < 52) { // if it's between 26 and 51, add an uppercase letter
            password[i] = 'A' + rand_num - 26;
        } else { // if it's between 52 and 61, add a digit
            password[i] = '0' + rand_num - 52;
        }
    }
    
    password[PASSWORD_LENGTH] = '\0'; // add the null terminator
    
    printf("%s", password); // print the password
    
    return 0;
}

