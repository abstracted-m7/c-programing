

// Guess the number game.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    
    int guess;
    int attempts = 0;
    
    printf("Welcome to the Guess the Number game!\n");
    printf("I have selected a secret number between 1 and 100. Try to guess it!\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        attempts++;
        
        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", secretNumber, attempts);
        }
    } while (guess != secretNumber);
    
    return 0;
}
