#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "header.h"
#define nalloc(n,t) (t *)malloc((n)*sizeof(t))
#define alloc(t) (t*)malloc(sizeof(t))

film *creer_film(void)
{
    film *f;
    f=alloc(film);
    fflush(stdin);
    printf("donner le titre du film : >>");
    scanf("%[^\n]s",f->titre);
    fflush(stdin);
    printf("\ndonner le realisateur du film : >>");
    scanf("%[^\n]s",f->realisateur);
    printf("\ndonner les noms des principaux 3 acteurs du '%s' :",f->titre);
    fflush(stdin);
    printf("\n>>");
    scanf("%s",f->list_acteurs.a1);
    fflush(stdin);
    printf("\n>>");
    scanf("%s",f->list_acteurs.a2);
    fflush(stdin);
    printf("\n>>");
    scanf("%s",f->list_acteurs.a3);
    fflush(stdin);
    printf("\nDescription du film\n ");
    printf("\nveuillez specifier la categorie du film :>>");
    fflush(stdin);
    scanf("%s",(f->description).categorie);
    printf("\nveuillez inserer l'annee de sortie du film");
    do{
        printf("\n>>veuillez verifier la validete de l'annee\n");
        scanf("%d",&(f->description).sortie);
        fflush(stdin);
    }while( (f->description).sortie > 2020 || (f->description).sortie<0 );
    printf("\nveuillez taper un resume du %s:>>",f->titre);
    scanf("%[^\n]s",(f->description).resume);
    system("cls");
    return f;
}

void afficher_film(film f)
{
    printf("\n---------------------------------------------------\n");
    printf("Titre original    : %s\n",f.titre);
    printf("Realisation       : %s\n",f.realisateur);
    printf("Acteurs principaux:\n");
    printf("\t#%s\n",f.list_acteurs.a1);
    printf("\t#%s\n",f.list_acteurs.a2);
    printf("\t#%s\n",f.list_acteurs.a3);
    printf("Description film  :\n");
    printf("\t*Categorie      :%s\n",f.description.categorie);
    printf("\t*Sortie         : %d\n",f.description.sortie);
    printf("Resumee           :\n\t#%s\n",f.description.resume);
    printf("\n---------------------------------------------------\n");
}

void modifier_film(film *f)
{
    int choix,desc;
    do
    {
        printf("1:Modifier le titre\n");
        printf("2:Modifier le realisateur\n");
        printf("3:Modifier la liste des acteurs\n");
        printf("4:Modifier la description\n");
        printf("0:Exit Modification\n");
        scanf("%d",&choix);
        fflush(stdin);
        system("cls");
        switch(choix)
        {
        case 1:
            printf("donner le nouveau titre :\n");
            scanf("%[^\n]s",f->titre);
            fflush(stdin);
            break;
        case 2:
            printf("donner le nouveau realisateur :\n");
            scanf("%[^\n]s",f->realisateur);
            fflush(stdin);
            break;
        case 3:
            printf("\ndonner les noms des principaux 3 acteurs du '%s' :",f->titre);
            fflush(stdin);
            printf("\n>>");
            scanf("%s",(f->list_acteurs).a1);
            fflush(stdin);
            printf("\n>>");
            scanf("%s",(f->list_acteurs).a2);
            fflush(stdin);
            printf("\n>>");
            scanf("%s",(f->list_acteurs).a3);
            fflush(stdin);
            break;
        case 4:
            do{
            printf("1:Modifier le genre \n");
            printf("2:Modifier la sortie\n");
            printf("3:retapper un resume\n");
            printf("0:Exit modification\n");
            scanf("%d",&desc);
            fflush(stdin);
            system("cls");
            switch(desc)
                {
                case 1:
                    printf("\nveuillez specifier la categorie du film :>>");
                    fflush(stdin);
                    scanf("%s",(f->description).categorie);
                    break;
                case 2:
                    printf("\nveuillez inserer l'annee de sortie du film");
                    do{
                    printf("\n>>veuillez verifier la validete de l'annee\n");
                    scanf("%d",&(f->description).sortie);
                    fflush(stdin);
                    }while( (f->description).sortie > 2020 || (f->description).sortie<0 );
                    break;
                case 3:
                    printf("\nveuillez taper un resume du %s:>>",f->titre);
                    scanf("%[^\n]s",(f->description).resume);
                    break;
                default:
                    desc=0;
                    break;
                }
            }while(desc!=0);
        case 0:
            break;
        }
    }while(choix!=0);
}

element *initelement(film *f,element *next)
{
    element *eptr;
    eptr=alloc(element);
    eptr->fiche=f;
    eptr->succ=next;
    return eptr;
}

