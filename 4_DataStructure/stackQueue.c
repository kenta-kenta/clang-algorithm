#include <stdio.h>

// スタックの実装
// 空のスタックを作成
// int stackEmpty(int top)
// {
//     if (top == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// // スタックが満杯かどうかを判定
// int stackFull(int top)
// {
//     if (top == 9)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// // スタックに要素を追加
// void push(int arr[], int x, int *top)
// {
//     if (stackFull(*top) == 1)
//     {
//         printf("error: stack overflow\n");
//     }
//     else
//     {
//         *top = *top + 1;
//         arr[*top] = x;
//     }
// }

// // スタックから要素を取り出す
// int pop(int arr[], int *top)
// {
//     if (stackEmpty(*top) == 1)
//     {
//         printf("error: stack underflow\n");
//         return -1;
//     }
//     else
//     {
//         *top = *top - 1;
//         return arr[*top + 1];
//     }
// }
// ポインタを利用しなければ，topの値が変わらない

// void main()
// {
//     int arr[10];
//     int top = 0;
//     for (int i = 1; i < 11; i++)
//     {
//         push(arr, i, &top);
//     }
//     for (int i = 1; i < 11; i++)
//     {
//         printf("%d\n", pop(arr, &top));
//     }
// }

// // キューの実装
// // キューに要素を追加
// void enqueue(int arr[], int x, int *tail)
// {
//     if (*tail == 10)
//     {
//         printf("error: stack overflow\n");
//     }
//     else
//     {
//         arr[*tail] = x;
//         *tail = *tail + 1;
//     }
// }

// // キューから要素を取り出す
// int dequeue(int arr[], int *head)
// {
//     int x = arr[*head];
//     if (*head == 10)
//     {
//         printf("error: stack underflow\n");
//         return -1;
//     }
//     else
//     {
//         *head = *head + 1;
//     }
//     return x;
// }

// void main()
// {
//     int arr[10];
//     int tail = 0;
//     int head = 0;
//     for (int i = 1; i < 12; i++)
//     {
//         enqueue(arr, i, &tail);
//     }
//     for (int i = 1; i < 12; i++)
//     {
//         printf("%d\n", dequeue(arr, &head));
//     }
// }

// スタックを用いてハノイの塔を解く
// typedef struct
// {
//     int from; // 移動元
//     int to;   // 移動先
//     int aux;  // 補助柱
//     int n;    // 移動するディスクの数
// } State;

// スタックの構造体
// typedef struct
// {
//     State stack[100];
//     int top;
// } Stack;

// // スタックの初期化
// void initStack(Stack *s)
// {
//     s->top = -1;
// }

// // スタックが空か確認
// int isEmpty(Stack *s)
// {
//     return s->top == -1;
// }

// // スタックに状態をプッシュ
// void push(Stack *s, State state)
// {
//     if (s->top < 100 - 1)
//     {
//         s->stack[++(s->top)] = state;
//     }
//     else
//     {
//         printf("Stack overflow\n");
//         exit(1);
//     }
// }

// // スタックから状態をポップ
// State pop(Stack *s)
// {
//     if (!isEmpty(s))
//     {
//         return s->stack[(s->top)--];
//     }
//     else
//     {
//         printf("Stack underflow\n");
//         exit(1);
//     }
// }

// ハノイの塔の移動手順を表示
// ディスク移動の出力
// void moveDisk(int from, int to)
// {
//     printf("Move disk from %c to %c\n", 'A' + from, 'A' + to);
// }

// // ハノイの塔をスタックで解く
// void hanoi(int numDisks)
// {
//     Stack stack;
//     initStack(&stack);

//     // 初期状態をプッシュ
//     State initialState = {0, 2, 1, numDisks};
//     push(&stack, initialState);

//     while (!isEmpty(&stack))
//     {
//         // スタックから現在の状態を取得
//         State current = pop(&stack);

//         if (current.n == 1)
//         {
//             // ディスクが1枚の場合は移動
//             moveDisk(current.from, current.to);
//         }
//         else
//         {
//             // 再帰を模倣するために状態をスタックにプッシュ
//             // ステップ3: 補助柱から移動先への移動を後で処理
//             push(&stack, (State){current.aux, current.to, current.from, current.n - 1});
//             // ステップ2: 移動元から移動先への移動
//             push(&stack, (State){current.from, current.to, current.aux, 1});
//             // ステップ1: 移動元から補助柱への移動を先に処理
//             push(&stack, (State){current.from, current.aux, current.to, current.n - 1});
//         }
//     }
// }

// void main()
// {
//     int numDisks = 4;
//     hanoi(numDisks);
// }

// スタックを用いて逆ポーランド記法を実装

#include <stdio.h>

#define MAX_STACK_SIZE 100

// スタック構造体
typedef struct
{
    double data[MAX_STACK_SIZE];
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

// スタックが満杯か確認
int isFull(Stack *s)
{
    return s->top == MAX_STACK_SIZE - 1;
}

// スタックにプッシュ
void push(Stack *s, double value)
{
    if (isFull(s))
    {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// スタックからポップ
double pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
        return 0;
    }
    return s->data[(s->top)--];
}

// 文字列を数値に変換（簡易版）
double stringToDouble(const char *str)
{
    double result = 0.0;
    double fraction = 0.1;
    int isNegative = 0;
    int decimalPoint = 0;

    if (*str == '-')
    { // 符号の処理
        isNegative = 1;
        str++;
    }

    while (*str)
    {
        if (*str == '.')
        {
            decimalPoint = 1;
            str++;
            continue;
        }

        if (!decimalPoint)
        {
            result = result * 10 + (*str - '0');
        }
        else
        {
            result += (*str - '0') * fraction;
            fraction *= 0.1;
        }
        str++;
    }

    return isNegative ? -result : result;
}

// 逆ポーランド記法を評価
double evaluateRPN(const char *expression)
{
    Stack stack;
    initStack(&stack);

    char token[20];
    int tokenIndex = 0;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char c = expression[i];
        if (c == ' ' || expression[i + 1] == '\0')
        {
            if (expression[i + 1] == '\0' && c != ' ')
            {
                token[tokenIndex++] = c; // 最後の文字を追加
            }
            token[tokenIndex] = '\0';

            if (tokenIndex > 0)
            {
                // 数値かどうかの判定
                if ((token[0] >= '0' && token[0] <= '9') || token[0] == '-')
                {
                    push(&stack, stringToDouble(token));
                }
                else
                {
                    // 演算子の場合
                    double b = pop(&stack);
                    double a = pop(&stack);

                    switch (token[0])
                    {
                    case '+':
                        push(&stack, a + b);
                        break;
                    case '-':
                        push(&stack, a - b);
                        break;
                    case '*':
                        push(&stack, a * b);
                        break;
                    case '/':
                        if (b == 0)
                        {
                            printf("Error: Division by zero\n");
                            return 0;
                        }
                        push(&stack, a / b);
                        break;
                    default:
                        printf("Error: Unknown operator %s\n", token);
                        return 0;
                    }
                }
            }
            tokenIndex = 0; // トークンをリセット
        }
        else
        {
            token[tokenIndex++] = c;
        }
    }

    return pop(&stack);
}

int main()
{
    char expression[100] = "3 4 + 2 * 7 /";

    double result = evaluateRPN(expression);
    printf("Result: %f\n", result);

    return 0;
}
