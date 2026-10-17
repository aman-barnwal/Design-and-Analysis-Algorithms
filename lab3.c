
#include <stdio.h>
#include <time.h>

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2] = {0}, i, j, k;
    clock_t start, end;

    start = clock();

    // Traditional multiplication
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];

    end = clock();

    printf("Traditional Result:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    printf("Traditional Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    // Strassen's theoretical comparison
    printf("\nStrassen Time Complexity: O(n^2.807)\n");
    printf("Traditional Time Complexity: O(n^3)\n");

    return 0;
}

