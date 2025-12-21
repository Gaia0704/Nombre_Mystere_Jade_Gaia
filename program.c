#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NB_CARTES 26



void banderole()
{
    printf("                                        ============= \n");
    printf("                                       |  Multigame! |           \n");
    printf("                                        =============\n");
}

void nom_joueur_choisir(char nom_joueur[], int max)
{
    
    printf("Bonjour cher joueur, et bienvenu dans Multigame, une plateforme"
           " qui rassemble les meilleurs jeux du MONDE entier!!!\n Ici on est la pour se détendre...\n\n"
           "Tout d'abord comment veux-tu etre appelé :\n ");
    fgets(nom_joueur, max, stdin);
    nom_joueur[strlen(nom_joueur)-1]='\0';
    printf("\n");
    printf("%s, c'est bien un nom de winner! Tu sais un des plus grand joueur de Multigame à le même nom que toi, coïncidence je ne crois pas...\n\n", nom_joueur);
}

void presentation_des_jeux( char nom_joueur[])
{
   
    printf("Alors %s sur cette plateforme, tu peux choisir de jouer entre 3 jeux :\n"
           "- Devine le nombre \n- Bataille (le jeux de carte) \n- Le pendu\n\n",nom_joueur);
}

void consignes(char nom_joueur[])
{
    printf("Choisissez quelle(s) consigne(s) vous voulez avoir ( un ou pluisieurs nombre entre comme par exemple 123) :\n");
        int consignes_jeux;
            printf("1) Devine le nombre \n");
            printf("2) Bataille\n");
            printf("3) Le pendu \n\n");
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
                       "Chaque erreur enlève un essai que tu as. Tu gagnera si tu trouves le mot que tes essais restants ne soient à 0!\n\n");
            }

        }
}

void jouer_nombre_mystere(int max_valeur, int max_essais) 
{
    int nombre_mystere = (rand() % max_valeur) + 1;
    int essai;
    int essais = 0;

    printf("Devine le nombre mystere choisi entre 1 et %d\n", max_valeur);

    while (1) 
    {
        if (max_essais != -1 && essais >= max_essais) 
        {
            printf("Vous avez épuisé vos %d essais. PERDU.\n", max_essais);
            printf("Le nombre etait : %d\n", nombre_mystere);
            break;
        }

        printf("Entre ton choix : ");
        scanf("%d", &essai);
        essais++;

        if (essai < nombre_mystere) 
        {
            printf("C'est plus grand\n\n");
        } 
        else if (essai > nombre_mystere) 
        {
            printf("C'est plus petit\n\n");
        } else 
        {
            printf("Bravo ! Tu as trouve en %d essais.\n", essais);
            break;
        }
    }
}

void distribuerCartes(int joueur[])
{
    int i;
    for (i = 0; i < NB_CARTES; i++) 
    {
        joueur[i] = rand() % 13 + 2; 
    }
}

int JouerPartieBataille(int joueur[], int ordinateur[])
{
    int i;
    int scoreJ = 0, scoreO = 0;
    char touche;

    for (i = 0; i < NB_CARTES; i++) 
    {
        printf("\nTour %d\n", i + 1);
        printf("Appuie sur une touche et puis sur entrée pour jouer ta carte...");
        scanf(" %c", &touche);

        printf("Ta carte : %d\n", joueur[i]);
        printf("Carte ordinateur : %d\n", ordinateur[i]);

        if (joueur[i] > ordinateur[i]) 
        {
            printf(">>> Tu gagnes ce tour !");
            scoreJ++;
        }
        else if (ordinateur[i] > joueur[i]) 
        {
            printf(">>> L'ordinateur gagne ce tour !");
            scoreO++;
        }
        else 
        {
            printf(">>> Egalite !");
        }
        printf("\n");
    }

    printf("\nScore final : Toi = %d | Ordinateur = %d\n", scoreJ, scoreO);

    if (scoreJ > scoreO) 
        return 1;
    else if (scoreO > scoreJ) 
        return 2;
    else 
        return 0;
}
    
    
int MenuPendu() 
{
    printf("Tu peux alors choisir entre plusieurs niveaux :\n");
    printf(" 1) Niveau débutant (20 coups)\n 2) Niveau médium (15 coups)\n 3) Niveau expert (10 coups)\n");
    printf("Ecris 1, 2 ou 3 : ");

    int NiveauPendu;
    scanf("%d", &NiveauPendu);
    printf("Alors tu as choisi le niveau %d\n", NiveauPendu);
    return NiveauPendu;
}

