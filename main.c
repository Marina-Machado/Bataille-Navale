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

void creationFichier(char username [20], int nbTirs){
    
    FILE *fPointer;//pointeur pour un fichier
    fPointer = fopen("Score/score.txt", "a");

    fprintf(fPointer, "Nom Joueur : %s  Nombre de tirs ratés : %d\n", username, nbTirs);//Le tableau des scores affichera ça

    fclose(fPointer);//sert a le fermer
}

void score(){//Fonction pour afficher le tableau des scores
    system("color 0E");
    printf("\t==========Tableaux des scores==========\n\n");
    FILE *fPointer;
    fPointer = fopen("Score/score.txt", "r");

    char affichageScore[150];

    while(fgets(affichageScore, 150, fPointer)){//boucle qui sert à lire ce qu'il y a dans le fichier jusqu'a la fin de celui-ci
        puts(affichageScore);// ce qui va permettre d'afficher les lignes
    }
    fclose(fPointer);

}
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

    system("cls"); //permets de nettoyer l'écran

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

    SetConsoleOutputCP(CP_UTF8); //sert à afficher les accents
    system("color 01");

    int sousMarinMAXHEALTH = 1;         //points de vie des bateaux
    int torpilleursMAXHEALTH = 2;
    int croiseursMAXHEALTH = 3;
    int cuirasseMAXHEALTH = 4;

    int incremente = 0;
    int incHor = 1; //pour afficher les numéros en vertical
    int choixHorizontal;
    int choixVertical;

    int i;//variables pour afficher le tableau
    int j;
    int choix = 1;
    int choixMenu;
    int choixScore;

    int choixNom;
    char nomUtilisateur [20];


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

    switch (choix)
    {
        case 1 :
            system("cls");
            printf("Voulez vous entrer un nom d'utilisateur ?\n\n");
            printf("1. Oui\n");
            printf("2. Non\n");

            scanf("%d", &choixNom);
            switch(choixNom){
                case 1:
                    printf("Quel est ton nom d'utilisateur ?\n");
                    printf("-> ");
                    scanf("%s", nomUtilisateur);
                    printf("%s c'est bien ça ?\n", nomUtilisateur);
                    break;
                case 2:
                    break;
            }
            while (1)
            {

                incHor = 1;
                system("cls");
                printf("\t**********************\n");
                printf("\t***BATAILLE NAVALE****\n");
                printf("\t***Joueur : %s ***\n", nomUtilisateur);
                printf("\t***Nombre ratés : %d**\n", incremente);// affiche le nombre de ratés
                printf("\t**********************\n");
                printf("    1   2   3   4   5   6   7   8   9  10\n"); // les chiffres pour s'orienter pour l'horizontal
                printf("   ");
                for (int (k) = 0; (k) < 40; ++(k)) {
                    printf("=");
                }
                printf("\n");
                for (j = 0; j < 10; j++) // boucle qui sert à afficher le tableau
                    {

                        printf("%2d", incHor);//affiche les numéros à coté du tableau au sens vertical
                        incHor++;//les incrémente
                        for (i = 0; i < 10; i++) {
                            printf(" ");
                            printf("|");
                            printf("%c ", tableauxVisuel[j][i]);
                        }

                        printf("|\n");
                        printf("   ");
                        for (int (k) = 0; (k) < 40; ++(k)) {
                            printf("=");
                        }
                        printf("\n");
                    }

                    printf("Nombre de vie restant : \n");
                    printf("sous-marin : %d     torpilleur : %d     croiseur : %d     cuirassé : %d\n", sousMarinMAXHEALTH,torpilleursMAXHEALTH, croiseursMAXHEALTH, cuirasseMAXHEALTH);

                    printf("Choisissez une case horizontalement :\n");//l'utilisateur choisis horizontalement
                    scanf("%d", &choixHorizontal);

                    if(choixHorizontal > 10){//Condition si le numéro choisi est plus grand que 10, si il est plus grand il va générer une boucle
                        printf("Choisissez un autre chiffre : ");
                        while(choixHorizontal > 10){
                        scanf("%d", &choixHorizontal);}

                    }
                    choixHorizontal = choixHorizontal - 1;

                    printf("Choisissez une case verticalement :\n"); // et puis verticalement
                    scanf("%d", &choixVertical);

                    if(choixVertical > 10){ //Condition si le numéro choisi est plus grand que 10, si il est plus grand il va générer une boucle
                        printf("Choisissez un autre chiffre : ");
                        while(choixVertical > 10){
                            scanf("%d", &choixVertical);}

                    }
                    choixVertical = choixVertical - 1;

                    //==============================================CONDITIONS=========================================================

                    if(tableauxnb[choixVertical][choixHorizontal] == 9){//condition qui s'affiche si la case a déja été tirée dessus

                        printf("Tu as déja tiré ici !\n");
                        system("pause");
                    }

                    if(tableauxnb[choixVertical][choixHorizontal] == 0){ //condition si le tir n'a pas touché un bateau
                        incremente = incremente + 1; // pour incrémenter le nombre de tirs ratés
                        printf("raté !\n");
                        system("pause");
                        tableauxVisuel[choixVertical][choixHorizontal] = 'O';//Affichera un O si la case est raté
                        tableauxnb[choixVertical][choixHorizontal] = 9;
                    }

                    if (tableauxnb[choixVertical][choixHorizontal] != 0 && tableauxnb[choixVertical][choixHorizontal] != 9){ // condition pour qu'un bateau soit touché
                        printf("touché !\n");
                        system("pause");
                        tableauxVisuel[choixVertical][choixHorizontal] = 'X';//affiche un X si la case est touchée

                        //condition ci-dessous pour changer un chiffre autre qu'un qui est attribué à un bateau en 9 pour afficher si l'utilisateur tire une 2ème fois qu'il a déja tiré ici
                        if(tableauxnb[choixVertical][choixHorizontal] != 4 && tableauxnb[choixVertical][choixHorizontal] != 3 && tableauxnb[choixVertical][choixHorizontal] != 2 && tableauxnb[choixVertical][choixHorizontal] != 1){
                            tableauxnb[choixVertical][choixHorizontal] = 9;
                        }

                    }

                    if(tableauxnb[choixVertical][choixHorizontal] == 4){ //condition pour que le cuirassé(4 cases) soit coulé
                        cuirasseMAXHEALTH = cuirasseMAXHEALTH - 1;
                        if(cuirasseMAXHEALTH == 0){
                            printf("Coulé !\n");
                            printf("Tu as coulé un cuirassé !\n");
                            system("pause");
                        }
                        tableauxnb[choixVertical][choixHorizontal] = 9;// change la case du bateau pour dire que la case est touchée
                    }

                    if(tableauxnb[choixVertical][choixHorizontal] == 3){ //condition pour que le croiseurs(3 cases) soit coulé
                        croiseursMAXHEALTH = croiseursMAXHEALTH - 1;
                        if(croiseursMAXHEALTH == 0){
                            printf("Coulé !\n");
                            printf("Tu as coulé un croiseur !\n");
                            system("pause");
                        }
                        tableauxnb[choixVertical][choixHorizontal] = 9;
                    }

                    if(tableauxnb[choixVertical][choixHorizontal] == 2){ //condition pour que le torpilleur (2 cases) soit coulé
                        torpilleursMAXHEALTH = torpilleursMAXHEALTH - 1;
                        if(torpilleursMAXHEALTH == 0){
                            printf("Coulé !\n");
                            printf("\nTu as coulé un torpilleur !\n");
                            system("pause");
                        }
                        tableauxnb[choixVertical][choixHorizontal] = 9;
                    }

                    if(tableauxnb[choixVertical][choixHorizontal] == 1){//condition pour que le sous-marin, (1 case) soit coulé
                        sousMarinMAXHEALTH = sousMarinMAXHEALTH - 1;

                        if(sousMarinMAXHEALTH == 0){
                            printf("Coulé !\n");
                            printf("Tu as touché un sous-marin !\n");
                            system("pause");
                        }
                        tableauxnb[choixVertical][choixHorizontal] = 9;
                    }

                    if(sousMarinMAXHEALTH == 0 && torpilleursMAXHEALTH == 0 && croiseursMAXHEALTH == 0 && cuirasseMAXHEALTH == 0){ //condtiton pour que le jeu se finisse
                        system("cls");
                        printf("\t========== VICTOIRE !==========\n\n");
                        printf("Bravo %s ! Vous avez coulé tous les bateaux après %d coups ratés !\n", nomUtilisateur,incremente);
                        printf("Peut-être vous ferez mieux la prochaine fois !\n\n");

                        printf("\tVoulez-vous afficher votre score dans le tableau des scores ?\n\n");
                        printf("\t1. Oui    2.Non, revenir au menu     3.Quitter le programme");

                        scanf("%d", &choixScore);

                        // Pour cette partie j'aurais préféré faire un switch mais un bug bizarre ne m'a pas permis de faire cela. Cels faisait une boucle infinie constamment qui
                        //redirigeait le joueur a la partie deja finie
                       if (choixScore == 1){
                                system("cls");
                                creationFichier(nomUtilisateur, incremente);
                                score();
                                system("pause");
                                main();
                                break;
                       }
                       if (choixScore == 2) {
                           system("cls");
                           main();//renvoie au menu
                           break;
                       }
                       if (choixScore == 2) {
                           return 6; // quitte le programme
                       }


                    }
                }
                break;

            case 2 : //pour afficher l'aide du jeu
                system("cls");
                aideJeu();
                system("pause");
                main();
                break;
            case 3 :  // pour afficher le menu de scores (en dev.)
                system("cls");
                score();
                system("pause");
                main();
            break;
            case 4 :
                system("exit");
                return 6; //permets de quitter le programme
                break;
            default: printf("Choisi un des numéros écris-ci dessus\n");//message qui s'affiche si on choisis un autre numéro que ceux montrés en haut
                    system("pause");
                break;
    }

    return 0;
}