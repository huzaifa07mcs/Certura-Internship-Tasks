#include <stdio.h>
#include <string.h>

void encrypt(char message[], char key[], char encrypted[]) {
    int msgLen = strlen(message), keyLen = strlen(key), i, j;
    for (i = 0, j = 0; i < msgLen; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = ((message[i] - 'A') + (key[j % keyLen] - 'A')) % 26 + 'A';
            j++;
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = ((message[i] - 'a') + (key[j % keyLen] - 'a')) % 26 + 'a';
            j++;
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[msgLen] = '\0';
}

void decrypt(char encrypted[], char key[], char decrypted[]) {
    int msgLen = strlen(encrypted), keyLen = strlen(key), i, j;
    for (i = 0, j = 0; i < msgLen; i++) {
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = ((encrypted[i] - 'A') - (key[j % keyLen] - 'A') + 26) % 26 + 'A';
            j++;
        } else if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = ((encrypted[i] - 'a') - (key[j % keyLen] - 'a') + 26) % 26 + 'a';
            j++;
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[msgLen] = '\0';
}

int main() {
    char message[100], key[100], encrypted[100], decrypted[100];

    printf("\n========================================\n");
    printf("    Simple Vigenere Cipher Tool   \n");
    printf("========================================\n");

    printf("\nEnter your secret key: ");
    gets(key);

    printf("Enter your message: ");
    gets(message);

    encrypt(message, key, encrypted);
    decrypt(encrypted, key, decrypted);

    printf("\n----------------------------------------\n");
    printf(" Original Message : %s\n", message);
    printf(" Encrypted Message: %s\n", encrypted);
    printf(" Decrypted Message: %s\n", decrypted);
    printf("----------------------------------------\n");

    return 0;
}

