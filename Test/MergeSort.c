#include <stdio.h>
#define M 1000

void mergesort(int a[], int left, int right)
{
    int i, j, k, mid;
    int work[M];
    if (left < right)
    {
        mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        for (i = mid; i >= left; i--)
        {
            work[i] = a[i];
        }
        for (j = mid + 1; j <= right; j++)
        {
            work[right + mid + 1 - j] = a[j];
        }
        i = left;
        j = right;
        for (k = left; k <= right; k++)
        {
            if (work[i] < work[j])
            {
                a[k] = work[i++];
            }
            else
            {
                a[k] = work[j--];
            }
        }
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
    mergesort(a, 0, n);
    // 並べ替えた配列を表示
    for (i = 0; i < n; i++)
    {
        printf("%5d\n", a[i]);
    }
}
