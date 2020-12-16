/*!  @file                              TVshowManager.c
     @version                           1.00
     @brief                             This program simulate a TV subscription

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2017-09-07
     @author                            Marc-Antoine
     @note                              It can display TV set according to your subscription

     <hr width="100%" height="5">
 */
//** **************************************************************************

#include <stdio.h>
#include <stdlib.h>

#include "../../header/SubscribeTvProgram/DisplayTVshow.h"

int main ( int argc, char** argv )
{

    int iAbonnement = 0;
    //Création d'un tableau d'information
    int iInfo[] = {6, 2010, 8, 22, 450, 510, 1,
                   12, 2010, 8, 30, 1020, 1080, 1,
                   16, 2010, 8, 28, 1140, 1170, 0,
                   24, 2011, 8, 26, 1140, 1170, 0,
                   26, 2010, 8, 18, 450, 510, 1,
                   40, 2010, 8, 22, 450, 510, 1,
                   -1, -1, -1, -1 };

    do
    {
        printf ( "Votre abonnement: " );
        scanf ( "%i", &iAbonnement ); //Stocker la saisi de l'utilisateur dans une variable
        if ( iAbonnement > 2 )
        {
            printf ( "Cet abonnement n'existe pas\n" );
        }

    }//Tant que l'abonnement choisi n'est pas bon
    while ( iAbonnement != 0 && iAbonnement != 1 && iAbonnement != 2 );

    printf ( "\n====================================================\n" );
    printf ( "Poste  Date     Debut   Fin      Mode\n" );
    printf ( "----------------------------------------------------\n" );

    AfficherListeProgrammation ( iAbonnement, iInfo ); //Utilisation de la routine qui affiche les divers postes

    return (EXIT_SUCCESS );
}

