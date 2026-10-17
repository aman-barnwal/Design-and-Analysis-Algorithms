
#include <stdio.h>

#define INF 9999

int main() {
    int edges[5][3] = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {2, 3, -3}
    };

    int d[4] = {INF, INF, INF, INF};
    int i, j, u, v, w;

    d[0] = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            u = edges[j][0];
            v = edges[j][1];
            w = edges[j][2];

            if (d[u] != INF && d[u] + w < d[v])
                d[v] = d[u] + w;
        }
    }

    for (j = 0; j < 5; j++) {
        u = edges[j][0];
        v = edges[j][1];
        w = edges[j][2];

        if (d[u] != INF && d[u] + w < d[v]) {
            printf("Negative cycle detected");
            return 0;
        }
    }

    printf("Shortest distances from source 0:\n");
    for (i = 0; i < 4; i++)
        printf("Vertex %d = %d\n", i, d[i]);

    return 0;
}

