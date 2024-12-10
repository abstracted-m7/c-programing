#include <stdio.h>
#include <string.h>

// Function to perform XOR operation
void xor(char *dividend, char *divisor, int len) {
    for (int i = 1; i < len; i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

// Function to calculate CRC
void calculateCRC(char *data, char *generator, char *remainder) {
    int data_len = strlen(data);
    int gen_len = strlen(generator);

    // Append zeros to the data
    char dividend[data_len + gen_len];
    strcpy(dividend, data);
    for (int i = 0; i < gen_len - 1; i++) {
        dividend[data_len + i] = '0';
    }
    dividend[data_len + gen_len - 1] = '\0';

    char temp[gen_len];
    strncpy(temp, dividend, gen_len);
    temp[gen_len] = '\0';

    for (int i = 0; i <= data_len; i++) {
        if (temp[0] == '1') {
            xor(temp, generator, gen_len);
        }
        memmove(temp, temp + 1, gen_len - 1);
        temp[gen_len - 1] = dividend[i + gen_len];
    }

    strncpy(remainder, temp, gen_len - 1);
    remainder[gen_len - 1] = '\0';
}

int main() {
    char data[100], generator[100], remainder[100];

    printf("Enter data bits: ");
    scanf("%s", data);
    printf("Enter generator polynomial: ");
    scanf("%s", generator);

    calculateCRC(data, generator, remainder);

    printf("Remainder (CRC): %s\n", remainder);

    // Append remainder to data to form the transmitted frame
    strcat(data, remainder);
    printf("Transmitted frame: %s\n", data);

    return 0;
}






// Inputs:
// Enter data bits: 11010011101100
// Enter generator polynomial: 1011
// Output:
// Remainder (CRC): 100
// Transmitted frame: 11010011101100100


