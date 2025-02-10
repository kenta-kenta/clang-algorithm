#include <stdio.h>

#define CHARS 256

void report(char text[], long pos)
{
    printf("matched at text[%ld], after %ld comparisons.\n", pos, pos);
}

void naive_match(char pattern[], long psize, char text[], long tsize, int *matches)
{
    long anchor, pix;
    printf("pattern size = %ld, text size = %ld.\n", psize, tsize);
    long comps = 0;
    for (anchor = 0; anchor <= tsize - psize; anchor++)
    {
        for (pix = 0; pix < psize; pix++)
        {
            comps++;
            if (pattern[pix] != text[anchor + pix])
                break;
        }
        if (pix >= psize)
        {
            (*matches)++;
            report(text, anchor);
        }
    }
}

void make_bmh_table(long table[], char pattern[], long psize)
{
    long pix;
    for (pix = 0; pix < CHARS; pix++)
    {
        table[pix] = psize;
    }
    for (pix = 0; pix < psize - 1; pix++)
    {
        table[pattern[pix]] = psize - pix - 1;
    }
}

void bmh_match(char pattern[], long psize, char text[], long tsize)
{
    long table[CHARS]; // text上の文字に対する適切なシフト量
    long pix, anchor, tix;
    char c;
    printf("pattern size = %d, text size = %d.\n", psize, tsize);
    make_bmh_table(table, pattern, psize); // テーブルの作成
    int comps = 0;
    anchor = 0;
    while (anchor <= tsize - psize)
    {
        tix = anchor + psize - 1;
        c = text[tix];
        for (pix = psize - 1; pix >= 0; pix--)
        {
            comps++;
            if (pattern[pix] != text[tix])
                break;
            tix--;
        }
        if (pix < 0)
        {
            report(text, anchor);
        }
        anchor += table[c]; // シフト
    }
}

int main()
{
    char text[] = "abracadabra";
    char pattern[] = "abr";
    int matches = 0;
    naive_match(pattern, 3, text, 11, &matches);
    printf("matches = %d\n", matches);
    bmh_match(pattern, 3, text, 11);
    return 0;
}