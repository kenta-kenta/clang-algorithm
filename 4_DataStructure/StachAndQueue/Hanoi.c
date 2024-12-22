#include <stdio.h>

// スタックを用いてハノイの塔を解く
typedef struct
{
    int from; // 移動元
    int to;   // 移動先
    int aux;  // 補助柱
    int n;    // 移動するディスクの数
} State;

// スタックの構造体
typedef struct
{
    State stack[100];
    int top;
} Stack;

// スタックの初期化
void initStack(Stack *s)
{
    s->top = -1;
}

// スタックが空か確認
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// スタックに状態をプッシュ
void push(Stack *s, State state)
{
    if (s->top < 100 - 1)
    {
        s->stack[++(s->top)] = state;
    }
    else
    {
        printf("Stack overflow\n");
        exit(1);
    }
}

// スタックから状態をポップ
State pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->stack[(s->top)--];
    }
    else
    {
        printf("Stack underflow\n");
        exit(1);
    }
}

// ハノイの塔の移動手順を表示
// ディスク移動の出力
void moveDisk(int from, int to)
{
    printf("Move disk from %c to %c\n", 'A' + from, 'A' + to);
}

// ハノイの塔をスタックで解く
void hanoi(int numDisks)
{
    Stack stack;
    initStack(&stack);

    // 初期状態をプッシュ
    State initialState = {0, 2, 1, numDisks};
    push(&stack, initialState);

    while (!isEmpty(&stack))
    {
        // スタックから現在の状態を取得
        State current = pop(&stack);

        if (current.n == 1)
        {
            // ディスクが1枚の場合は移動
            moveDisk(current.from, current.to);
        }
        else
        {
            // 再帰を模倣するために状態をスタックにプッシュ
            // 補助柱から移動先への移動を後で処理
            push(&stack, (State){current.aux, current.to, current.from, current.n - 1});
            // 移動元から移動先への移動
            push(&stack, (State){current.from, current.to, current.aux, 1});
            // 移動元から補助柱への移動を先に処理
            push(&stack, (State){current.from, current.aux, current.to, current.n - 1});
        }
    }
}

void main()
{
    int numDisks = 4;
    hanoi(numDisks);
}