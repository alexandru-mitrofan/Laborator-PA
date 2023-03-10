#include <stdio.h>

#include <stdlib.h>

int visited[10001], mat[10001][10001], muchii, cic_flag = 0, vis[10001];
int enter[10001], nrv;
int numofvisited(int n) {
    int v = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 1) {
            v++;
        }
    }
    return v;
}
void makevis0(int n) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
}
//trebuie sa fac 0 vis
void verif_cic(int i, int n, int inc) {

    for (int k = 1; k <= n; k++) {
        if (mat[i][k] == 1 && k == inc) {
            cic_flag = 1;
        }

        if (mat[i][k] == 1 && cic_flag == 0 && vis[k] == 0) {
            vis[k] = 1;
            verif_cic(k, n, inc);
        }
    }

}

void nornminus1(int i, int n) {

    for (int k = 1; k <= n; k++) {

        if ((mat[i][k] == 1 || mat[k][i] == 1) && visited[k] == 0) {
            visited[k] = 1;
            nrv++;
            if (cic_flag == 0) {
                makevis0(n);
                verif_cic(k, n, k);
            }

            nornminus1(k, n);
        }

    }

}

int main() {
    FILE * fin = fopen("p1.in", "r");
    FILE * fout = fopen("p1.out", "w");
    int n, m, a, b, i, ex, rasp, dif;
    if (!fin || !fout) {
        printf("Could not open file\n");
        return 1;
    }
    fscanf(fin, "%d %d", & n, & m);
    //printf("\n\n%d %d\n\n", n, m);
    for (i = 0; i < m; i++) {

        fscanf(fin, "%d %d", & a, & b);
        mat[a][b] = 1;
        enter[a] = 1;
        enter[b] = 1;
    }
    rasp = 0;
    for (i = 1; i <= n; i++) {

        if (visited[i] == 0 & enter[i] == 1) {
            ex = nrv;
            visited[i] = 1;
            nrv++;
            cic_flag = 0;
            nornminus1(i, n);
            dif = nrv - ex;
            if (cic_flag == 1) {
                rasp += dif;
            } else {
                rasp = rasp + dif - 1;
            }

        }
    }

    fprintf(fout, "%d\n", rasp);

    fclose(fin);
    fclose(fout);
    return 0;
}