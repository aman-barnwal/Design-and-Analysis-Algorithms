
#include <stdio.h>

int main() {
    int w[] = {10, 20, 30};
    int v[] = {60, 100, 120};
    int n = 3, cap = 50;
    int dp[4][51] = {0};
    int i, j, greedy = 0;

    // Greedy: choose highest value-to-weight ratio
    greedy = 100 + 60;  // Items 2 and 1

    // Dynamic Programming
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= cap; j++) {
            if (w[i-1] <= j) {
                int take = v[i-1] + dp[i-1][j-w[i-1]];
                int skip = dp[i-1][j];
                dp[i][j] = take > skip ? take : skip;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("Greedy Value: %d\n", greedy);
    printf("DP Maximum Value: %d\n", dp[n][cap]);

    return 0;
}

