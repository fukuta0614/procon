#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i;
    int j;
    const char *flag = "ruoYced_ehpigniriks_i_llrg_stae";
    for (int key = 1; key < 100; key++){
        printf("cpaw{");
        for (i = key - 1; i <= strlen(flag); i += key){
            for (j = i; j >= i - key + 1; j--) {
                printf("%c", flag[j]);
            }
        }
        printf("}\n");
    }

    return 0;
}