int dejaTestee(const char lettresTestees[], int nb, char lettre)
{
    for (int i = 0; i < nb; i++) 
    {
        if (lettresTestees[i] == lettre) return 1;
    }
    return 0;
}

void JeuPendu(const char* mot, int NombreDecoupsMax) 
{
    int n = (int)strlen(mot);

    char MotMasqué[50];
    for (int i = 0; i < n; i++) MotMasqué[i] = '_';
    MotMasqué[n] = '\0';

    int NombreDeCoups = NombreDecoupsMax;
    char lettresTestees[26];
    int nbLettresTestees = 0;

    while (NombreDeCoups > 0 && strcmp(MotMasqué, mot) != 0) 
    {
        printf("\nMot : %s\n", MotMasqué);
        printf("Coups restants : %d\n", NombreDeCoups);

        printf("\n");

        printf("Lettres deja testees : ");
        for (int i = 0; i < nbLettresTestees; i++) printf("%c ", lettresTestees[i]);
        printf("\n");

        printf("Lettre : ");
        printf("ATTENTION LA LETTRE DOIT ETRE EN MINUSCULE\n");
        char lettre;
        scanf(" %c", &lettre);

        if (dejaTestee(lettresTestees, nbLettresTestees, lettre)) 
        {
            printf("Tu as deja essaye cette lettre !\n");
            continue;
        }
    
        lettresTestees[nbLettresTestees] = lettre;
        nbLettresTestees++;

        int trouve = 0;
        for (int i = 0; i < n; i++) 
        {
            if (mot[i] == lettre) 
            {
                MotMasqué[i] = mot[i];
                trouve = 1;
            }
        }

        if (!trouve) 
        { 
            NombreDeCoups = NombreDeCoups - 1;
             printf("Raté !\n"); 
        }
        else 
        { 
            printf("Bien !\n"); 
        }
    }

    if (strcmp(MotMasqué, mot) == 0)
    {
        printf("\nBravo ! Le mot était : %s\n", mot);
    } 
    else 
    {
        printf("\nPerdu... Le mot était : %s\n", mot);
    }
}

