#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 60

int main(void)
{
srand(time(NULL)); // initialize the random number generator with the current time
    
char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator
    
for (int i = 0; i < PASSWORD_LENGTH; i++) {
    int rand_num = rand() % 94 + 33; // generate a random number between 33 and 126
        
    password[i] = (char)rand_num; // convert the random number to a character
}
    
password[PASSWORD_LENGTH] = '\0'; // add the null terminator
    
printf("%s\n", password); // print the password followed by a newline character
printf("Tada! Congrats\n"); // print the success message
    
return 0;
}

