#include <stdio.h>
#define M 1000

void sort(int a[], int n)
{
    int i, j, tmp, min, m;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        for (j = i + 1; j < n; j++)
        {
            /* もしもa[j]がa[i]より小さいならば，
            a[i]とa[j]を入れ替える。*/
            if (min > a[j])
            {
                m = j;
                min = a[j];
            }
        }
        tmp = a[i];
        a[i] = min;
        a[m] = tmp;
    }
}

int main(int argc, char **argv)
{
    int i, n;
    int a[M];
    char *filename;
    FILE *fp;
    // コマンド行の引数からファイル名を得る．
    filename = argv[1];
    // ファイル filename から数値列を読み込み，配列 a に格納
    // データの数（有効な配列の要素数）を n に格納
    fp = fopen("data1.txt", "r");
    for (i = 0; i < M; i++)
    {
        char ret = fscanf(fp, "%d", &a[i]);
        if (ret == EOF)
        {
            break;
        }
        n = i + 1;
    }
    fclose(fp);
    // 配列 a を並べ替え（ソーティング）
    sort(a, n);
    // 並べ替えた配列を表示
    for (i = 0; i < n; i++)
    {
        printf("%5d\n", a[i]);
    }
}

