/*
*	Created by Nan Mihai on 04.04.2020
*	Copyright (c) 2020 Nan Mihai. All rights reserved.
*	Laborator - Proiectarea algoritmilor (Grafuri)
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2019-2020, Seria CD
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"
#include "queue.h"
#include "list.h"

#define MAX 1000
#define INF 9999999

int dis[1000];
int flag = 0;
static void BellmanFord(int graph[MAX][MAX], int n, int m,
    int src) {


    for (int i = 0; i < n; i++)
        dis[i] = INF;


    dis[src] = 0;
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < m; j++) {
            if (dis[graph[j][0]] != INF && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])

                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        }
    }
	//verificam cicluri neg
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
	freopen("test1.in", "r", stdin);
	int n, m, i, nod1, nod2, dist, j;
    int mat[MAX][MAX];

    scanf("%d %d", & n, & m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", & nod1, & nod2, & dist);
        mat[i][0] = nod1;
        mat[i][1] = nod2;
        mat[i][2] = dist;
    }


    for (i = 0; i < n; i++) {
        BellmanFord(mat, n, m, i);
    }
    if (flag == 1) {
        printf("Are cicluri negative");
    } else {

        for (i = 0; i < n; i++) {
            BellmanFord(mat, n, m, i);
            for (j = 0; j < n; j++) {
                if (dis[j] == INF)
                    printf("inf ");
                else
                    printf("%d ", dis[j]);
            }
            printf("\n");
        }
    }

    flag = 0;
	return 0;
}