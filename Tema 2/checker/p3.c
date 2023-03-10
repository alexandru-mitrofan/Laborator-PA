#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#define MAX 1000
#define INF 9999999

int dis[MAX];
int flag = 0;
int mat[MAX][MAX], graf[500][500];
static void BellmanFord(int graph[MAX][MAX], int n, int m,
    int src) {

    for (int i = 1; i <= n; i++)
        dis[i] = INF;

    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++) {

        for (int j = 1; j <= m; j++) {
            if (dis[graph[j][0]] != INF && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])

                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        }
    }

}

int main() {

    FILE * fin = fopen("p3.in", "r");
    FILE * fout = fopen("p3.out", "w+");
    int n, m, i, nod1, nod2, dist, j;

    if (!fin || !fout) {
        printf("Could not open file\n");
        return 1;
    }

    fscanf(fin, "%d %d", & n, & m);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            graf[i][j] = INF;
        }

    }
    for (i = 1; i <= m; i++) {
        fscanf(fin, "%d %d %d", & nod1, & nod2, & dist);
        mat[i][0] = nod1;
        mat[i][1] = nod2;
        mat[i][2] = dist;
        graf[nod1][nod2] = dist;
    }

    int minim = INF;
    for (i = 1; i <= n; i++) {
        BellmanFord(mat, n, m, i);
        for (j = 1; j <= n; j++) {
            if (graf[j][i] != INF && j != i) {
                if (dis[j] + graf[j][i] < minim) {

                    minim = dis[j] + graf[j][i];
                }
            }
        }

    }
    fprintf(fout, "%d", minim);

    return 0;

}