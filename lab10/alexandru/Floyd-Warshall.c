#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#define MAX 1000
#define NUMBER_TEST 20
//#define FILE_LENGTH 50
#define INF 9999999

int matrix[MAX][MAX];
void floydWarshall(int graph[MAX][MAX], int n) {

    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

}

int dis[MAX];
int flag = 0;
static void BellmanFord(int graph[MAX][MAX], int n, int m,
    int src) {
    // Initialize distance of all vertices as infinite.

    for (int i = 0; i < n; i++)
        dis[i] = INF;

    // initialize distance of source as 0
    dis[src] = 0;

    // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < m; j++) {
            if (dis[graph[j][0]] != INF && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])

                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        }
    }

    // check for negative-weight cycles.
    // The above step guarantees shortest
    // distances if graph doesn't contain
    // negative weight cycle. If we get a
    // shorter path, then there is a cycle.

    for (int i = 0; i < m; i++) {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INF && dis[x] + weight < dis[y]) {
            flag = 1;
        }
    }
}

int main() {

    for (int i = 1; i <= NUMBER_TEST; i++) {
        FILE * in ;
        FILE * out;
        // char * input_name = (char * ) calloc(FILE_LENGTH, sizeof(char));
        // char * output_name = (char * ) calloc(FILE_LENGTH, sizeof(char));
        // char number_to_string[10];
        // strcat(input_name, "./in/test");
        // strcat(output_name, "./outFW/test");
        // sprintf(number_to_string, "%d", i);
        // strcat(input_name, number_to_string);
        // strcat(output_name, number_to_string);
        // strcat(input_name, ".in");
        // strcat(output_name, ".out");

        // in = fopen(input_name, "r");
        // out = fopen(output_name, "w");

        in=fopen("test.in","r");
        out=fopen("test.out","w");
        int n, m, i, nod1, nod2, dist, j;
        int mat[MAX][MAX];
        int verificare[MAX][MAX];
        fscanf( in , "%d %d", & n, & m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j)
                    mat[i][j] = INF;

            }
        }
        for (i = 0; i < m; i++) {
            fscanf( in , "%d %d %d", & nod1, & nod2, & dist);
            mat[nod1][nod2] = dist;
            verificare[i][0] = nod1;
            verificare[i][1] = nod2;
            verificare[i][2] = dist;
        }

        for (i = 0; i < n; i++) {
            BellmanFord(verificare, n, m, i);
        }
        if (flag == 1) {
            fprintf(out, "Are cicluri negative");
        } else {

            floydWarshall(mat, n);
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (matrix[i][j] == INF)
                        fprintf(out, "inf ");
                    else
                        fprintf(out, "%d ", matrix[i][j]);
                }
                fprintf(out, "\n");
            }
        }

        flag = 0;
        // free(input_name);
        // free(output_name);
    }

}