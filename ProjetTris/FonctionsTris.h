#ifndef HEADER_FILE
#define HEADER_FILE

#define TAILLEMAX 10000

void Imprimer_Tableau(int t[], int lg);
void Init_Tab(int t[], int lg);
void Copier_Tab(int t[], int copie[], int lg);
int Tri_Reussi(int t[], int lg);

void Tri_Insertion(int t[], int lg);
void Tri_Insertion_Dichotomie(int t[], int lg);
void Tri_Selection(int t[], int lg);
void Tri_Bulles(int t[], int lg);
void Tri_Shake(int t[], int lg);
void Tri_Shell(int t[], int lg);
void placer(int g, int d, int *T);
void Tri_Heap(int t[], int lg);
void Recursivite_Quick(int t[], int g, int d);
void Tri_Quick(int t[], int lg);


#endif