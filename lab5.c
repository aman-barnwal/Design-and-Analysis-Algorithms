
#include <stdio.h>
#include <limits.h>

int main() {
    int p[] = {10, 30, 5, 60};
    int n = 3, i, j, k, l;
    int dp[10][10];

    for (i = 1; i <= n; i++)
        dp[i][i] = 0;

    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j]
                         + p[i-1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum multiplications: %d\n", dp[1][n]);

    return 0;
}