int main(void) 
{
    srand((unsigned)time(NULL));
    char nom_joueur[100];
    banderole();
    nom_joueur_choisir(nom_joueur,100);
    presentation_des_jeux(nom_joueur);
    consignes(nom_joueur);

    int choix = 0;
    int quitter = 0;
    while (quitter == 0)
    {
        printf("\n================ MENU PRINCIPAL ================\n");
        presentation_des_jeux(nom_joueur);
        printf("Quel jeux veux-tu choisir? Entre 1, 2 et 3\n");
        scanf("%d",&choix);

        if (choix == 1)
        {
            int continuer = 1;
            while (continuer == 1) 
            {  
                printf("=== DEVINE LE NOMBRE ===\n");
                int niveau;
                int max_essais;
                int max_valeur = 100;

                printf("Choisis ton niveau (1, 2, 3) : ");
                scanf("%d", &niveau);

                if (niveau == 1)
                {
                    max_essais = -1;   // illimité
                } 
                else if (niveau == 2)
                {
                    max_essais = 50;
                } 
                else if (niveau == 3) 
                {
                    max_essais = 10;
                } 
                else 
                {
                    printf("Niveau invalide. Tu repars au niveau 1.\n");
                    max_essais = -1;
                }

                jouer_nombre_mystere(max_valeur, max_essais);
                printf("On espere que tu t'es bien amusé! Mais il faut faire un choix. Soit tu continues de jouer, soit tu arretes et reviens au menu principal.\n");
                printf("Tu as le chois entre :\n 1)Je continue de jouer a devine le nombre \n 2) J'arrete de jouer\n");
                int ChoixApresDevineLeNombre;
                scanf("%d",&ChoixApresDevineLeNombre);
                printf("Tu as choisi de faire le numéro : %d \n\n", ChoixApresDevineLeNombre);

                if (ChoixApresDevineLeNombre == 1) 
                {
                continuer = 1;
                } 
                else 
                {
                continuer = 0;
                }
            
            }
        }

        else if (choix == 2)
        {
            int continuer = 1;
            while (continuer == 1) 
            {
                int joueur[NB_CARTES];
                int ordinateur[NB_CARTES];
                int resultat;

                printf("=== JEU DE LA BATAILLE ===\n");
                printf("Toi contre l'ordinateur\n\n");

                distribuerCartes(joueur);
                distribuerCartes(ordinateur);

                resultat = JouerPartieBataille(joueur, ordinateur);

                if (resultat == 1)
                {
                    printf("Bravo ! Tu gagnes la partie !\n");
                }
                else if (resultat == 2)
                {
                    printf("L'ordinateur gagne la partie.\n");
                }
                else
                {
                    printf("Match nul.\n");
                }

                printf("Alors cette bataille? Mais il faut faire un choix. Soit tu continues de jouer, soit tu arretes et reviens au menu principal.");
                printf("Tu as le chois entre :\n 1)Je continue de jouer au pendu \n 2) J'arrete de jouer\n");
                int ChoixApresBataille;
                scanf("%d",&ChoixApresBataille);
                printf("Tu as choisi de faire le numéro : %d \n\n", ChoixApresBataille);

                if (ChoixApresBataille == 1) 
                {
                continuer = 1;
                } 
                else 
                {
                continuer = 0;
                }

            } 
        }

        else if (choix == 3)
        {
            int continuer = 1;
            while (continuer == 1) 
            {
                printf("=== JEU DU PENDU ===\n");
                const char* listeMots[] = 
                {
                "eclipse","ruisseau","galaxie","pivoine","fragment","brume","cascade","saphir","horizon",
                "melodie","nuance","symbiose","quartz","fougere","paradoxe","eclat","labyrinthe",
                "vestige","lueur","rivage","spirale","envol","mirage","velours","azur","harmonie",
                "mosaique","enigme","silence","luciole","turboreacteur", "aerodynamique", "cockpit", "altitude", 
                "fuselage", "turbulence","avionique", "helicoptere","volets", "atterrissage", 
                "planeur", "compas", "navigation", "commandant", "empennage", "piste","portance", "radar", "maintenance", "cap",
                };

                int nbMots = (int)(sizeof(listeMots) / sizeof(listeMots[0]));
                const char* motSecret = listeMots[rand() % nbMots];
                printf("Te voici dans la partie du Pendu...\n");
                printf("L'ordinateur choisit un mot, et toi tu vas devoir le trouver !\n");

                int niveau = MenuPendu();

                if (niveau == 1)
                {
                    JeuPendu(motSecret, 20);
                }
                else if (niveau == 2) 
                {
                    JeuPendu(motSecret, 15);
                }
                else if (niveau == 3) 
                {
                    JeuPendu(motSecret, 10);
                }
                else 
                {
                  printf("Niveau invalide.\n");
                }
                
                printf("Maintenant que tu t'es bien amusé avec le pendu il faut faire un choix. Soit tu continues de jouer, soit tu arretes et reviens au menu principal.");
                printf("Tu as le chois entre :\n 1)Je continue de jouer au pendu \n 2) J'arrete de jouer\n");
                int ChoixApresPendu;
                scanf("%d",&ChoixApresPendu);
                printf("Tu as choisi de faire le numéro : %d \n\n", ChoixApresPendu);

                if (ChoixApresPendu == 1) 
                {
                    continuer = 1;
                } 
                else 
                {
                    continuer = 0;
                }
            }
        }
    }
    return 0;
}
   