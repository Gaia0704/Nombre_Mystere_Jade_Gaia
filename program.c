#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



/*void banderole()
{
    printf("                                        ------------- \n");
    printf("                                       |  Multigame! |           \n");
    printf("                                        -------------\n");
}

void nom_joueur_choisir(char nom_joueur[], int max)
{
    
    printf("Bonjour cher joueur, et bienvenu dans Multigame, une plateforme"
        " qui rassemble les meilleurs jeux du MONDE entier!!!\n Ici on est la pour se détendre...\n\n"
        "Tout d'abord comment veux -tu etre appelé :\n ");
    fgets(nom_joueur, max, stdin);
    nom_joueur[strlen(nom_joueur)-1]='\0';
    printf("\n");
    printf("%s, ca c'est bien un nom de winner! Tu sais un des plus grand joueur de Multigame a le meme nom que toi, coincidence je crois pas...\n\n", nom_joueur);
}

void presentation_des_jeux( char nom_joueur[])
{
   
    printf("Alors %s sur cette plateforme, tu peux choisir de jouer entre 3 jeux :\n"
        "- Devine le nombre \n- Bataille (le jeux de carte) \n- Le pendu\n\n",nom_joueur);
}

void consignes(char nom_joueur[])
{
    printf("Est -ce que tu veux les consignes d'un jeu? Si oui choissiez un ou pluisieurs nombre entre :\n");
        int consignes_jeux;
            printf("1) Devine le nombre \n");
            printf("2) Bataille\n");
            printf("3) Le pendu \n\n");
            printf("Alors quelle(s) consigne(s) de jeux choisissez-vous ?\n");
            scanf("%d", &consignes_jeux);
        
        int chiffre;
        while (consignes_jeux > 0) 
        {
        chiffre = consignes_jeux % 10; 
        consignes_jeux = consignes_jeux / 10;

        if (chiffre== 1)
        {
            printf("\nDevine le nombre\n"
                "L’ordinateur choisit un nombre secret entre 1 et 100. Ton but est de le deviner. Après chaque essai," 
                "on te dit si le nombre secret est plus grand ou plus petit. Continue jusqu’à trouver le bon nombre !\n\n");
        }

        if (chiffre==2)
        {
            printf("\nLa Bataille\n"
                "Chaque joueur retourne la première carte de son paquet. Celui qui a la carte la plus forte gagne les cartes." 
                "En cas d’égalité, c’est la bataille ! Le joueur qui remporte toutes les cartes gagne la partie.\n\n");
        }

        if (chiffre==3)
        {
            printf("\nLe pendu\n"
                "Devine le mot en proposant des lettres." 
                "Chaque erreur ajoute une partie du pendu. Tu gagnes si tu trouves le mot avant que le dessin soit complet !\n\n");
        }

        }
}

 char nom_joueur[100];
    banderole();
    nom_joueur_choisir(nom_joueur,100);
    presentation_des_jeux(nom_joueur);
    consignes(nom_joueur);

    int choix;
    printf("Quel jeux veux-tu choisir? Entre 1, 2 et 3");
    scanf("%d", choix);
    
    if (choix == 1)
    {

    }
    
    else if (choix == 2)
    {

    }

    else if (choix == 3)
    {
        
    }*/


int main() {
    srand(time(NULL));
   const char* listeMots[] = {
    "Éclipse","Ruisseau","Galaxie","Pivoine","Fragment","Brume","Cascade","Saphir","Horizon",
    "Mélodie","Nuance","Symbiose","Quartz","Fougère","Paradoxe","Éclat","Labyrinthe",
    "Vestige","Lueur","Rivage","Spirale","Envol","Mirage","Velours","Azur","Harmonie",
    "Mosaïque","Enigme","Silence","Luciole",
    };

    
    int nbMots = sizeof(listeMots) / sizeof(listeMots[0]); 
    int index = rand() % nbMots;                             
    const char* motSecret = listeMots[index];
    printf("Mot choisi : %s\n", motSecret);

    /*char MotJoueurDevine[20];*/

   
        

return 0;}

/**/
