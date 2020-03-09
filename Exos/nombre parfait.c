#include <stdio.h>

int nombre_parfait(int n){
    int x = n / 2, r = 0;
    while (x > 0 && r < n)
    {
        if (n % x == 0)
            r += x;
        x--;
    }
    return (x == 0 && r == n);
}

int main()
{
    int nb;

    for (nb = 1; nb <= 10000; nb++)
        if (nombre_parfait(nb))
            printf("%d\n", nb);

    return 0;
}