/* lire un nombre n entier impair, afficher le carré magique d'ordre n
carré magique : sommeColonne = sommeLigne = sommeDiagonale
1 - quand on a un carré d'ordre n, on va le remplir successivement par le valeurs [1 - n^2]
2 - quelquesoit k compris en 2 et n^2, k dépend de k-1
3 - la place du 1 c'est la place au dessus du centre
4 - regle NE : je décale d'un cran au nord est a partir de k
    si case libre, je met k + 1 dedans

    si case occupée, on enchaine avec NO, on met k + 1 dedans, puis on reprend avec NE

    (pour répondre à cette question il faut donc initialiser le carré avec des 0)
*/

#include <stdio.h>
#define MAX 1000

int deplacementNord (int l, int n){
    if (l == 0)
        return (n - 1);
    return (l - 1);
}

int deplacementOuest (int c, int n){
    if (c == n - 1)
        return 0;
    return c + 1;
}
int deplacementEst (int c, int n){
    if (c == 0)
        return n - 1;
    return c - 1;
}

int main()
{
    int t[MAX][MAX] = {0}, n, l, c, k;

    printf("n ?");
    scanf("%d", &n);

    c = n / 2;
    l = c - 1;
    t[l][c] = 1;

    for (k = 2; k <= n * n; k++)
    {
        l = deplacementNord(l, n);
        c = deplacementOuest(c, n);
        if (t[l][c] != 0){
            l = deplacementNord(l, n);
            c = deplacementEst(c, n);
        }
        t[l][c] = k;
    }

    for (l = 0; l < n; l++){
        for (c = 0; c < n; c++)
            printf("%2d ", t[l][c]);
        printf("\n");
    }
    
    int sum = 0;
    for (c = 0; c < n; c++)
        sum += t[0][c];
    
    printf("\nsomme de la premier ligne = %d\n", sum);

    int sumLigne = 0;
    int sumColonne = 0;
 
    for (l = 0; l < n; l++)
    {
        for (c = 0; c < n; c++)
        {
            sumColonne += t[c][l];
            sumLigne += t[l][c];
        }
        if (sum != sumColonne || sumColonne != sumLigne)
            {
                printf("Faux\n");
                return 0;
            }
        sumColonne = 0;
        sumLigne = 0;
    }
    printf("C'est good\n");
    return 0;
}
