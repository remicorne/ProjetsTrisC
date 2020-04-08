#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX 1000

typedef int T;

typedef struct maillon
{
    T info;
    struct maillon *suivant;
} MAILLON;

typedef MAILLON *PTR;

typedef PTR FILE_T;

PTR NM(T info, PTR suivant)
{
    PTR maillon = malloc(sizeof(MAILLON)); //checker "invalid conversion from 'void*' to ..."
    assert(maillon != NULL);
    maillon->info = info;
    maillon->suivant = suivant;
    return maillon;
}

void creer_file(FILE_T *k)
{
    k = NULL;
}

int file_vide(FILE_T k)
{
    return k == NULL;
}

int enfiler(T e, FILE_T *k) 
{
    if (!file_vide(*k))
    {
        *k = NM(e, *k);
        return 1;   
    }
}

int defiler(FILE_T *k)
{
    PTR p, c = *k;
    while (c->suivant != NULL)
    {
        p = c;
        c = c->suivant;
    }
    p->suivant = NULL;
    free(c);
}

T premier(FILE_T k)
{
    assert(!file_vide(k));
}

int main()
{
    FILE_T f;
    creer_file(&f);
    T e = 10;
    
    enfiler(e, &f);
    e = 9;
    enfiler(e, &f);
    defiler(&f);
    printf("%d", f->info);
    // int reponse;

    // while (1)
    // {
    //     printf("Votre choix :\n1-Enfiler\n2-Defiler\n3-Premier element\n");
    //     scanf("%d", &reponse);
    //     switch (reponse)
    //     {
    //     case 1:
    //         printf(file_vide(f));
    //     case 2:
    //         T e;
    //         printf("element : ");
    //         scanf("%d", &e);
    //         if (!enfiler(e, &f)) printf("%d ajoute en pos %d", f.tab[f.d], f.d);
    //     case 3:
    //         /* code */
    //         break;

    //     case 0:
    //         break;
        
    //     default:
    //         break;
    //     }
    // }


    // }



}