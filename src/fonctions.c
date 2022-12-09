#include "fonction.h"
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>




void remplirTableau(Logement * tab){
        FILE *fichier;
        char tampon[BUFSIZ];
        int actuel = 0;
        int c;
        int j=0;
        int i=0;
        int n;
        signed char txt[256];
        
 
 
        fichier = fopen ("airbnb_donnees_propre.csv", "r");
        if (!fichier) {
                printf("Erreur fichier\n");
        }
        fgets(txt,255,fichier);   // supprime la première ligne qui contient le nom des colonnes et nous est donc inutile
        while(fgets(txt,255,fichier)!=NULL){
            char *p = strtok(txt, ",");
            while(p != NULL){
                n=atoi(p);
                if(j==0){
                    tab[i].blank = n;
                }
                if(j==1){
                    tab[i].accomodates = n;
                }
                if(j==2){
                    tab[i].bedrooms = n;
                }
                if(j==3){
                    tab[i].bathrooms = n;
                }
                if(j==4){
                    tab[i].beds = n;
                }
                if(j==5){
                    tab[i].price = n;
                }
                if(j==6){
                    tab[i].minimum_nights = n;
                }
                if(j==7){
                    tab[i].maximum_nights = n;
                }
                if(j==8){
                    tab[i].number_of_reviews = n;
                }
                p = strtok(NULL, ",");
                j+=1;
            }
            i+=1;
            j=0;


        }
 
        fclose (fichier);
}


void afficherTableau(Logement * tab){
    for(int i=0;i<7917;i++){
        printf("%d,",tab[i].blank);
        printf("%d,",tab[i].accomodates);
        printf("%d,",tab[i].bedrooms);
        printf("%d,",tab[i].bathrooms);
        printf("%d,",tab[i].beds);
        printf("%d,",tab[i].price);
        printf("%d,",tab[i].minimum_nights);
        printf("%d,",tab[i].maximum_nights);
        printf("%d\n",tab[i].number_of_reviews);
    }

}



void calculdistance(Logement * tab, Distance * tabDistance){
    int distance=0;
    int blank;
    int accomodates;
    int bedrooms;
    int bathrooms;
    int beds;
    int price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;
    Logement x =tab[X];
    for(int i=0;i<7917;i++){
        blank=pow(x.blank-tab[i].blank,2);
        accomodates=pow(x.accomodates-tab[i].accomodates,2);
        bedrooms=pow(x.bedrooms-tab[i].bedrooms,2);
        beds=pow(x.beds-tab[i].beds,2);
        price=pow(x.price-tab[i].price,2);
        minimum_nights=pow(x.minimum_nights-tab[i].minimum_nights,2);
        maximum_nights=pow(x.maximum_nights-tab[i].maximum_nights,2);
        number_of_reviews=pow(x.number_of_reviews-tab[i].number_of_reviews,2);
        bathrooms=pow(x.bathrooms-tab[i].bathrooms,2);
        distance=sqrt(blank+accomodates+bedrooms+beds+price+minimum_nights+maximum_nights+number_of_reviews+bathrooms);
        tabDistance[i].id=i;
        tabDistance[i].distance=distance;
    }
}

void MelangeTableau(Logement * tab){
    int r;
    Logement x;
    for(int i=0;i<7917;i++){
        srand( time( NULL ) );
        r=rand()%7917; //nombre aléatoire entre 0 et 7916
        x=tab[i];
        tab[i]=tab[r];
        tab[r]=x;
        
    }

}

void afficherDistance(Distance * tabDistance){
    for(int i=0;i<N;i++){
        printf("%d,%d\n",tabDistance[i].id,tabDistance[i].distance);
    }
}


void permuter(Distance * a, Distance * b) {
    Distance tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}



void triRapid(Distance * tabDistance,int first,int last) {   
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tabDistance[i].distance <= tabDistance[pivot].distance && i < last)
                i++;
            while(tabDistance[j].distance > tabDistance[pivot].distance)
                j--;
            if(i < j) {
                permuter(&tabDistance[i], &tabDistance[j]);
            }
        }
        permuter(&tabDistance[pivot], &tabDistance[j]);
        triRapid(tabDistance, first, j - 1);
        triRapid(tabDistance, j + 1, last);
    }
}



float MoyTableau(int tab[K]){
    float x=0;
    for(int i=0;i<K;i++){
        x+=tab[i];
    }
    x=x/K;
    return x;
}



