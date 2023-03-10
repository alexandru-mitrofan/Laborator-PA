#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#include <stdbool.h>


#define MAX 1000
#define NUMBER_TEST 20
//#define FILE_LENGTH 50
#define INF 9999999
int distance[1000];

void Dijkstra(int graph[MAX][MAX], int n, int startnode) {

    int visited[MAX], count, mindistance, nextnode, i, j;

    for (i = 0; i < n; i++) {
        distance[i] = graph[startnode][i];
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1) {
        mindistance = INF;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++) {

            if (!visited[i])
                if (mindistance + graph[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + graph[nextnode][i];
                }
        }
        count++;
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
        // strcat(output_name, "./outDij/test");
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

        fscanf( in , "%d %d", & n, & m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j)
                    mat[i][j] = 0;
                else
                    mat[i][j] = INF;
            }
        }

        int flag = 0;
        for (i = 0; i < m; i++) {
            fscanf( in , "%d %d %d", & nod1, & nod2, & dist);
            mat[nod1][nod2] = dist;
            if (dist < 0) {
                flag = 1;
            }
        }

        if (flag == 1) {
            fprintf(out, "Contine muchii negative deci nu se poate apllica Dijkstra");

        } else {
            for (i = 0; i < n; i++) {
                Dijkstra(mat, n, i);
                for (j = 0; j < n; j++) {
                    if (distance[j] == INF)
                        fprintf(out, "inf ");
                    else
                        fprintf(out, "%d ", distance[j]);
                }
                fprintf(out, "\n");
            }
        }

        // free(input_name);
        // free(output_name);
    }

}