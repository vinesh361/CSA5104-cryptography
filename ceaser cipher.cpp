#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
char encrypt(char ch, int key) {
    if(isalpha(ch)) {
        char offset = isupper(ch) ? 'A' : 'a';
        return (ch - offset + key) % ALPHABET_SIZE + offset;
    }
    return ch;
}
char decrypt(char ch, int key) {
    if(isalpha(ch)) {
        char offset = isupper(ch) ? 'A' : 'a';
        return (ch - offset - key + ALPHABET_SIZE) % ALPHABET_SIZE + offset;
    }
    return ch;
}
int main() {
    char message[1000];
    int key;
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key (shift): ");
    scanf("%d", &key);
    key = key % ALPHABET_SIZE;  
    for(int i = 0; message[i] != '\0'; i++) {
        message[i] = encrypt(message[i], key);
    }
    printf("Encrypted message: %s", message);
    for(int i = 0; message[i] != '\0'; i++) {
        message[i] = decrypt(message[i], key);
    }
    printf("Decrypted message: %s", message);
    return 0;
}
