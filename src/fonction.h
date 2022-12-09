#ifndef __FONCTION_H__
#define __FONCTION_H__

#define X 5  //entier entre 0 et 7917 l'indice du logement x
#define N 7917
#define K 10





typedef struct Logement{
    int blank;
    int accomodates;
    int bedrooms;
    int bathrooms;
    int beds;
    int price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews; 
}Logement;



typedef struct Distance{
    int id;
    int distance;
}Distance;

typedef struct Logement2{ //La structure logement en prenant en compte les modifs de la question d/
    int blank;
    int accomodates;
    int bedrooms;
    int bathrooms;
    int beds;
    int price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;
    Distance d;
}Logement2;


void remplirTableau(Logement * tab);
void afficherTableau(Logement * tab);
void calculdistance(Logement * tab, Distance * tabDistance);
void MelangeTableau(Logement * tab);
void afficherDistance(Distance * tabDistance);
void permuter(Distance * a, Distance * b);
void triRapid(Distance * tabDistance,int first,int last);
float MoyTableau(int tab[K]);
float PrixPredit(Logement * tab,Distance * tabDistance,int k);

void run(Logement * tab,Distance * tabDistance);

//Qustion d
void calculdistance2(Logement2 * tab2);
void triRapid2(Logement2 * tab2,int first,int last);
void permuter2(Logement2 * a, Logement2 * b);
float PrixPredit2(Logement2 * tab2,int k);
void remplirTableau2(Logement2 * tab);
void MelangeTableau2(Logement2 * tab2);

void run2(Logement2 * tab2);


#endif