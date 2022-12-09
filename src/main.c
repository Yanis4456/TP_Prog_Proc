#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#define X 5  //entier entre 0 et 7917 l'indice du logement x
#define N 7917
#define K 10
#include "fonction.h"


int main(void){
    Logement * tab = malloc(sizeof(Logement)*N);
    Logement2 * tab2 = malloc(sizeof(Logement2)*N);
    Distance * tabDistance = malloc(sizeof(Distance)*N);
    //run le code de la première partie du sujet1
    run(tab,tabDistance);
    //run le code en tenant compte des modifications de la dernière question
    run2(tab2);

    free(tab);
    free(tab2);
    free(tabDistance);
}




