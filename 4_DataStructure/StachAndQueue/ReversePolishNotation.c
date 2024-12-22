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
