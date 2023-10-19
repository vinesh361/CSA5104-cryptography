#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char *plainText, int rails) {
    int length = strlen(plainText);
    char code[rails][length];
    int count = 0;
    int len = 0;
    int j = 0;
    int direction = 1; 
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            code[i][j] = ' ';
        }
    }
    while (j < length) {
        code[count][j] = plainText[j];
        j++;
        if (count == 0) {
            direction = 1; 
        } else if (count == rails - 1) {
            direction = -1;
        }
        count += direction;
    }
    printf("Rail Fence Pattern:\n");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            printf("%c ", code[i][j]);
        }
        printf("\n");
    }
    printf("Encrypted Text: ");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            if (code[i][j] != ' ') {
                printf("%c", code[i][j]);
            }
        }
    }
    printf("\n");
}
int main() {
    int rails;
    char text[1000];
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    printf("Enter the text: ");
    scanf(" %s", text);
    railFenceEncrypt(text, rails);
    return 0;
}
