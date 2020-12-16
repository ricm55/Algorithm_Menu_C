/*!  @file                              AfficherProgrammation.c
     @version                           1.00
     @brief                             Implementation de...

     @internal
     @note                              Note au programmeur.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2017-11-07
     @author                            Marc-Antoine
     @note                              Entree du code.

     <hr width="100%" height="5">
 */
//** **************************************************************************

#include "AfficherProgrammation.h"

//** **************************************************************************
/*!  @brief                             Fonction de la routine.

     @return                            Code de la couleur de l'objet.
     @retval                            ccNoir    Noir.
     @retval                            ccBrun    Brun / marron.
     @retval                            ccMarron  Brun / marron.
     @retval                            ccRouge   Rouge.
     @retval                            ccOrange  Orange.
     @retval                            ccJaune   Jaune.
     @retval                            ccVert    Vert.
     @retval                            ccBleu    Bleu.
     @retval                            ccViolet  Violet / mauve.
     @retval                            ccMauve   Violet / mauve.
     @retval                            ccGris    Gris.
     @retval                            ccBlanc   Blanc.
     @retval                            ccBleu    Bleu.

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2005-09-13
     @author                            Denis Lavoie
     @note                              Entr�e du code.

     <hr width="100%" height="5">
 */
int AfficherListeProgrammation ( int iAbonnement, int iInfo[] )
{
    //Nom de la fonction: AfficherListeProgrammation
    //
    //Objectif: Fonction permettant d'afficher une liste des postes de télévision
    //          disponible selon les abonnements


    int p = 0;
    while ( iInfo[p] != -1 )
    {//Boucle permettant d'afficher les divers postes disponibles

        if ( ( iAbonnement == 0 && iInfo[p] <= 16 ) ||
             ( iAbonnement == 1 && iInfo[p] <= 26 ) ||
             ( iAbonnement == 2 && iInfo[p] <= 40 ) )
        {
            printf ( "%5i %4i-%02i-%02i %3.2i:%2.2i %4.2i:%2.2i %4i\n", //Imprimer les postes, dates et autres informations
                     iInfo[p], iInfo[p + 1], iInfo[p + 2], iInfo[p + 3],
                     iInfo[p + 4] / 60, iInfo[p + 4] % 60,
                     iInfo[p + 5] / 60, iInfo[p + 5] % 60, iInfo[p + 6] );

            p = p + 7; //Incrementer de 7 pour passer à l'autre poste
        }
        else
            p += 7;

    }
    return 0;
}
