#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*Créateur : Marina Machado
 * Date : 05.03.2020
 * Version :0.1
 */

void menu(){ //fonction pour afficher le menu
    printf("1.Menu\n");
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
    int choixHorizontal;
    int choixVertical;

    int i;
    int j;


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

    while(1){
     system("cls");
      printf("BATAILLE NAVALE\n\n");

        for(j = 0;j <10; j++) // boucle qui sert à afficher le tableau
        {
            for(i = 0; i < 10; i++){
            printf("|");
            printf("__");
            printf("%c", tableauxVisuel [j] [i]);

            }

            printf("\n");

        }

        printf(" \nNombre ratés : %d\n" ,incremente);

        printf("Choisissez une case horizontalement :\n");
        scanf("%d", &choixHorizontal);

        printf("Choisissez une case verticalement :\n");
        scanf("%d", &choixVertical);


        if(tableauxnb[choixVertical][choixHorizontal] == 0){
            incremente = incremente + 1;
        }

        if (tableauxnb[choixVertical][choixHorizontal] != 0) {
            printf("touché !\n");
            system("pause");

            tableauxVisuel[choixVertical][choixHorizontal] = 'X';
        }
        if (tableauxnb[choixVertical][choixHorizontal] == 0) {
            printf("raté !\n");
            system("pause");

            tableauxVisuel[choixVertical][choixHorizontal] = 'O';
        }



    }

    return 0;
}