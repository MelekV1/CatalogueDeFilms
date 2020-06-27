#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define Max 50


typedef struct/* une structure qui definie trois principaux acteurs dans le film*/
{
    char a1[Max];
    char a2[Max];
    char a3[Max];
}principaux;

typedef struct/*description brève du film (categorie, annee de sortie, resume )*/
{
    char categorie[Max];
    char resume[2*Max];
    int sortie;
}fdata;

typedef struct/*definition type film */
{
    char titre[Max];
    char realisateur[Max];
    principaux list_acteurs;
    fdata description;
}film;

typedef struct element/*Definition dynamique liste chainée */
{
    film *fiche;
    struct element *succ;
}element;

 typedef struct catalogue /* catalogue a base liste chaineé*/
 {
    element *tete;
 }catalogue;

typedef enum/*typed boolean pour faciliter les test d'existance */
{
    false,
    true
}bool;

film *creer_film(void);/*Créer une fiche d’un film*/

void afficher_film(film f);/*affichage des informations d'une fiche de film*/

void modifier_film(film *f);/*modifier les informations d'un film */

element *initelement(film *f,element *next);/*initializer un element du liste chaineé*/

catalogue *initcatalogue(element *premier);/*initializer un catalogue*/

void affiche_catalogue(catalogue *book );/*Affichage d'une liste chainée*/

void ajouter_film(catalogue *book, film *f);/*ajout d'un fiche dans le catalogue */

int longeur(catalogue *book);/*calcule le nombre de film qu'un catalogue donnee contient */

film *recherche_titre(catalogue *book);/*Rechercher les films d’une catégorie donnée*/

catalogue *recherche_categorie(catalogue *book);/*Rechercher les films d’une catégorie donnée */

catalogue *recherche_motcle(catalogue *book);/*Rechercher un film dans le catalogue par la donnée d'un mot-clé*/

catalogue *tri(catalogue *book);/*tri du catalogue*/

bool exist(catalogue *book, film *f);/*test sur l'existance d'un film dans un catalogue*/

void supprimer_film(catalogue *book,film *fiche);/*suppression d'un film du catalogue*/
int menu5();
int menu4();
int menu3();
int menu();
int menu2();
#endif // HEADER_H_INCLUDED
