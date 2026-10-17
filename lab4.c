
#include <stdio.h>

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = 6, i, last = 0;

    printf("Selected activities: ");
    printf("A1 ");

    for (i = 1; i < n; i++) {
        if (s[i] >= f[last]) {
            printf("A%d ", i + 1);
            last = i;
        }
    }

    return 0;
}