catalogue *initcatalogue(element *premier)
{
    catalogue *cptr;
    cptr=alloc(catalogue);
    cptr->tete=premier;
    return cptr;
}

void affiche_catalogue(catalogue *book)
{
  element *eptr;
  eptr=book->tete;
  if(eptr==NULL)
  {
    printf("\n ________________\n");
    printf("! catalogue vide !");
    printf("\n!________________!\n");
  }
  else
  {
    while(eptr)
    {
        afficher_film(*(eptr->fiche));
        eptr=eptr->succ;
    }
  }
  free(eptr);
  printf("\nle catalogue contient <<%d>> produits visuels \n",longeur(book));

}

int longeur(catalogue *book)
{
    element *eptr;
    eptr=book->tete;
    int n=0;
    while(eptr)
    {
        eptr=eptr->succ;
        n+=1;
    }
    return n;
}

void ajouter_film(catalogue *book, film *f)
{
    element *cour;
    if(book->tete)
    {
        cour=book->tete;
        while(cour->succ)
        {
            cour=cour->succ;
        }
        cour->succ=initelement(f,NULL);
    }
    else
        book->tete=initelement(f,NULL);
}


film *recherche_titre(catalogue *book)
{
    char title[Max];
    element *eptr;
    eptr=book->tete;
    fflush(stdin);
    printf("\nveuillez taper le titre a chercher:>>");
    scanf("%[^\n]s",title);
    printf("\n");
        while(eptr)
        {
            if(!strcmp((eptr->fiche)->titre ,title))
            {
                printf("Film Founded\n");
                printf("v v v v v v v v v v v v v v v v v v v v v v v v v v");
                afficher_film(*(eptr->fiche));
                return eptr->fiche;
            }
            eptr=eptr->succ;
        }
    printf("Sorrry\nFilm Not Found\n");
    return NULL;
}

catalogue *recherche_categorie(catalogue *book)
{
    char categorie[Max];
    catalogue *cptr;
    element *cour;
    film *f;
    cptr=initcatalogue(NULL);
    cour=book->tete;
    fflush(stdin);
    printf("\nveuillez taper la categorie cherchee >>");
    scanf("%[^\n]s",categorie);
    printf("\n----%s----\n",categorie);
    while(cour)//recherche du premier element du liste chaineé
    {
        f=cour->fiche;
        if(!strcmp(categorie,(f->description).categorie))
        {
            cptr->tete=initelement(f,NULL);
            cour=cour->succ;
            break;
        }
        cour=cour->succ;
    }

    while(cour)//completer la liste chainee des films de meme categorie
    {
        f=cour->fiche;
        if(!strcmp(categorie , (f->description ).categorie ) )
        {
            ajouter_film(cptr,f);
        }
        cour=cour->succ;
    }
    printf("creation d'un catalogue contenant les films de cette categorie\n\nveuiller patienter.......\n");
    return cptr;
}

catalogue *recherche_motcle(catalogue *book)
{
    char cle[Max];
    catalogue *cptr;
    element *cour;
    film *f;
    cptr=initcatalogue(NULL);
    cour=book->tete;
    fflush(stdin);
    printf("\nveuillez taper le mot cle>>");
    scanf("%[^\n]s",cle);
    printf("\n----<<%s>> est apparue dans ----\n",cle);
    while(cour)//recherche du premier element du liste chaineé
    {
        f=cour->fiche;
        if(strstr (f->titre,cle ) || strstr((f->description).resume,cle))
        {
            cptr->tete=initelement(f,NULL);
            cour=cour->succ;
            break;
        }
        cour=cour->succ;
    }

    while(cour)//completer la liste chainee des films de meme categorie
    {
        f=cour->fiche;
        if( !strstr(f->titre,cle ) || !strstr((f->description).resume,cle) )
        {
            ajouter_film(cptr,f);
        }
        cour=cour->succ;
    }
    printf("\ncreation d'un catalogue films en relation avec <<%s>>\n\nveuiller patienter.......\n",cle);
    return cptr;
}

void supprimer_film(catalogue *book,film *fiche)
{
    catalogue *cptr;
    element *cour,*pred;
    cour=book->tete;
    pred=NULL;
    if(!fiche)
        printf("\nDeleting Process Failed \n");
    while(cour)
    {
        if (cour->fiche==fiche)
        {
            if(pred)
                pred->succ = cour->succ;
            else
                book->tete=(book->tete)->succ;
            free(cour);
            printf("supression du film <<%s>> avec succes !!",cour->fiche->titre);
            break;

        }
        pred=cour;
        cour=cour->succ;
    }
}

