#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX 1000

typedef int T;

typedef struct maillon
{
    T info;
    struct maillon *gauche, *droit;
} MAILLON;

typedef MAILLON *PTR;

typedef struct
{
    PTR gauche, droit;
} DEQUE_T;
