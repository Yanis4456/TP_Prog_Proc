# TP_Prog_Proc
TP du binôme Yanis Aissaoui et Nicolas Ussont à rendre pour le 10 décembre


Introduction:  

Afin d'exécuter ce programme on se servira de la commande make pour compiler puis make run pour exécuter   



__ Sujet1 __

Partie 1

a/  
Afin de calculer la distance de similarité du logement x avec chaque logement du fichier airbnb_donnees_propores.csv on initialiserale un type structure contenant les caractéristiques d'un logement et un logement x avec des caractéristiques aléatoire excepté pour le prix que nous tâcherons de déterminer ces distances seront stockés dans une structure de type Distance contenant l'id du logement et sa distance au logement x.  

Le calcul de la distance à un logement y se fera par la formule donnée dans l'énoncé avec les xi et yi les caractéristiques respective du logement x et y  



b/
afin de randomiser le tableau nous parcourerons la liste en permutant chaque élément avec un élément aléatoire de la liste.  
Quand au tri nous choisissons le tri rapide car comme son nom l'indique il est en moyenne plus rapide que les autres vu en cours.  

c/   
Après avoir trié le tableau de distance il suffit de stocker dans un tableau les prix des logement dont l'indice est égal à celui de l'indice des k premiers éléments du tableau de distance puis de calculer la moyenne de ces éléments.

d/  
D'après l'énoncé nous modifions la structure logement afin d'y ajouter directement la structure distance ce qui permet des calculs plus aisés notament de pour celui de la distance
