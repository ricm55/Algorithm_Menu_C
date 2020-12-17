/*!  @file                              Palindrome.c
     @version                           1.00
     @brief                             This program can analyze sentences and determine if they are palindrome

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2017-10-16
     @author                            Marc-Antoine Ricard
     @note                              Can now verify each character and determine if the user input is <br>
                                        associated with the definition of a palindrome

     <hr width="100%" height="5">
 */
//** **************************************************************************

#include <stdio.h>
#include <stdlib.h>

#include "..\..\header\Compiler.h"
#include "..\..\header\Palindrome\Palindrome.h"
#include "..\..\header\Palindrome\verifyPalindrome.h"

//Maximum number of character for user input
#define MAX_CHARACTERS 500
//** **************************************************************************
/*!
     Verify if a sting is a palindrome
     @return                Code d'erreur.
     @retval  EXIT_SUCCESS  Error code
     @retval  EXIT_FAILED   Error code
 */
int palindrome ()
{
#if 1

    char sTitre[] = "PALINDROME TESTER\n";
    char sPied[] =  "*********************\n\n";
    char sDemande[] = "Insert a sentence\n=> ";
    char sPhrase[MAX_CHARACTERS] = "";
    char sPositif[] = "This sentence is a palindrome!\n";
    char sNegatif[] = "This sentence is not a palindrome!\n";
    char sRecommencer[] = "Do you want to start over ? (O/N) ";
    char sPasCompris[] = "I don't understand your answer...\n";
    char cRejouer = 'a';
    int iReponse = 0;

    //Display title
    printf ( "%s%s", sTitre, sPied );


    do
    {
        //Ask the user for a sentence
        printf ( "%s", sDemande );

        //get sentence
        scanf ( "%s", sPhrase );

        //verify if the sentence is a palindrome
        iReponse = cVerifierPalindrome ( sPhrase );

        //display if its a palindrome or not
        if ( iReponse == 1 )
        {
            printf ( "%s", sPositif );
        }
        else
        {
            printf ( "%s", sNegatif );
        }

        //Does the user want to start over from the beginning?
        do
        {

            printf ( "%s", sRecommencer );

            fflush(stdin);

            scanf("%c",&cRejouer);

            fflush(stdin);

            cRejouer = toupper ( cRejouer );

            if ( cRejouer != 'O' && cRejouer != 'N' )
            {

                printf ( "%s", sPasCompris );
            }

        }
        while ( cRejouer != 'O' && cRejouer != 'N' );


    }
    //Restart the programme
    while ( cRejouer == 'O' );



#endif
#if 0
    //****************************************************************
    //-------------------------TEST DU PROGRAMME--------------------
    //****************************************************************
    //   Retourner le code d'erreur au processus appelant.

    char cMot[] = "ALLO é ? ? ! !?,YO;HEY";
    char cMot2[] = "Bonj ou r";
    char cMot3[] = "Mon cher Saint-élois";

    printf ("%s\n", cVerifierPalindrome(cMot2));


#endif
    PAUSE();
    return EXIT_SUCCESS;
}

