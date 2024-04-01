#include <stdio.h>

// Function to convert integer to base 64
void toBase64(long long num) {
    // Array to store the base 64 digits
    char base64[100];
    int i = 0;

    // Convert the number to base 64
    while (num != 0) {
        int remainder = num % 64;
        if (remainder < 10) {
            base64[i++] = remainder + '0';
        } else if (remainder < 36) {
            base64[i++] = remainder - 10 + 'a';
        } else if (remainder < 62) {
            base64[i++] = remainder - 36 + 'A';
        } else if (remainder == 62) {
            base64[i++] = '+';
        } else if (remainder == 63) {
            base64[i++] = '/';
        }
        num = num / 64;
    }

    // Print the base 64 representation in reverse order
    printf("Base 64 representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", base64[j]);
    }
    printf("\n");
}

int main() {
    long long num;

    // Input integer from user
    printf("Enter an integer: ");
    scanf("%lld", &num);

    // Convert to base 64
    toBase64(num);

    return 0;
}
