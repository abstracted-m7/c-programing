// Only user's games

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Dice Rolling Simulator!\n");
    
    while (1) {
        printf("Press Enter to roll the dice (or 'q' to quit): ");
        char input = getchar();
        
        if (input == 'q') {
            break;
        }
        
        int diceValue = rand() % 6 + 1;
        printf("You rolled a %d!\n", diceValue);
        
        // Clear the input buffer
        while (getchar() != '\n');
    }
    
    return 0;
}

