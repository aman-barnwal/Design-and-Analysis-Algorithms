
#include <stdio.h>

#define INF 9999

int main() {
    int g[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int d[5], visited[5] = {0};
    int i, j, u, min, src = 0;

    for (i = 0; i < 5; i++)
        d[i] = INF;

    d[src] = 0;

    for (i = 0; i < 5; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < 5; j++)
            if (!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }

        if (u == -1) break;

        visited[u] = 1;

        for (j = 0; j < 5; j++)
            if (g[u][j] && !visited[j] &&
                d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }

    printf("Shortest distances from source 0:\n");
    for (i = 0; i < 5; i++)
        printf("To vertex %d = %d\n", i, d[i]);

    return 0;
}

