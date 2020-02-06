#include <stdio.h>

void exercice1()
{
    int e, t[100], n, i;

    printf("entier?\n");
    scanf("%d", &e);
    
    i = 0;
    n = 0;

    while (e != 0)
    {
        t[i++] = e;
        scanf("%d", &e);

    }
    
    printf("il y a %d entiers dans le tableau :", n);
    while (n < i)
    {
        printf("%d", t[n++]);
    }


}

void exercice2()
{
    int e, t[100], n, i;

    printf("entier?");
    scanf("%d", &e);
    
    n = 0;
    while (e != 0)
    {
        i = 0;
        while (i < n && t[i] != e)
        {
            i++;
        }
        if (i == n)
        {
            t[i++] = e;
            n++;
        }
        scanf("%d", &e);        
    }
    
    printf("il y a %d entiers dans le tableau : ", n);
    i = 0;
    while (i < n)
    {
        printf("%d", t[i++]);
    }
}

void exercice3()
{
    char t[100], tc[100], c;
    int nbc, nb;

    printf("char?");
    scanf("%c", &c);
    while (c == ' ') scanf("%c", &c);
    nb = 0;
    while (c != '.')
    {
        nbc = 0;
        while (c != ' ' && c != '.')
        {
            tc[nbc] = c;
            nbc++;
            scanf("%c", &c);
        }
        if (nbc > nb)
        {
            nb = 0;
            while (nbc > nb)
            {
                t[nb] = tc[nb];
                nb++;
            }
        }
        while (c == ' ') scanf("%c", &c);
    }
    nbc = 0;
    while (nbc < nb)
    {
        printf("%c", t[nbc++]);
    }
    if (nb)
        printf("' est le plus long, il est de longueur %d\n", nb);
    else 
        printf("lol ya pas de mots gros\n");
} 

void exercice4()
{
    char t[100], c;
    int nb, lg, i;

    printf("char?");
    scanf("%c", &c);

    nb = 0;
    lg = 0;

    while (c == ' ') scanf("%c", &c);

    while (c != '.' && c != ' ')
    {
        t[lg] = c;
        lg++;
        scanf("%c", &c);
    }

    nb = lg ? 1 : 0;

    while (c != '.')
    {
        i = 0;
        while (i < lg && c == t[i])
        {
            i++;
            scanf("%c", &c);
        }
        if (i == lg && (c == ' ' || c == '.'))
            nb++;
        else if (c != '.') scanf("%c", &c);;
    }
    if (nb) printf("il y a %d fois le premier mot", nb);
    else printf("il y a %d mots %c", nb, c);
} 


int main()
{
    exercice4();
}