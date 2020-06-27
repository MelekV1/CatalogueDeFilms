#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main()
{
    int choix_menu,choix_saisie,choix_affichage,choix_recherche,choix_modification;
    film *f=NULL,*fr=NULL , *fs=NULL , *f3=NULL ,*f4=NULL;
    catalogue *box_office=NULL;
    box_office=NULL;

/* Test Issue
    box_office=initcatalogue(NULL);
    f=creer_film();
    ajouter_film(box_office,f);
    affiche_catalogue(box_office);
*/
    do
    {
        fflush(stdin);
        choix_menu=menu();
        switch(choix_menu)
        {
        case 1:
            if(box_office)
            {
                do
                {
                    fflush(stdin);
                    choix_saisie=menu2();
                    switch(choix_saisie)
                {
                    case 1:
                        f=creer_film();
                        system("cls");
                        printf("\n=====Creation d'une fiche avec SUCCES======\n");
                        printf("Voici la fiche du film saisie : \n");       //affichage simple
                        afficher_film(*f);
                        break;

                    case 2:
                        if(f)
                        {
                            ajouter_film(box_office,f);
                            printf("\n==========Ajout termine=========\n");
                        }
                        else
                            printf("\n==========Rien n'ete saisie=====\n");
                        break;

                    case 3:
                        fr=recherche_titre(box_office);
                        if(fr)
                        {
                            printf("\n==========MODIFICATION EN COURS=============\n\n\n");
                            modifier_film(fr);
                        }
                        break;

                    case 0:
                        break;

                    default:
                        printf("\nCheck input please\n");
                        break;
                    }
                }while(choix_saisie!=0);
            }
            else
                printf("\n=====Veuillez initialiser un catalogue d'abord=========\n");
            break;

        case 2:
            if(box_office)
            {
                fs=recherche_titre(box_office);
                supprimer_film(box_office,fs);
            }
            else
                printf("\n=====Veuillez initialiser un catalogue d'abord=========\n");
            break;

        case 3:
            if(box_office)
            {
                do{
                    fflush(stdin);
                    choix_affichage=menu3();
                    switch(choix_affichage)
                    {
                      case 1:
                          f3=recherche_titre(box_office);
                          if(f3)
                            afficher_film(*f3);
                          break;
                      case 2:
                          affiche_catalogue(box_office);
                        break;
                      case 0:
                        break;
                      default:
                        printf("\nCheck input please\n");
                        break;
                    }
                }while(choix_affichage!=0);
            }
            else
                printf("\n=====Veuillez initialiser un catalogue d'abord=========\n");
            break;

        case 4:
            if(box_office)
            {
                do{
                    choix_recherche=menu4();
                    fflush(stdin);
                    switch(choix_recherche)
                    {
                        case 1:
                            affiche_catalogue(recherche_motcle(box_office));
                            break;
                        case 2:
                            affiche_catalogue(recherche_categorie(box_office));
                            break;
                        case 3:
                            f4=recherche_titre(box_office);
                            break;
                        case 4:
                            affiche_catalogue( tri(box_office) );
                            break;
                        case 0:
                            break;
                        default :
                            printf("\nCheck input please\n");
                            break;
                    }
                }while(choix_recherche!=0);
            }
            else
                printf("\n=====Veuillez initialiser un catalogue d'abord=========\n");
            break;

        case 5:
            if(box_office)
            {
                printf("\nGESTION DE FICHIER ...\n");
                free(box_office);
                box_office=NULL;

            }
            else
            {
                box_office=initcatalogue(NULL);
                printf("\n==========Votre Catalogue est initilise et pret a etre remplie===========\n");
            }
            break;

        case 0:
            break;

        default :
            printf("\nCheck input please\n");
            break;
        }
    }while(choix_menu!=0);

    printf("___________________________________________GOOD BYE___________________________________________\n");
    return 0;
}
