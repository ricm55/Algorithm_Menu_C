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

    char title[] = "PALINDROME TESTER\n";
    char headerLine[] =  "*********************\n\n";
    char askSentence[] = "Insert a sentence\n=> ";
    char userSentence[MAX_CHARACTERS] = "";
    char palindromeOk[] = "This sentence is a palindrome!\n";
    char notPalindrome[] = "This sentence is not a palindrome!\n";
    char askRestart[] = "Do you want to restart ? (O/N) ";
    char answerNotUnderstand[] = "I don't understand your answer...\n";
    char userRestart = 'a';
    int isPalindrome = 0;

    //Display title
    printf ( "%s%s", title, headerLine );


    do
    {
        //Ask the user for a sentence
        printf ( "%s", askSentence );

        fgets(userSentence,MAX_CHARACTERS,stdin);
        //remove the '\n' character from gets
        userSentence[strlen(userSentence)-1] = '\0';

        //verify if the sentence is a palindrome
        isPalindrome = verifyPalindrome ( userSentence );

        //display if its a palindrome or not
        if ( isPalindrome == 1 )
        {
            printf ( "%s", palindromeOk );
        }
        else
        {
            printf ( "%s", notPalindrome );
        }

        //Does the user want to start over from the beginning?
        do
        {

            printf ( "%s", askRestart );

            fflush(stdin);

            scanf("%c",&userRestart);

            fflush(stdin);

            userRestart = toupper ( userRestart );

            if ( userRestart != 'O' && userRestart != 'N' )
            {

                printf ( "%s", answerNotUnderstand );
            }

        }
        while ( userRestart != 'O' && userRestart != 'N' );


    }
    //Restart the programme
    while ( userRestart == 'O' );



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

