#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encryptVigenere(char *plaintext, char *key, char *ciphertext) {
    int i, j = 0, keyLen = strlen(key), textLen = strlen(plaintext);
    for (i = 0; i < textLen; i++) {
        if (isalpha(plaintext[i])) { 
            if (isupper(plaintext[i])) {
                ciphertext[i] = (plaintext[i] - 'A' + (toupper(key[j % keyLen]) - 'A')) % 26 + 'A';
            } else {
                ciphertext[i] = (plaintext[i] - 'a' + (tolower(key[j % keyLen]) - 'a')) % 26 + 'a';
            }
            j++;  
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';  
}
void decryptVigenere(char *ciphertext, char *key, char *decryptedText) {
    int i, j = 0, keyLen = strlen(key), textLen = strlen(ciphertext);
    for (i = 0; i < textLen; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                decryptedText[i] = (ciphertext[i] - 'A' - (toupper(key[j % keyLen]) - 'A') + 26) % 26 + 'A';
            } else {
                decryptedText[i] = (ciphertext[i] - 'a' - (tolower(key[j % keyLen]) - 'a') + 26) % 26 + 'a';
            }
            j++;
        } else {
            decryptedText[i] = ciphertext[i];
        }
    }
    decryptedText[i] = '\0';
}
int main() {
    char plaintext[1000], key[100], ciphertext[1000], decryptedText[1000];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    encryptVigenere(plaintext, key, ciphertext);
    printf("Encrypted: %s\n", ciphertext);
    decryptVigenere(ciphertext, key, decryptedText);
    printf("Decrypted: %s\n", decryptedText);
    return 0;
}
