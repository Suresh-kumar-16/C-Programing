#include <stdio.h>
#include <ctype.h>

#define SHIFT 3  // Define the shift for the Caesar cipher

// Function to encrypt the message
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) { // Encrypt only alphabetic characters
            char offset = isupper(message[i]) ? 'A' : 'a';
            message[i] = ((message[i] - offset + shift) % 26) + offset;
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) { // Decrypt only alphabetic characters
            char offset = isupper(message[i]) ? 'A' : 'a';
            message[i] = ((message[i] - offset - shift + 26) % 26) + offset; // Added 26 to handle negative shifts
        }
    }
}

int main() {
    char message[] = "HAVE A NICE DAY";  // The message to be encrypted

    printf("Original message: %s\n", message);

    // Encrypt the message
    encrypt(message, SHIFT);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, SHIFT);
    printf("Decrypted message: %s\n", message);

    return 0;
}
