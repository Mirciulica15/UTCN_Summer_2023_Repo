#include <stdlib.h>
#include <stdio.h>

int a[4][5];

int main() {

    for(int i = 0; i < 4; i++) {
        for(int j = 4; j >= 0; j--) {
            a[i][j] = 5 - j + 5 * i;
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}