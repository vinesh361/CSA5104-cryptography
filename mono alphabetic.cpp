#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
const char substitution[ALPHABET_SIZE] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
void encrypt(char plaintext[], char ciphertext[]) {
    for(int i = 0; i < strlen(plaintext); i++) {
        if(isalpha(plaintext[i])) {
            if(isupper(plaintext[i])) {
                ciphertext[i] = substitution[plaintext[i] - 'A'];
            } else {
                ciphertext[i] = tolower(substitution[plaintext[i] - 'a']);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}
void decrypt(char ciphertext[], char plaintext[]) {
    for(int i = 0; i < strlen(ciphertext); i++) {
        if(isalpha(ciphertext[i])) {
            for(int j = 0; j < ALPHABET_SIZE; j++) {
                if(isupper(ciphertext[i]) && ciphertext[i] == substitution[j]) {
                    plaintext[i] = 'A' + j;
                    break;
                } else if(islower(ciphertext[i]) && ciphertext[i] == tolower(substitution[j])) {
                    plaintext[i] = 'a' + j;
                    break;
                }
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char plaintext[100], encrypted[100], decrypted[100];

    printf("Enter the plaintext: ");
    gets(plaintext);

    encrypt(plaintext, encrypted);
    printf("Encrypted Text: %s\n", encrypted);

    decrypt(encrypted, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
