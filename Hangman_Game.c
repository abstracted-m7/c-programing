
// Find the words

#include <stdio.h>
#include <string.h>

int main() {
    char secretWord[] = "hangman";
    int wordLength = strlen(secretWord);
    char guessedWord[wordLength];
    int attempts = 6;
    
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    
    printf("Welcome to Hangman!\n");
    
    while (attempts > 0) {
        printf("Word: ");
        for (int i = 0; i < wordLength; i++) {
            printf("%c ", guessedWord[i]);
        }
        printf("\n");
        
        char guess;
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = 1;
            }
        }
        
        if (!found) {
            attempts--;
            printf("Incorrect guess! You have %d attempts left.\n", attempts);
        }
        
        int correct = 1;
        for (int i = 0; i < wordLength; i++) {
            if (guessedWord[i] != secretWord[i]) {
                correct = 0;
                break;
            }
        }
        
        if (correct) {
            printf("Congratulations! You guessed the word: %s\n", secretWord);
            break;
        }
    }
    
    if (attempts == 0) {
        printf("Sorry, you've run out of attempts. The word was: %s\n", secretWord);
    }
    
    return 0;
}
