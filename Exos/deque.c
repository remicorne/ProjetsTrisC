#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX 1000
#define GAUCHE 0
#define DROITE 1


typedef int T;
typedef struct 

{
    T tab[MAX];
    int d, nb;7
} DEQUE_T;

int indice_extremite(int sens, DEQUE_T k)
{
    return k.d + ((k.nb - 1) * sens);
}

void creer_deque(DEQUE_T *k)
{
    k->nb = 0;
    k->d = 0;
}

int deque_vide(DEQUE_T k)
{
    return k.nb == 0;
}

int endequer(int sens, T e, DEQUE_T *k)
{
    if (k->nb == MAX) 
        return 0;
        
    int i = ((k->nb + 1) * sens) - 1;
    k->tab[indice_extremite(sens, *k) + (2 * sens - 1)] = e;
    k->d += sens - 1;
    k->nb++;
    return 1;
}

int dedequer(int sens, DEQUE_T *k)
{
    if (deque_vide(*k))
        return 0;
    
    k->d += 1 - sens;
    k->nb--;
    return 1;
}

T extremite(int sens, DEQUE_T k)
{
    assert(!deque_vide(k));
    return k.tab[indice_extremite(sens, k)];
}

int main()
{
    DEQUE_T f;
    creer_deque(&f);
    T e = 10;

    endequer(DROITE, e++, &f);
    endequer(DROITE, e++, &f);
    endequer(DROITE, e++, &f);
    endequer(DROITE, e++, &f);
    endequer(DROITE, e++, &f);

    for (int i = f.d; i < f.d + f.nb; i++)
    {
        printf("%d ", f.tab[i]);
    }
    printf("\n");
        
    dedequer(DROITE, &f);
    for (int i = f.d; i < f.d + f.nb; i++)
    {
        printf("%d ", f.tab[i]);
    }
    printf("\n");

    dedequer(GAUCHE, &f);
    for (int i = f.d; i < f.d + f.nb; i++)
    {
        printf("%d ", f.tab[i]);
    }
    
}