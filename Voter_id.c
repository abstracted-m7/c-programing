#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VOTER_ID_LENGTH 10

char* generateRandomVoterID() {
    char* voterID = (char*)malloc((VOTER_ID_LENGTH + 1) * sizeof(char));

    // Include 2 random letters as uppercase alphabets
    for (int i = 0; i < 2; i++) {
        voterID[i] = rand() % 26 + 'A';
    }

    // Include 6 random digits
    for (int i = 2; i < 8; i++) {
        voterID[i] = rand() % 10 + '0';
    }

    // Include last 2 random letters as uppercase alphabets
    for (int i = 8; i < 10; i++) {
        voterID[i] = rand() % 26 + 'A';
    }

    voterID[VOTER_ID_LENGTH] = '\0';

    return voterID;
}

int main() {
    srand(time(NULL));

    printf("Generated Voter ID-like Numbers:\n");

    for (int i = 0; i < 5; i++) {
        char* voterID = generateRandomVoterID();
        printf("%d. %s\n", i + 1, voterID);
        free(voterID);
    }

    return 0;
}
