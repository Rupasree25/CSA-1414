#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char filename[50];
    char ch;
    int characters = 0;
    int words = 0;
    int lines = 0;
    int inword = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Unable to open the file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
        {
            inword = 0;
        }
        else if (inword == 0)
        {
            words++;
            inword = 1;
        }
    }

    fclose(fp);

    printf("\nNumber of Characters = %d", characters);
    printf("\nNumber of Words      = %d", words);
    printf("\nNumber of Lines      = %d\n", lines);

    return 0;
}
