#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main() {
    char nom_joueur[100];
    printf("              Multigame!            \n"
        "Bonjour cher joueur, et bienvenu dans Multigame, une plateforme"
        " qui rassemble les meilleurs jeux du MONDE entier!!!\n Ici on est la pour se détendre...\n\n"
        "Tout d'abord comment veux -tu etre appelé : ");
        fgets(nom_joueur, 100, stdin);
        nom_joueur[strlen(nom_joueur)-1]='\0';
        printf("\n");
        printf("%s, ca c'est bien un nom de winner! Tu sais un des plus grand joueur de Multigame a le meme nom que toi, coincidence de je crois pas...\n\n", nom_joueur);
        printf("Alors %s sur cette plateforme, tu peux choisir de jouer entre 3 jeux :\n"
        "- Devine le nombre \n- Bataille (le jeux de carte) \n- Le pendu\n",nom_joueur);

        
        int consignes_jeux;
            printf("Est -ce que tu veux les consignes d'un jeu? Si oui choissiez un ou pluisieurs nombre entre :\n"
                "1) Devine le nombre \n","2) Bataille\n", "3) Le pendu \n");
            scanf("%d", &consignes_jeux);

            




    


return 0;
}
/*const char* listeMots[] = {
    "Éclipse","Ruisseau","Galaxie","Pivoine","Fragment","Brume","Cascade","Saphir","Horizon",
    "Mélodie","Nuance","Symbiose","Quartz","Fougère","Paradoxe","Éclat","Labyrinthe",
    "Vestige","Lueur","Rivage","Spirale","Envol","Mirage","Velours","Azur","Harmonie",
    "Mosaïque","Enigme","Silence","Luciole",
    };

    char MotJoueurDevine[20];*/
