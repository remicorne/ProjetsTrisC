#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX 1000

typedef int T;
typedef struct 
{
    T tab[MAX];
    int d, f, nb;
} FILE_T;

void creer_file(FILE_T *k)
{
    k->nb = 0;
    k->d = 0;
    k->f = k->d - 1;
}

int file_vide(FILE_T k)
{
    return k.nb == 0;
}

int enfiler(T e, FILE_T *k)
{
    if (k->nb == MAX) 
        return 0; 
    
    k->f = (k->f + 1) % (MAX);
    k->tab[k->f] = e;
    k->nb++;
    return 1;
}

int enfilerbis(T e, FILE_T k)
{
    if (k.nb == MAX) 
        return 0; 
    
    k.f = (k.f + 1) % (MAX);
    k.tab[k.f] = e;
    k.nb++;
    return 1;
}

int defiler(FILE_T *k)
{
    if (file_vide(*k))
        return 0;
    
    k->d = (k->d + 1) % (MAX);
    k->nb--;
    return 1;
}

T premier(FILE_T k)
{
    assert(!file_vide(k));
    return k.tab[k.d];
}

int main()
{
    FILE_T f;
    creer_file(&f);
    T e = 10;
    enfiler(e, &f);
    printf("%d", f.tab[f.d]);
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