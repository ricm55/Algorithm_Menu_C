/*!  @file                              VerifierPalindrome.c
     @version                           1.00
     @brief                             Implementation de...

     @internal
     @note                              Note au programmeur.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2017-10-25
     @author                            Marc-Antoine
     @note                              Entree du code.

     <hr width="100%" height="5">
 */
//** **************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\..\header\Palindrome\TraiterChaineCaracteres.h"
#include "..\..\header\Palindrome\VerifyPalindrome.h"
#define TAILLE_MAX 500
//** **************************************************************************
/*!  @brief                             Fonction de la routine.

     @return                            Code de la couleur de l'objet.
     @retval                            ccNoir    Noir.
     @retval                            ccBrun    Brun / marron.

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2005-09-13
     @author                            Denis Lavoie
     @note                              Entr�e du code.

     <hr width="100%" height="5">
 */
unsigned char* cVerifierPalindrome ( unsigned char* pChaine )
{//Chaine verifiant si la saisi est un palindrome

    unsigned char pChaineInverse[TAILLE_MAX];//Creer de l'espace pour la chaine inverse

    int iPalindrome = 0;//Creer de l'espace pour l'information qui indique si c'est un palindrome

    //Traitement de la chaine de l'utilisateur
    pChaine = cEliminerMajuscules(cEliminerPonctuation(cEliminerMajuscules(ElimineAccents(cEliminerEspaces(pChaine)))));

    //Inversion de la chaine de l'utilisateur
    cInversionChaine(pChaine, pChaineInverse);

    //Analyser les 2 chaines pour voir s'ils sont egaux
    iPalindrome = iComparerChaine(pChaine, pChaineInverse);


    return iPalindrome;//Retourner si c'est un palindrome ou non
}
