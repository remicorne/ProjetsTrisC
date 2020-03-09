#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{
    int i=0;
    clock_t t1, t2;
    srand((int)clock());
    t1 = clock();
    for (i=0 ; i<10000 ; i++)
        {
        printf("nombre numero %d : %d\n", i, rand()%100);
        t2 = clock();
        }
    printf("temps (en secondes) pour le tirage de ces 10000 nombres aleatoires (compris entre 1 et 100) = %.3f\n", (float)(t2 - t1) / CLOCKS_PER_SEC);
}