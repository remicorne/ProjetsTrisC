#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX 1000

typedef int T;

typedef struct noeud
{
    T info;
    struct noeud *fg, *fd;
} NOEUD;

typedef NOEUD *ARBRE;

ARBRE NN(ARBRE fg, ARBRE fd)
{
    ARBRE arbre = (ARBRE)malloc(sizeof(NOEUD));
    assert(arbre != NULL);
    arbre->fg = fg;
    arbre->fd = fd;
    return arbre;
}

int taille(ARBRE arbre)
{
    int tg = 0, td = 0;
    if (arbre->fg == NULL && arbre->fd == NULL )
        return 0;
    if (arbre->fg != NULL) tg = taille(arbre->fg);
    if (arbre->fd != NULL) td = taille(arbre->fd);
    return tg + td + 1;
}

int feuilles(ARBRE arbre)
{
    int fg = 0, fd = 0;
    if (arbre->fg == NULL && arbre->fd == NULL)
        return 1;
    if (arbre->fg != NULL) fg = feuilles(arbre->fg);
    if (arbre->fd != NULL) fd = feuilles(arbre->fd);
    return fg + fd;
}

int hauteur(ARBRE arbre)
{
    int hg = -1, hd = -1, hmax = -1;
    if (arbre->fg == NULL && arbre->fd == NULL)
        return -1;
    if (arbre->fg != NULL) hg = hauteur(arbre->fg);
    if (arbre->fd != NULL) hd = hauteur(arbre->fd);
    hmax = hg > hd ? hg : hd;
    return hmax + 1;
}

int main()
{
    ARBRE arbre = NN(NN(NULL, NULL), NN(NN(NN(NULL, NULL), NULL), NN(NN(NN(NULL, NULL), NN(NULL, NN(NULL, NULL))), NN(NULL, NN(NULL, NULL)))));
    printf("taille = %d\n", taille(arbre));
    printf("hauteur = %d\n", hauteur(arbre));
    printf("nombre feuilles = %d\n", feuilles(arbre));
}