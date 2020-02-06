#include <stdio.h>

int exercice1()
{
    int nb = 0;
    char c;

    printf("Char?\n");
    scanf("%c", &c)

    while (c != '.')
    {
        if (c == 'l')
            nb++;
        printf("Char?\n");
        scanf("%c", &c)
    }
    return nb; 
}

int exercice2()
{
    int nb = 0;
    char c;

    printf("Char?\n");
    scanf("%c", &c)

    while (c != '.')
    {
        if (c == 'l')
        {
            printf("Char?\n");
            scanf("%c", &c)
            if (c == 'e')
            {
                nb++;
                printf("Char?\n");
                scanf("%c", &c)
            }
        }
        else
        {
            printf("Char?\n");
            scanf("%c", &c)    
        }
    return nb; 
    }

int exercice4()
{
    int nb = 0;
    char p, c;

    p = ' '
    
    printf("Char?\n");
    scanf("%c", &c);

    while (c != '.')
    {
        if (p == 'l' && c == 'e')
            nb++
        p = c;
        printf("Char?\n");
        scanf("%c", &c);
    }
}

int exercice6()
{
    int nb = 0;
    char c;

    printf("Char?\n");
    scanf("%c", &c);

    while (c == ' ')
        printf("Char?\n");
        scanf("%c", &c);

    while (c != '.')
    {
        nb++
        printf("Char?\n");
        scanf("%c", &c);
        while (c != ' ' && c != '.')
        {
            printf("Char?\n");
            scanf("%c", &c);
        }
        while (c == ' ')
        {
            printf("Char?\n");
            scanf("%c", &c);
        }
            printf("Char?\n");
            scanf("%c", &c);
    }
}


int main()
{

}