float PrixPredit(Logement * tab,Distance * tabDistance,int k){ //Prédiction du prix de logement en compte les k plus proche logement
    int Prix[k];
    if(k<N){
        for(int i=0;i<k;i++){
        for(int j=0;j<N;j++){
            if(tabDistance[i].id==j){
                Prix[i]=tab[j].price;
            }
        }
        }
        return MoyTableau(Prix);
    }else{
        printf("Erreur k doit être plus petit que %d",N);
    }
}



void run(Logement * tab,Distance * tabDistance){
    remplirTableau(tab); 
    MelangeTableau(tab);
    calculdistance(tab,tabDistance);
    triRapid(tabDistance,0,N-1);
    printf("Le prix prédit pour K=%d est :%f\n",K,PrixPredit(tab,tabDistance,K));
}





/*----------------------------------------------------------------------------------------------------------*/


//En prenant en compte les modifications de la question d

void remplirTableau2(Logement2 * tab){
        FILE *fichier;
        char tampon[BUFSIZ];
        int actuel = 0;
        int c;
        int j=0;
        int i=0;
        int n;
        signed char txt[256];
        
 
 
        fichier = fopen ("airbnb_donnees_propre.csv", "r");
        if (!fichier) {
                printf("Erreur fichier\n");
        }
        fgets(txt,255,fichier);   // supprime la première ligne qui contient le nom des colonnes et nous est donc inutile
        while(fgets(txt,255,fichier)!=NULL){
            char *p = strtok(txt, ",");
            while(p != NULL){
                n=atoi(p);
                if(j==0){
                    tab[i].blank = n;
                }
                if(j==1){
                    tab[i].accomodates = n;
                }
                if(j==2){
                    tab[i].bedrooms = n;
                }
                if(j==3){
                    tab[i].bathrooms = n;
                }
                if(j==4){
                    tab[i].beds = n;
                }
                if(j==5){
                    tab[i].price = n;
                }
                if(j==6){
                    tab[i].minimum_nights = n;
                }
                if(j==7){
                    tab[i].maximum_nights = n;
                }
                if(j==8){
                    tab[i].number_of_reviews = n;
                }
                p = strtok(NULL, ",");
                j+=1;
            }
            i+=1;
            j=0;


        }
 
        fclose (fichier);
}



void calculdistance2(Logement2 * tab2){
    int distance=0;
    int accomodates;
    int bedrooms;
    int beds;

    Logement x ={tab2[X].blank,tab2[X].accomodates,tab2[X].bedrooms,tab2[X].bathrooms,tab2[X].beds,tab2[X].price,tab2[X].minimum_nights,tab2[X].maximum_nights,tab2[X].number_of_reviews};
    for(int i=0;i<7917;i++){
        accomodates=pow(x.accomodates-tab2[i].accomodates,2);
        bedrooms=pow(x.bedrooms-tab2[i].bedrooms,2);
        beds=pow(x.beds-tab2[i].beds,2);
        
        distance=sqrt(accomodates+bedrooms+beds);
        tab2[i].d.id=i;
        tab2[i].d.distance=distance;
    }
}

void MelangeTableau2(Logement2 * tab2){
    int r;
    Logement2 x;
    for(int i=0;i<7917;i++){
        srand( time( NULL ) );
        r=rand()%7917; //nombre aléatoire entre 0 et 7916
        x=tab2[i];
        tab2[i]=tab2[r];
        tab2[r]=x;
        
    }

}


void permuter2(Logement2 * a, Logement2 * b) {
    Logement2 tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}





void triRapid2(Logement2 * tab2,int first,int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab2[i].d.distance <= tab2[pivot].d.distance && i < last)
                i++;
            while(tab2[j].d.distance > tab2[pivot].d.distance)
                j--;
            if(i < j) {
                permuter2(&tab2[i], &tab2[j]);
            }
        }
        permuter2(&tab2[pivot], &tab2[j]);
        triRapid2(tab2, first, j - 1);
        triRapid2(tab2, j + 1, last);
    }
}


float PrixPredit2(Logement2 * tab2,int k){
    int Prix[k];
    if(k<N){
        for(int i=0;i<k;i++){
        Prix[i]=tab2[i].price;
        }
        return MoyTableau(Prix);
    }else{
        printf("Erreur k doit être plus petit que %d",N);
    }
}



void run2(Logement2 * tab2){    //run en prenant en compte les modif de la question d
    remplirTableau2(tab2); 
    MelangeTableau2(tab2);

    calculdistance2(tab2);
    triRapid2(tab2,0,N-1);
    printf("Le prix prédit pour K=%d est :%f\n",K,PrixPredit2(tab2,K));

}

