/*
 * Début d'en-tête
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*Créateur : Marina Machado
 * Date : 05.03.2020
 * Version :0.1
 */

void aideJeu(){ // Fonction pour afficher l'aide du jeu
    printf("\tAIDE DU JEU\n");
    printf("============================\n\n");
    printf("La bataille Navale est un jeu de scoiété qui existe depuis un long moment.\n\n");
    printf("Dans ce jeu il existe plusieurs types de bateaux :\n");

    printf("\t- Les sous-marins, qui sont les plus petits qui font 1 case de long,\n");
    printf("\t- Les torpilleurs, qui font 2 cases de long,\n");
    printf("\t- Les croiseurs, qui font 3 cases de long et,\n");
    printf("\t- Les cuirassés, qui sont les plus grands et qui font 4 cases de long.\n\n");

    printf("Le but du jeu est de couler tous les bateaux avec le moins de coups ratés au possible !\n\n");


}
void menu(){ //fonction pour afficher le menu

    printf("\t\t                                     |__\n");
    printf("\t\t                                     |\\/\n");
    printf("\t\t                                     ---\n");
    printf("\t\t                                     / | [\n");
    printf("\t\t                              !      | |||\n");
    printf("\t\t                            _/|     _/|-++'\n");
    printf("\t\t                        +  +--|    |--|--|_ |-\n");
    printf("\t\t                     { /|__|  |/\\__|  |--- |||__/\n");
    printf("\t\t                    +---------------___[}-_===_.'____               /\\\n");
    printf("\t\t                ____`-' ||___-{]_| _[}-  |     |_[___\\==--          \\/   _\n");
    printf("\t\t __..._____--==/___]_|__|_____________________________[___\\==--___,-----' .7\n");
    printf("\t\t|                                                                         /\n");
    printf("\t\t \\____________________________BATAILLE NAVALE____________________________|\n");
    //par  Matthew Bace

    printf("1.Jouer\n");
    printf("2.Aide du jeu\n");
    printf("3.Scores\n");
    printf("4.Quitter\n");
}


