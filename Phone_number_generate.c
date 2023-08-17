#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PHONE_NUMBER_LENGTH 10

char* generatePhoneNumber() {
    char* phoneNumber = (char*)malloc((PHONE_NUMBER_LENGTH + 1) * sizeof(char));
    
    for (int i = 0; i < PHONE_NUMBER_LENGTH; i++) {
        phoneNumber[i] = rand() % 10 + '0'; // Random digit from 0 to 9
    }
    
    phoneNumber[PHONE_NUMBER_LENGTH] = '\0';
    
    return phoneNumber;
}

int main() {
    srand(time(NULL));
    
    printf("Generated Phone Numbers:\n");
    
    for (int i = 0; i < 5; i++) {
        char* phoneNumber = generatePhoneNumber();
        printf("%d. %s\n", i + 1, phoneNumber);
        free(phoneNumber);
    }
    
    return 0;
}
