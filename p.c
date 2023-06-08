#include <stdio.h>

int main () {
    long P[10][10] = {1,};

    printf("%d", sizeof(*P));
    for (int i = 0; i < 10; i++) {
        printf("%p, ", *(P + i));
    }
    return 0;
}