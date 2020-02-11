#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Tri_Insertion(int t[], int lg) // possibilité amélioration avec recherche dicho sur la partie triée
{
    int k = 1, j, temp;
    int count = 0;
    while (k < lg)
    {
        j = k;
        temp = t[k];
        while (j > 0 && temp < t[j - 1])
        {
            t[j] = t[j - 1];
            j--;
        }
        t[j] = temp;
        k++;
        count++;
    }
}

void Tri_Insertion_Dichotomie(int t[], int lg) 
{
    int k = 1, j, i, temp;
    int count = 0;
    while (k < lg)
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
        i = k;
        while (i > j)
        {
            t[i] = t[i - 1];
            i--;
        }
        t[j] = temp;
        k++;
        count++;
    }
}

void Tri_Selection(int t[], int lg)
{
    int k = lg - 1, i, j, temp;
    int count = 0;
    while (k > 0)
    {
        j = k;
        i = k - 1;
        while (i >= 0)
        {
            if (t[i] > t[j])
            {
                j = i;
            }
            i--;
        }
        temp = t[k];
        t[k] = t[j];
        t[j] = temp;
        k--;
        count++;
    }
}

void Tri_Bulles(int t[], int lg)
{
    int k = lg - 1, kp, i, temp;
    int count = 0;
    while (k > 0)
    {
        i = 0;
        kp = 0;
        while (i < k)
        {
            if (t[i] > t[i + 1])
            {
                temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
                kp = i + 1;
            }
            i++;
        }
        k = kp;
        count++;
    }
}

void Tri_Shake(int t[], int lg)
{
    int kmax = lg - 1, kmin = 0, kp, i, temp;
    int count = 0;
    while (kmin != kmax)
    {
        i = kmin;
        kp = kmin;
        while (i < kmax)
        {
            if (t[i] > t[i + 1])
            {
                temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
                kp = i + 1;
            }
            i++;
        }
        kmax = kp;

        i = kmax;
        kp = kmax;
        while (i > kmin)
        {
            if (t[i] < t[i - 1])
            {
                temp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = temp;
                kp = i - 1;
            }
            i--;
        }
        kmin = kp;
        count++;
    }
}

void Tri_Shell(int t[], int lg)
{
    int p = 1, k, j, it, temp;
    int count = 0;
    
    while (p < lg)
        p = 3 * p + 1;
    p = (p - 1) / 3;

    while (p >= 1)
    {
        it = 0;
        while (it < p)
        {
            k = p + it;
            while (k < lg)
            {
                j = k;
                temp = t[k];
                while (j >= p && temp < t[j - p])
                {
                    t[j] = t[j - p];
                    j = j - p;
                }
                t[j] = temp;
                k = k + p;
            }
            it++;
        }
        p = (p - 1) / 3;
    }
}

int main()
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
    Tri_Shell(t20, 20);

    i = 0;
    while (i < 20)
    {
        printf("%d ",t20[i++]);
    }

}