int main() {
    SetConsoleOutputCP(CP_UTF8);


    int sousMarinMAXHEALTH = 1; //points de vie des bateaux
    int torpilleursMAXHEALTH = 2;
    int croiseursMAXHEALTH = 3;
    int cuirasseMAXHEALTH = 4;

    int incremente = 0;
    int incHor = 1; //pour afficher les numéros en vertical
    int choixHorizontal;
    int choixVertical;

    int i;
    int j;
    int l;
    int choix = 1;


    int tableauxnb [10] [10] =// ce que definis ou se trouve les bateaux
            {0,0,0,0,0,0,0,0,0,0, //sous marin = 1 (1 case)
             0,0,0,4,4,4,4,0,0,0, //torpilleurs = 2 (2 cases)
             0,0,0,0,0,0,0,0,0,0, //croiseurs = 3 (3 cases)
             0,0,0,0,0,0,0,0,0,0, //cuirassé = 4 (4 cases)
             0,2,2,0,0,0,0,0,3,0,
             0,0,0,0,0,0,0,0,3,0,
             0,0,0,0,0,0,0,0,3,0,
             0,0,0,0,0,0,0,0,0,0,
             0,0,1,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0};

    char tableauxVisuel [10] [10] = //note pour moi premier[] c'est vertical et le 2ème c'est horizontal
            {'~','~','~','~','~','~','~','~','~','~', // ce que le joueur verra
             '~','~','~','~','~','~','~','~','~','~',
             '~','~','~','~','~','~','~','~','~','~',
             '~','~','~','~','~','~','~','~','~','~',
             '~','~','~','~','~','~','~','~','~','~',
             '~','~','~','~','~','~','~','~','~','~',
             '~','~','~','~','~','~','~','~','~','~',
             '~','~','~','~','~','~','~','~','~','~',
             '~','~','~','~','~','~','~','~','~','~',
             '~','~','~','~','~','~','~','~','~','~'};

    menu();// affiche le menu

    scanf("%d", &choix); //choix pour le switch plus bas qui va pouvoir rediriger l'utilisateur selon les choix du menu


    if(choix < 0 || choix > 4){
        printf("\nchoisi un des numéros affichés ci-dessus");
        while(choix > 4){
            scanf("%d", &choix);
        }
    }

    switch (choix) {
        case 1 :while (1) {
                incHor = 1;
                system("cls");
                printf("**********************\n");
                printf("***BATAILLE NAVALE****\n");
                printf("***Nombre ratés : %d**\n", incremente);// affiche le nombre de ratés
                printf("**********************\n");
                printf("    1   2   3   4   5   6   7   8   9  10\n"); // les chiffres pour s'orienter pour l'horizontal
                for (int (k) = 0; (k) < 42; ++(k)) {
                    printf("=");
                }
                printf("\n");
                for (j = 0; j < 10; j++) // boucle qui sert à afficher le tableau
                    {

                        printf("%2d", incHor);
                        incHor++;
                        for (i = 0; i < 10; i++) {
                            printf(" ");
                            printf("|");
                            printf("%c ", tableauxVisuel[j][i]);

                        }

                        printf("|\n");
                        for (int (k) = 0; (k) < 42; ++(k)) {
                            printf("=");
                        }
                        printf("\n");
                    }


                    printf("Nombre de vie restant : \n");
                    printf("sous-marin : %d     croiseur : %d     torpilleur : %d     cuirassé : %d\n", sousMarinMAXHEALTH,torpilleursMAXHEALTH, croiseursMAXHEALTH, cuirasseMAXHEALTH);

                    printf("Choisissez une case horizontalement :\n");//l'utilisateur choisis horizontalement
                    scanf("%d", &choixHorizontal);
                    choixHorizontal = choixHorizontal - 1;

                    if(choixHorizontal > 9){
                        printf("Choisissez un chiffre en 1 et 10");// condition si le chiffre est supérieur à 10
                        while(choixHorizontal > 10){
                            scanf("%d", &choixHorizontal);
                        }
                    }

                    printf("Choisissez une case verticalement :\n"); // et puis verticalement
                    scanf("%d", &choixVertical);
                    choixVertical = choixVertical - 1;

                    if(choixVertical > 9){
                        printf("Choisissez un chiffre en 1 et 10\n");// condition si le chiffre est supérieur à 10
                        while(choixVertical > 10){
                            scanf("%d", &choixHorizontal);
                        }
                    }


                    //==============================================CONDITIONS=========================================================


                    if (tableauxnb[choixVertical][choixHorizontal] == 0) {// condition pour l'incrémentation du nombre de ratés
                        incremente = incremente + 1;
                    }

                    if(tableauxnb[choixVertical][choixHorizontal] == 0){ //condition si le tir n'a pas touché un bateau
                        printf("raté !\n");
                        system("pause");
                        tableauxVisuel[choixVertical][choixHorizontal] = 'O';//Affichera un O si la case est raté
                    }

                    if (tableauxnb[choixVertical][choixHorizontal] != 0){ // condition pour qu'un bateau soit touché
                        printf("touché !\n");
                        system("pause");
                        tableauxVisuel[choixVertical][choixHorizontal] = 'X';//affiche un X si la case est touchée
                    }


                    if(tableauxnb[choixVertical][choixHorizontal] == 4){ //condition pour que le cuirassé(4 cases) soit coulé
                        cuirasseMAXHEALTH = cuirasseMAXHEALTH - 1;
                        if(cuirasseMAXHEALTH == 0){
                            printf("Coulé !\n");
                            printf("Tu as coulé un cuirassé !\n");
                            system("pause");
                        }
                    }

                    if(tableauxnb[choixVertical][choixHorizontal] == 3){ //condition pour que le croiseurs(3 cases) soit coulé
                        croiseursMAXHEALTH = croiseursMAXHEALTH - 1;
                        if(croiseursMAXHEALTH == 0){
                            printf("Coulé !\n");
                            system("COLOR 14A");
                            printf("Tu as coulé un croiseur !\n");
                            system("pause");
                        }
                    }

                    if(tableauxnb[choixVertical][choixHorizontal] == 2){ //condition pour que le torpilleur (2 cases) soit coulé
                        torpilleursMAXHEALTH = torpilleursMAXHEALTH - 1;
                        if(torpilleursMAXHEALTH == 0){
                            printf("Coulé !\n");
                            printf("\nTu as coulé un torpilleur !\n");
                            system("pause");
                        }
                    }

                if(tableauxnb[choixVertical][choixHorizontal] == 1){//condition pour que le sous-marin, (1 case) soit coulé
                    sousMarinMAXHEALTH = sousMarinMAXHEALTH - 1;
                    if(sousMarinMAXHEALTH == 0){
                        printf("Coulé !\n");
                        printf("Tu as touché un sous-marin !\n");
                        system("pause");
                    }
                }

                if(sousMarinMAXHEALTH == 0 && torpilleursMAXHEALTH == 0 && croiseursMAXHEALTH == 0 && cuirasseMAXHEALTH == 0){ //condtiton pour que le jeu se finisse
                    system("cls");
                    printf("==========VICTOIRE !==========\n\n");
                    printf("Vous avez coulé tous les bateaux après %d coups ratés !\n", incremente);
                    printf("Peut-être vous ferez mieux la prochaine fois !\n");

                    system("pause");
                    return 99;
                }


                }
                break;
        case 2 : //pour afficher l'aide du jeu
                system("cls");
                aideJeu();
                system("pause");
                break;
            case 3 :  // pour afficher le menu de scores (en dev.)
                system("cls");
                printf("toujours en cours de developpement\n");
                system("pause");
                break;
            case 4 :
                return 6; //permets de quitter le programme
                break;
            default: printf("Choisi un des numéros écris-ci dessus\n");
                    system("pause");
                break;
        }



    return 0;
}