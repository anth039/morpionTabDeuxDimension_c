#include <stdio.h>
#include <windows.h>

int main() {
    //Déclarations
    char maGrille[3][3];
    int joueur = 1,remplissageOK = 0;
    char tab[2] = {'X','O'};
    int choixJoueur = 0;
    int partieRemporte = 0, nombreCoup = 9;

    //Initialisation de la grille
    int nbr = 49;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            maGrille[i][j] = (char)nbr;
            nbr++;
        }
    }

    //Tant que la partie n'est pas terminée
    while (1){

        //Affichage
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                printf("%c|",maGrille[i][j]);
            }
            printf("\n");
        }

        //Demande de saisi d'une case
        printf("\nJoueur %d, saisir un chiffre dans la grille (%c)\n",joueur,tab[joueur-1]);
        scanf("%d",&choixJoueur);

        //Parcour pour remplissage
        remplissageOK = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                //Si le choix est dans la grille
                if(maGrille[i][j] == (char)(choixJoueur+48)){
                    maGrille[i][j] = tab[joueur-1];
                    remplissageOK = 1;
                    nombreCoup--;
                }
            }
        }

        //Vérification des lignes et des colonnes
        int testLigne = 0,testColonne = 0;
        for (int i = 0; i < 3; ++i) {
            testLigne = 0;
            testColonne = 0;
            for (int j = 0; j < 3; ++j) {
                if(maGrille[i][j] == tab[joueur-1]){
                    testLigne++;
                }
                if(maGrille[j][i] == tab[joueur-1]){
                    testColonne++;
                }
            }
            if(testLigne == 3 || testColonne == 3 ){
                break;
            }
        }
        if(testLigne == 3 || testColonne == 3 ){
            partieRemporte = 1;
            break;
        }

        //Vérification des diagonales
        int testDiagonale1 = 0,testDiagonale2 = 0;
        for (int i = 0; i < 3; ++i) {
            if(maGrille[i][i] == tab[joueur-1]){
                testDiagonale1++;
            }
            if(maGrille[i][2-i] == tab[joueur-1]){
                testDiagonale2++;
            }
        }
        if(testDiagonale1 == 3 || testDiagonale2 == 3 ){
            partieRemporte = 1;
            break;
        }

        //Si Nombre de coup est à zéro
        if(nombreCoup == 0){
            break;
        }

        //Changement de joueur
        if(remplissageOK == 1){
            if(joueur == 1){
                joueur = 2;
            }else{
                joueur = 1;
            }
        }
    }

    //Détermine comment la partie sait terminée
    if(nombreCoup == 0 && partieRemporte == 0){
        printf("\nMatch null !\n");
    }else{
        printf("Félicitation joueur %d, vous avez gagné !\n",joueur);
    }

    //PAUSE
    system("PAUSE");

    return 0;
}
