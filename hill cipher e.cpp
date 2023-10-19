#include <stdio.h>
#include <stdlib.h>

void hillCipherEncrypt(int key[2][2], char plaintext[2], char ciphertext[2]) {
    int i, j;

    for (i = 0; i < 2; i++) {
        ciphertext[i] = 0;
        for (j = 0; j < 2; j++) {
            ciphertext[i] += key[i][j] * (plaintext[j] - 'A');
        }
        ciphertext[i] %= 26;
        ciphertext[i] += 'A';
    }
}

int main() {
    int key[2][2];
    char plaintext[2], ciphertext[2];

    printf("Enter the 2x2 Hill cipher key matrix (4 integers):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter 2 characters of plaintext (uppercase letters): ");
    scanf(" %c %c", &plaintext[0], &plaintext[1]);

    hillCipherEncrypt(key, plaintext, ciphertext);

    printf("Ciphertext: %c%c\n", ciphertext[0], ciphertext[1]);

    return 0;
}
