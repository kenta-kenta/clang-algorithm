#include <stdio.h>
#include <stdlib.h> // malloc, free, exit, EXIT_FAILURE
#include <limits.h> // INT_MAX

#define MAX_PATH 100

char *visited = NULL;
int nvertices = 7;
char amat[][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 1},
    {0, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

char amatrix(int i, int j)
{
    return amat[i][j];
}

// グローバル変数：最短経路の記録
int bestPath[MAX_PATH];
int bestPathLen = INT_MAX;

// 現在の経路を表示するユーティリティ
void printPath(int path[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void dfsearch_rec(int current, int dest, int dp, int currPath[])
{
    currPath[dp] = current; // 現在の頂点を経路に追加
    dp++;                   // 経路長を更新

    // 目的地に到達した場合
    if (current == dest)
    {
        printf("Found path: ");
        printPath(currPath, dp);
        // 最短経路の更新（複数あればどれか一つでよい）
        if (dp < bestPathLen)
        {
            bestPathLen = dp;
            for (int i = 0; i < dp; i++)
                bestPath[i] = currPath[i];
        }
        return;
    }
    // 再帰的に隣接頂点へ探索
    for (int i = 0; i < nvertices; i++)
    {
        if (amatrix(current, i) == 1 && visited[i] == 0)
        {
            visited[i] = 1;
            dfsearch_rec(i, dest, dp, currPath);
            visited[i] = 0; // バックトラック
        }
    }
}

// dfsearch:
// 初期状態の visited 配列の確保、初期化を行い、dfsearch_rec を呼び出す。
void dfsearch(int v1, int v2)
{
    int i;
    // visited の確保と初期化
    visited = (char *)malloc(sizeof(char) * nvertices);
    if (visited == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < nvertices; i++)
        visited[i] = 0;
    visited[v1] = 1;

    // 最短経路の初期化
    bestPathLen = INT_MAX;
    int currPath[MAX_PATH];

    printf("Starting at vertex %d,\n", v1);
    dfsearch_rec(v1, v2, 0, currPath);

    if (bestPathLen != INT_MAX)
    {
        printf("Shortest path: ");
        printPath(bestPath, bestPathLen);
    }
    else
    {
        printf("No path found from %d to %d.\n", v1, v2);
    }
    free(visited);
}

int main()
{
    // 既存の dfsearch（今回、全経路探索と最短経路更新を行う）
    printf("DFsearch (all paths and the shortest path):\n");
    dfsearch(0, 6);

    return 0;
}