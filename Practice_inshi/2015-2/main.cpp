#include <stdio.h>
#include <math.h>


int g(int n){
    int temp = 0;
    for (int i=0;i<=n;i++){
        if (i == 0){
            temp = 1;
        }
        else{
            temp = (1103515245 * temp + 12345) % int(pow(2,26));
        }
    }
    return temp;
}

int main(void){

    int k = 1;
    int temp = 1;
    while (true) {
        if (g(k) == 1) break;
        k += 1;
        if (k % 100 == 0) printf("%d\n",k);
    }
    printf("%d\n",k);

}