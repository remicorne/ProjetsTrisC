#include <stdio.h>

void exercice1()
{
    int nb = 0;
    char cour, prem;

    printf("Char?\n");
    scanf("%c", &prem);

    cour = prem;

    while (cour != '.')
    {
        if (cour == prem)
            nb++;
        printf("Char?\n");
        scanf("%c", &cour);
    }
    printf("il y en a %d\n", nb);
}

void exercice2()
{
    int nb, lg, lgc;
    char c;

    printf("longueur?\n");
    scanf("%d", &lg);
    scanf("%c", &c);
    printf("la suite de car : ");
    nb = 0;

    scanf("%c", &c);

    while (c != '.')
    {
        lgc = 0;
        while (c != ' ' && c != '.')
        {
            lgc++;
            scanf("%c", &c);
        }
        if (lgc == lg)
        {
            nb++;
        }
        if (lgc == 0)
        {
            scanf("%c", &c);
        }
    }
    printf("il y en a %d de longueur %d\n", nb, lg);
}

void exercice3()
{
    int nb, lg, lgc;
    char c;

    printf("suite de car ?\n");
    scanf("%c", &c);
    
    lg = 0;

    while (c == ' ') scanf("%c", &c);

    while (c != '.' && c != ' ')
    {
        lg++;
        scanf("%c", &c);
    }
    
    nb = lg ? 1 : 0;
    
    while (c != '.')
    {
        lgc = 0;
        while (c != ' ' && c != '.')
        {
            lgc++;
            scanf("%c", &c);
        }
        if (lgc == lg)
        {
            nb++;
        }
        if (lgc == 0)
        {
            scanf("%c", &c);
        }
    }
    if (lg != 0)
        printf("il y en a %d de meme longueur que le premier\n", nb);
    else printf("lol ya pas de mots");
}

int main()
{
    exercice3();

    return 0;
}