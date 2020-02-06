#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int main()
{
    int t[MAX], n, i, p, m;

    printf("Un entier?\n");
    scanf("%d", &n);

    for (i = 1; i < n; i++)
        t[i] = i + 1;
    t[0] = 0;

    p = 0;
    for (i = 0; i < n; i++)
        if (t[i] != 0)
        {
            m = i + t[i];
            while (m < n)
            {
                t[m] = 0;
                m += t[i];
            }
            t[p] = t[i];
            p++;
        }
    for (i = 0; i < p; i++)
        printf("%d ", t[i]);
    printf("\n");

}
