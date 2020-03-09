#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "FonctionsTris.c"

typedef void (*fPTR)(int t[], int lg);

typedef struct 
{
    char *nom;
    char *cout;
    float temps[2][3];
    fPTR fonction;
} RESULTAT;

float Effectuer_Tri(int copie[], int lg, fPTR fonction)
{
    clock_t t1, t2;

    t1 = clock();
    fonction(copie, lg);
    t2 = clock();

    if (Tri_Reussi(copie, lg))
        return (float)(t2 - t1) / CLOCKS_PER_SEC; 
}

int main()
{
    int t[TAILLEMAX], copie[TAILLEMAX], lg, tailles[] = {500, 1000, 10000};
    RESULTAT resultats[8];
    clock_t t1, t2;

    resultats[0].nom = "Tri par insertion";
    resultats[0].cout = "0(n^2)";
    resultats[0].fonction = &Tri_Insertion;

    resultats[1].nom = "Insertion dichotomie";
    resultats[1].cout = "0(n^2)";
    resultats[1].fonction = &Tri_Insertion_Dichotomie;
    
    resultats[2].nom = "Tri par selection";
    resultats[2].cout = "0(n^2)";
    resultats[2].fonction = &Tri_Selection;
    
    resultats[3].nom = "Tri a bulles";
    resultats[3].cout = "0(n^2)";
    resultats[3].fonction = &Tri_Bulles;
    
    resultats[4].nom = "Shake sort";
    resultats[4].cout = "0(n^2)";
    resultats[4].fonction = &Tri_Shake;
    
    resultats[5].nom = "Shell sort";
    resultats[5].cout = "0(n^1,2)";
    resultats[5].fonction = &Tri_Shell;
    
    resultats[6].nom = "Heap sort";
    resultats[6].cout = "0(n log n)";
    resultats[6].fonction = &Tri_Heap;
    
    resultats[7].nom = "Quick sort";
    resultats[7].cout = "0(n log n)";
    resultats[7].fonction = &Tri_Quick;

    for (int taille = 0; taille < 3; taille++) //initialisation du temps a 0
            for (int tri = 0; tri < 8; tri++)
                resultats[tri].temps[1][taille] = 0;


    for (int taille = 0; taille < 3; taille++)
    {
        lg = tailles[taille];
        for (int tableau = 0; tableau < 10; tableau++)
        {
            Init_Tab(t, lg);
            for (int tri = 0; tri < 8; tri++)
            {
                Copier_Tab(t, copie, lg);
                resultats[tri].temps[1][taille] += Effectuer_Tri(copie, lg, resultats[tri].fonction);
                if (tableau == 9) // apres le premier tri, on refait le tri sur le tableau trié 
                {
                    resultats[tri].temps[0][taille] = Effectuer_Tri(copie, lg, resultats[tri].fonction);
                    resultats[tri].temps[1][taille] /= 10; // On moyenne
                }
            }
        }
    }

    printf("|%22s |%12s | %19s             |  %30s  |\n", "", "", "trié", "désordonné (moyenne pour 10)");
    printf("|%22s |%12s |", "", "");
    for (int desord = 0; desord < 2; desord++)
                for (int taille = 0; taille < 3; taille++)
                    printf(" %6d   |", tailles[taille]);
    printf("\n|_______________________|_____________|__________|__________|__________|__________|__________|__________|\n");

    for (int tri = 0; tri < 8; tri++)
    {
        printf("|%22s |%12s |", resultats[tri].nom, resultats[tri].cout);
        for (int desord = 0; desord < 2; desord++)
        {
            for (int taille = 0; taille < 3; taille++)
                printf(" %8f |", resultats[tri].temps[desord][taille]);
        }
        printf("\n");
    }

    return 0;
    

}