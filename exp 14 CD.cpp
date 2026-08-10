#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
char stack[100];
int top = -1;
int temp = 1;

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void generateTAC(char op, char a, char b)
{
    printf("t%d = %c %c %c\n", temp, a, op, b);
}

int main()
{
    int i, j;
    char postfix[100];
    char operands[100][10];
    int optop = -1;
    int ptop = -1;
    char ch;

    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++)
    {
        ch = expr[i];

        if (isalnum(ch))
        {
            postfix[++ptop] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[++ptop] = stack[top--];

            if (top != -1)
                top--;
        }
        else
        {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[++ptop] = stack[top--];
            }

            stack[++top] = ch;
        }
    }

    while (top != -1)
        postfix[++ptop] = stack[top--];

    postfix[++ptop] = '\0';

    printf("\nThree Address Code:\n");

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if (isalnum(ch))
        {
            operands[++optop][0] = ch;
            operands[optop][1] = '\0';
        }
        else
        {
            char op1[10], op2[10], result[10];

            strcpy(op2, operands[optop--]);
            strcpy(op1, operands[optop--]);

            sprintf(result, "t%d", temp);

            printf("%s = %s %c %s\n", result, op1, ch, op2);

            strcpy(operands[++optop], result);

            temp++;
        }
    }

    return 0;
}
