#include <stdio.h>
#include <math.h>

extern int CODE[4];


typedef struct
{
    int rouge, blanc;
} REPONSE;

typedef struct
{
    int couleur;
    int position;
} BOULE;

typedef struct 
{
    BOULE boule[4];
    REPONSE reponse;
} TENTATIVE;


// typedef struct
// {
//     int proposition;
//     REPONSE reponse;
// } TENTATIVE;

// void codifier(int code, int t[4])
// {
//     int i;
//     for (i = 0; i < 4; i++)
//         {
//             t[i] = code / (1000 / (int) (pow(i, 10)));
//             code = code % (1000 / (int) pow(i, 10));
//         }    
// }

int reponseTrouveeTableau(TENTATIVE tentative)
{
    int i;
    for (i = 0; i < 4; i++)
        if (tentative.boule[i].couleur != CODE[tentative.boule[i].position])
            break;
    return i == 4;
}

// int reponseTrouvee(TENTATIVE tentative)
// {
//     return tentative.proposition == CODE;
// }

void evaluationTentative(TENTATIVE tentativeCourante)
{
    int t[4];
    
    for (int i = 0; i < 4; i++)
        t[tentativeCourante.boule[i].position] = tentativeCourante.boule[i].couleur;
    
    for (int i = 0; i < 4; i++)
        printf("%d", t[i]);

    printf("bien placée : ");
    scanf("%d", tentativeCourante.reponse.rouge);
    

    printf("bonne couleur : ");
    scanf("%d", tentativeCourante.reponse.blanc);
}

void nouvelleTentative(TENTATIVE *tentativeCourante, TENTATIVE *tentativePrecedente)
{
    int i;

    TENTATIVE nouvelleTentative;

    for (i = tentativeCourante->reponse.blanc + tentativeCourante->reponse.rouge; i < 4; i++)
        nouvelleTentative.boule[i]

    tentativePrecedente = tentativeCourante;
    tentativeCourante = &nouvelleTentative;
}


int main()
{
    int tentatives, code;
    TENTATIVE tentativeCourante, tentativePrecedente;
    
    printf("Votre code?");
    scanf("%d", code);

    codifier(code, CODE);

    tentativePrecedente.proposition = 9999;
    tentativePrecedente.reponse.blanc = 0;
    tentativePrecedente.reponse.rouge = 0;
    tentativeCourante.proposition = 0;


    tentatives = 0;
    while (tentatives < 8 && !reponseTrouveeTableau(tentativeCourante))
    {
        evaluationTentative(tentativeCourante);
        nouvelleTentative(&tentativeCourante, &tentativePrecedente);
    }
    return 0;
}