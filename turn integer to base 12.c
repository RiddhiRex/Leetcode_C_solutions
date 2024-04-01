#include <stdio.h>

// Function to convert integer to base 12
void toBase12(int num) {
    // Array to store the digits in base 12
    char base12[50];
    int idx = 0;
    int rem= 0;

    // Handle the case for 0 separately
    if (num == 0) {
        printf("0\n");
        return;
    }

    // Convert the number to base 12
    while (num != 0) {
        rem = num % 12;
        if (rem < 10) {
            base12[idx++] = rem + '0'; //do number to ascii conversion
        } else {
            base12[idx++] = rem - 10 + 'A'; //do number to ascii conversion
        }
        num = num / 12;
    }

    // Print the base 12 representation in reverse order
    printf("Base 12 representation: ");
    for (int j = idx - 1; j >= 0; j--) {
        printf("%c", base12[j]);
    }
    printf("\n");
}

int main() {
    int num=11;
    // Convert to base 12
    toBase12(num);
    return 0;
}
