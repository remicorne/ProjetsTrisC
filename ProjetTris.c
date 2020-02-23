#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        pas = (pas - 1) / 3;
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

int main() // Changer les while en for la ou cest logique
{
    int t20[500], i;

    i = 0;
    srand(time(NULL));

    while (i < 20)
    {
        t20[i++] = rand() % 20;
        printf("%d ",t20[i - 1]);
    }

    printf("\n");
    Tri_Heap(t20, 20);

    i = 0;
    while (i < 20)
    {
        printf("%d ",t20[i++]);
    }

}