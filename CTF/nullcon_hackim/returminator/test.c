#include <stdio.h>

int main() {
    char str[256];
    scanf("%s", str);
    char x = getchar();
    printf("入力値は「%s」です。%c \n", str, x);

    return 0;
}