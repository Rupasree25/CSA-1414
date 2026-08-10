#include <stdio.h>
#include <string.h>

#define MAX 50

struct Symbol
{
    char name[30];
    char type[20];
    char value[30];
};

struct Symbol table[MAX];
int count = 0;

void insert()
{
    if (count >= MAX)
    {
        printf("\nSymbol table is full!\n");
        return;
    }

    printf("\nEnter symbol name: ");
    scanf("%s", table[count].name);

    printf("Enter symbol type: ");
    scanf("%s", table[count].type);

    printf("Enter symbol value: ");
    scanf("%s", table[count].value);

    count++;

    printf("\nSymbol inserted successfully.\n");
}

void display()
{
    int i;

    if (count == 0)
    {
        printf("\nSymbol table is empty.\n");
        return;
    }

    printf("\n-------------------------------\n");
    printf("Name\t\tType\t\tValue\n");
    printf("-------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%s\t\t%s\t\t%s\n",
               table[i].name,
               table[i].type,
               table[i].value);
    }

    printf("-------------------------------\n");
}

void search()
{
    char name[30];
    int i, found = 0;

    printf("\nEnter symbol to search: ");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            printf("\nSymbol found!\n");
            printf("Name  : %s\n", table[i].name);
            printf("Type  : %s\n", table[i].type);
            printf("Value : %s\n", table[i].value);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nSymbol not found.\n");
}

void deleteSymbol()
{
    char name[30];
    int i, j, found = 0;

    printf("\nEnter symbol to delete: ");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            for (j = i; j < count - 1; j++)
            {
                table[j] = table[j + 1];
            }

            count--;
            found = 1;

            printf("\nSymbol deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("\nSymbol not found.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== SYMBOL TABLE =====");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Search");
        printf("\n4. Delete");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteSymbol();
                break;

            case 5:
                printf("\nProgram terminated.\n");
                return 0;

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}
