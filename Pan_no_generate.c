#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAN_LENGTH 10

char* generateRandomPan() {
    char* pan = (char*)malloc((PAN_LENGTH + 1) * sizeof(char));

    // Include first 5 letters as uppercase alphabets
    for (int i = 0; i < 5; i++) {
        pan[i] = rand() % 26 + 'A';
    }

    // Include 4 random digits
    for (int i = 5; i < 9; i++) {
        pan[i] = rand() % 10 + '0';
    }

    // Include last character as uppercase alphabet
    pan[9] = rand() % 26 + 'A';

    pan[PAN_LENGTH] = '\0';

    return pan;
}

int main() {
    srand(time(NULL));

    printf("Generated PAN-like Numbers:\n");

    for (int i = 0; i < 5; i++) {
        char* pan = generateRandomPan();
        printf("%d. %s\n", i + 1, pan);
        free(pan);
    }

    return 0;
}
