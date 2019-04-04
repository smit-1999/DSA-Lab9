#include <stdio.h>
#define MAX 10000

int min_cost = MAX;
int path_length = 0;

void clear(int n, int visit[n]){
    min_cost = MAX;
    for (int i = 0; i < n; i++) visit[i] = 0;
}

void dfs (int n, int a[n][n], int visit[n], int u, int v, int path, int cost){
    if (visit[u] == 1) return;
    else if (a[u][v] != 0) {
        if (path <= path_length) {
            if (min_cost > cost + a[u][v]) min_cost = cost + a[u][v];
        }
    }; 

    visit[u] = 1;
    for (int i = 0; i < n; i++){
        if (a[u][i] != 0) dfs(n,a,visit,i,v, path + 1,cost + a[u][i]);
    }
    visit[u] = 0;
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    int a[n][n];
    for (int i =0 ; i < n; i++){
        for (int j = 0; j <n; j++) a[i][j] = 0;
    }
    
    for (int i =0 ;i <m; i++) {
        int u,v,p;
        scanf("%d %d %d", &u, &v, &p);
        a[u][v] = p;
        a[v][u] = p;
    }

    int t;
    scanf("%d", &t);
    int visit[n];

    for (int i = 0; i < t; i++){
        int u, v;
        scanf("%d %d %d", &u, &v, &path_length);
        clear(n,visit);
        dfs(n,a,visit,u,v,0,0);

        if (min_cost == MAX) printf("Not possible\n");
        else printf("%d\n", min_cost);
    }
}

