#include <stdio.h>

typedef struct maillon
{
    int valeur;
    struct maillon *suivant;
} MAILLON;

typedef MAILLON *PTR; 


int inverser(PTR *L)
{
    PTR p, c = *L;
    while (c != NULL)
    {
        p = c;
        c = c->suivant;
    }
    c = *L;
    p->suivant = NULL;
    *L = c; 
}

int main()
{


}