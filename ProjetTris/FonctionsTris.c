#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimer_Tableau(int t[], int lg)
{
    for (int i = 0; i < lg; i++)
    {
        printf("%d ", t[i]);
    }
}

void Init_Tab(int t[], int lg)
{
    srand((int)clock());
    
    for (int i = 0; i < lg; i++)
        t[i] = rand() % 100;
}

void Copier_Tab(int t[], int copie[], int lg)
{
    for (int i = 0; i < lg; i++)
        copie[i] = t[i];
}

int Tri_Reussi(int t[], int lg)
{
    for (int i = 0; i + 1 < lg; i++)
        if (t[i] > t[i + 1])
        {
            printf("echec\n");
            Imprimer_Tableau(t, lg);
            exit(1);
        }
    return 1;
}

void Tri_Insertion(int t[], int lg) 
{
    int k, j, temp;

    for (k = 1; k < lg; k++)
    {
        j = k;
        temp = t[k];
        while (j > 0 && temp < t[j - 1])
        {
            t[j] = t[j - 1];
            j--;
        }
        t[j] = temp;
    }
}

void Tri_Insertion_Dichotomie(int t[], int lg) 
{
    int k, j, i, temp;
    for (k = 1; k < lg; k++)
    {
        j = k;
        temp = t[k];
        i = 0;
        while (j > 0 && (temp > t[j] || temp < t[j - 1]))
        {
            if (temp > t[j])
            {
                j = 1 + (i + j) / 2;
                i = j;
            }
            if (temp < t[j - 1])
                j = (i + j) / 2;
        }
        for (i = k; i > j; i--)
        {
            t[i] = t[i - 1];
        }
        t[j] = temp;
    }
}

void Tri_Selection(int t[], int lg)
{
    int k, i, j, temp;
    for (k = lg - 1; k > 0; k--)
    {
        j = k;
        for (i = j - 1; i >= 0; i--)
        {
            if (t[i] > t[j])
            {
                j = i;
            }
        }
        temp = t[k];
        t[k] = t[j];
        t[j] = temp;
    }
}

void Tri_Bulles(int t[], int lg)
{
    int k = lg - 1, kp, i, temp;
    while (k > 0)
    {
        kp = 0;
        for (i = 0; i < k; i++)
        {
            if (t[i] > t[i + 1])
            {
                temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
                kp = i + 1;
            }
        }
        k = kp;
    }
}

void Tri_Shake(int t[], int lg)
{
    int kmax = lg - 1, kmin = 0, kp, i, temp;
    while (kmin != kmax)
    {
        kp = kmin;
        for (i = kmin; i < kmax; i++)
        {
            if (t[i] > t[i + 1])
            {
                temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
                kp = i + 1;
            }
        }
        kmax = kp;

        for (i = kmax; i > kmin; i--)
        {
            if (t[i] < t[i - 1])
            {
                temp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = temp;
                kp = i - 1;
            }
        }
        kmin = kp;
    }
}

void Tri_Shell(int t[], int lg)
{
    int pas, k, j, it, temp;
    int count = 0;
    
    for (pas = 1; pas < lg; pas = 3 * pas + 1);
    
    pas = (pas - 1) / 3;

    for (pas; pas >= 1; pas = (pas - 1) / 3)
    {
        it = 0;
        while (it < pas && pas + it < lg)
        {
            for (k = pas + it; k < lg; k = k + pas)
            {
                j = k;
                temp = t[k];
                while (j - pas >= 0 && temp < t[j - pas])
                {
                    t[j] = t[j - pas];
                    j = j - pas;
                }
                t[j] = temp;
            }
            it++;
        }
    }
}

void placer(int g, int d, int *T)
{
    int i, j, x, place_trouvee;
    x = T[g];
    i = g;
    j = 2 * g + 1;
    place_trouvee = 0;

    while ((j <= d) && !(place_trouvee))
    {
        if (j < d)
            if (T[j + 1] > T[j])
                j = j + 1;
        if (x >= T[j])
            place_trouvee = 1;
        else
        {
            T[i] = T[j];
            i = j; 
            j = 2 * i + 1;
        }
    }
    T[i] = x;
}

void Tri_Heap(int t[], int lg)
{
    int g, d = lg - 1, temp;

    for (g = lg / 2 - 1; g > 0; g--) // on s'arrete avant de mettre le premier à sa place
    {
        placer(g, d, t);
    }

    for (d = lg - 1; d > 0; d--) // on part du principe que la manip demarre avec le premier mal placé
    {
        placer(0, d, t);
        temp = t[0];
        t[0] = t[d];
        t[d] = temp;
    }
}

void Recursivite_Quick(int t[], int g, int d)
{
    int p = (t[g] + t[d]) / 2;
    int k1 = g, k2 = d, temp;

    while (k1 < k2) //tant que les indices ne se sont pas croisés
    {
        if (t[k1] > p && t[k2] <= p) // on echange t[k1] et t[k2] pour les mettre a leur place s'ils sont du mauvais coté de p
        {
            temp = t[k1];
            t[k1] = t[k2];
            t[k2] = temp;
        }
        while (k1 < d && t[k1] <= p) //on fait avancer k1 jusqta ce que t[k1] soit une valeur mal placéé
            k1++;
        while (k2 > g && t[k2] > p) // pareil pour k2
            k2--;
    }
    if (d - g < 2) // si le tableau est de taille 2 ou moins alors il a été trié
        return;
    Recursivite_Quick(t, g, k1 - 1);
    Recursivite_Quick(t, k2 + 1, d);
}

void Tri_Quick(int t[], int lg)
{
    Recursivite_Quick(t, 0, lg - 1);
}

