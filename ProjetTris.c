#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Tri_Insertion(int t[], int lg)
{
    int k = 1, j, temp;
    while (k < lg)
    {
        j = k;
        while (j > 0 && t[j] < t[j - 1])
        {
            temp = t[j];
            t[j] = t[j - 1];
            t[j - 1] = temp;
            j--;
        }
        k++;
    }
}

void Tri_Selection(int t[], int lg)
{
    int k = lg - 1, i, j, temp;
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
    }
}

void Tri_Bulles(int t[], int lg)
{
    int k = lg - 1, temp;
    while (k > 0)
    {
        while (i < kp)
    }
}

int main()
{
    int t500[500], i;

    i = 0;
    srand(time(NULL));

    while (i < 10)
    {
        t500[i++] = rand() % 10;
        printf("%d ", t500[i-1]);
    }

    printf("\n");
    Tri_Selection(t500, 10);

    i = 0;
    while (i < 10)
    {
        printf("%d ", t500[i++]);
    }

}