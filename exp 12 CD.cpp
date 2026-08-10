#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int pos = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if (input[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (input[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

void F()
{
    if (strncmp(&input[pos], "id", 2) == 0)
    {
        pos = pos + 2;
    }
    else if (input[pos] == '(')
    {
        pos++;
        E();

        if (input[pos] == ')')
        {
            pos++;
        }
        else
        {
            printf("\nError: Missing ')'\n");
        }
    }
    else
    {
        printf("\nError: Invalid symbol at position %d\n", pos);
    }
}

int main()
{
    int i;
    char temp[100];

    printf("Enter the expression: ");
    scanf("%s", temp);

    pos = 0;

    for (i = 0; temp[i] != '\0'; i++)
    {
        if (isalpha(temp[i]))
        {
            input[pos++] = 'i';
            input[pos++] = 'd';
        }
        else
        {
            input[pos++] = temp[i];
        }
    }

    input[pos] = '\0';
    pos = 0;

    E();

    if (input[pos] == '\0')
    {
        printf("\nString is accepted.\n");
    }
    else
    {
        printf("\nString is rejected.\n");
    }

    return 0;
}
