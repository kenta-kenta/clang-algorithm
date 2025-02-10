//// filepath: /home/kenta/Practice/clang/6_AdvancedTopics/WidthFirstSearch.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_PATH 100
#define MAX_QUEUE_SIZE 1000

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

/* Path構造体: 経路（頂点列）を保持 */
typedef struct
{
    int vertices[MAX_PATH];
    int len;
} Path;

/* Queue構造体: Pathへのポインタを管理 */
typedef struct
{
    Path *items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue *q)
{
    return q->front == q->rear;
}

bool enqueue(Queue *q, Path *p)
{
    if (q->rear >= MAX_QUEUE_SIZE)
        return false;
    q->items[q->rear++] = p;
    return true;
}

Path *dequeue(Queue *q)
{
    if (isEmpty(q))
        return NULL;
    return q->items[q->front++];
}

/* 経路に頂点が含まれているかを確認（サイクル防止用） */
bool inPath(Path *p, int vertex)
{
    for (int i = 0; i < p->len; i++)
    {
        if (p->vertices[i] == vertex)
            return true;
    }
    return false;
}

void printPath(Path *p)
{
    for (int i = 0; i < p->len; i++)
    {
        printf("%d ", p->vertices[i]);
    }
    printf("\n");
}

/* グローバル変数: 最短経路の記録 */
int bestPathLen = INT_MAX;
Path bestPath;

/* main関数内の処理を分離した runBFS 関数 */
void runBFS()
{
    int start = 0, dest = 6;
    bestPathLen = INT_MAX;

    Queue q;
    initQueue(&q);

    /* 初期経路の作成 */
    Path *initPath = (Path *)malloc(sizeof(Path));
    initPath->len = 0;
    initPath->vertices[initPath->len++] = start;
    enqueue(&q, initPath);

    while (!isEmpty(&q))
    {
        Path *curr = dequeue(&q);
        int last = curr->vertices[curr->len - 1];

        /* 目的地に到達した場合 */
        if (last == dest)
        {
            printf("Found path: ");
            printPath(curr);
            if (curr->len < bestPathLen)
            {
                bestPathLen = curr->len;
                bestPath = *curr; // 構造体のコピー（配列も含む）
            }
        }

        /* 既に最短経路が見つかっていれば、それ以上伸ばさない */
        if (curr->len < bestPathLen - 1)
        {
            /* 隣接頂点でかつ、サイクルにならないものを拡張 */
            for (int i = 0; i < nvertices; i++)
            {
                if (amatrix(last, i) == 1 && !inPath(curr, i))
                {
                    Path *newPath = (Path *)malloc(sizeof(Path));
                    newPath->len = curr->len;
                    for (int j = 0; j < curr->len; j++)
                    {
                        newPath->vertices[j] = curr->vertices[j];
                    }
                    newPath->vertices[newPath->len++] = i;
                    enqueue(&q, newPath);
                }
            }
        }
        free(curr);
    }

    if (bestPathLen != INT_MAX)
    {
        printf("Shortest path: ");
        for (int i = 0; i < bestPathLen; i++)
        {
            printf("%d ", bestPath.vertices[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No path found from %d to %d\n", start, dest);
    }
}

int main()
{
    runBFS();
    return 0;
}