catalogue *tri(catalogue *book)
{
    bool sorted=false;
    film *fm,*fl;
    int reference;
    catalogue *cptr;
    element *linker,*recent;
    linker=book->tete;
    recent=book->tete;
    cptr=initcatalogue(NULL);
    if (!book->tete)
        printf("\nImpossible de trier !\nle catalogue est vide\n");
    else
    {
        printf("Tri en cours \nveuillez patienter...\n");
        while(linker)//recherche du film le plus recent
        {
            fl=linker->fiche;
            fm=recent->fiche;
            if((fl->description).sortie >= (fm->description).sortie)
                recent=linker;
            linker=linker->succ;
        }
        cptr->tete=recent;

        while(!sorted)
        {
            reference=0;
            sorted=true;
            linker=book->tete;
            while(linker)//recherche du film le plus recent
                {
                fl=linker->fiche;
                if((fl->description).sortie >= reference && !exist(cptr,fl))
                    {
                        reference= (fl->description).sortie;
                        recent=linker;
                        sorted=false;
                    }
                linker=linker->succ;
                }
            if (sorted==false)
                ajouter_film(cptr,recent->fiche);
        }
        printf("\n---Fin Tri---\n");

    }
    return cptr;
}
bool exist(catalogue *book, film *f)
{
    element *cour;
    cour=book->tete;
    while(cour)
    {
        if (f==cour->fiche)
            return true;
        cour=cour->succ;
    }
    return false;
}

int menu5()
{
    int choix;
    printf("\n\n_____________________________________________________________________________________________________\n");
    printf("1-Modifier le Film saisie           \t\t\t\t");
    printf("2-Modifier un Film dans le catalogue \n");
    printf("0-Retour au menu principal \n");
    printf("\t\t\t\tVeuillez choisir une option >>>");
    scanf("%d",&choix);      //selon le choix_saisie on va faire un traitement
    system("cls");
    return choix;
}

int menu4()
{
    int choix;
    printf("________________________________RECHERCHE D'UN FILM DANS LE CATALOGUE________________________________\n");
    printf("\n\n_____________________________________________________________________________________________________\n");
    printf("1-Recherche par mot cle           \t\t\t\t");
    printf("2-Recherche par categorie \n");
    printf("3-Recherche par titre          \t\t\t\t\t");
    printf("4-Trier selon date sortie \n");
    printf("0-Retour au menu principal \n");
    printf("\t\t\t\tVeuillez choisir une option >>>");
    scanf("%d",&choix);      //selon le choix_saisie on va faire un traitement
    system("cls");
    return choix;
}

int menu3()
{
    int choix;
    printf("_______________________________________AFFICHAGE DES DONNEES ________________________________________\n");
    printf("\n_____________________________________________________________________________________________________\n");
                        printf("1-Afficher la fiche d'un film           \t\t\t\t");
                        printf("2-Afficher le catalogue \n");
                        printf("0-Retour au menu principal \n");
                        printf("\t\t\t\tVeuillez choisir une option >>>");
                        scanf("%d",&choix);      //selon le choix_saisie on va faire un traitement
                        system("cls");
                        return choix;
}

int menu2()
{
    printf("_____________________________SAISIR/AJOUTER/MODIFIER UNE FICHE D'UN FILM_____________________________\n");
    int choix;
    printf("\n\n_____________________________________________________________________________________________________\n");
                        printf("1-(Re)Saisir une fiche de film          \t\t\t");
                        printf("2-Ajouter le film saisie au catalogue\n");
                        printf("3-Modifier un film du catalogue          \t\t\t");
                        printf("0-Retour au menu principal \n");
                        printf("\t\t\t\tVeuillez choisir une option >>>");
                        scanf("%d",&choix);      //selon le choix_saisie on va faire un traitement
                        system("cls");
                        return choix;
}

int menu()
{
int choix;
printf("\n_________________________________Gestionnaire catalogues de films_________________________________\n");
printf("\n___________________________________________________________________________________________________\n");
        printf("1-Ajout/Modifier une fiche d'un film\t\t\t\t");
        printf("2-Supression d'un film du catalogue\n");
        printf("3-Affichage du catalogue            \t\t\t\t");
        printf("4-Recherche d'un film\n");
        printf("5-(RE)Initialisation d'un catalogue \t\t\t\t");
        printf("0-EXIT\n");
        printf("\t\t\t\tVeuillez choisir une option >>> ");
        scanf("%d",&choix);
        system("cls");
        return choix;
}
