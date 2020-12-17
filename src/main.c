/*! @file                              main.c
    @version                           1.00
    @brief                             This main file contains menu management which allows
                                       the user to choose the program to run, stop it, and
                                       left the program.


     <hr width="100%" height="5">
     <b>History</b>
     <hr width="100%" height="1">
     @date                              2020-10-31
     @author                            Marc-Antoine Ricard
     @note                              Create the main menu which allows the user to choose which program to launch

     <hr width="100%" height="5">
 */
//** **************************************************************************


#include <stdio.h> /* printf, */
#include <stdlib.h> /* EXIT_SUCCESS, system*/

#include <ctype.h> /* toupper, */


#include "..\header\keyboard.h" /*K_F10, */
#include "..\header\Compiler.h" /*CLEAR_SCREEN */
#include "..\header\ASCII.h"

#include "..\header\Menu.h" /* Test1, Test2, */

#include "..\header\SubscribeTvProgram\TVshowManager.h"
#include "..\header\DigitalConverter\digitalConverter.h"

//Some algorithm coming soon...
/*#include "Palindrome.h"
#include "Thermo.h"
#include "JeuPendu.h"
*/

//Create the algorithm choice menu
static TMenu Menu [] = {


    {'A', "Run test 1", Test1 },
    {'B', "Run Test 2", Test2 },
    {'C', "View your television subscription", TVshowManager},
    {'D', "Convert integers or characters in different digital base", digitalConverter },
    /*{'E', "Verifier si une chaine est un palindrome", Palindrome },

    {'F', "Verifier la temperature passante dans la maison", Thermo },
    {'G', "Un programme qui fait rien", ProgrammeFaitRien },
    {'H', "Le programme qui crash (Pas recommande)", ProgrammeCrash },
    {'I', "Le jeu du pendu", JeuPendu },*/
};

//calculate the number of items in the menu
static unsigned int iNbElementMenu = sizeof ( Menu ) / sizeof ( struct TMenu );

//** **************************************************************************
/*!
     The main program can display the algorithm menu and manage it
     @param   argc          Number of argument on the command line
     @param   argv          User's strings pass in argument of this program
     @return                Error code
     @retval  EXIT_SUCCESS  no runtime error
     @retval  EXIT_FAILED   failure
 */
int main ( int argc, char* argv[] )
{

    //** Menu formatting
    char cTitre[] = "Algorithm Menu (F10 to quit)\n";
    char cPied[] =  "****************************\n";
    char cAttendre[5] = "\n=> ";
    char cArret[] = "Program stop\n";
    int i = 0;

    //** Can store the user input
    char cChoix = 0;
    int iTouche = 0;


    //display date and time
    printf ( "%s %s\n\n", __DATE__, __TIME__ );

    //F10 to get out of this program
    while ( iTouche != K_F10 )
    {

        //Display the menu
        printf ( "%s%s", cTitre, cPied );

        //Display the menu for each algorithm
        for ( i = 0; i < iNbElementMenu; i++ )
        {

            printf ( "%c     %s\n", Menu[i].Touche, Menu[i].Description );
        }

        printf ( "%s", cAttendre );

        //Wait for the user input
        cChoix = getch ( );


        if ( cChoix == 0 || cChoix == 224 )
        {
            iTouche = getch ( );

        }
        else
        {

            //Clear buffer
            fflush ( stdin );

            //Capitalize the character
            cChoix = toupper ( cChoix );

            //Find which program the user want to run
            for ( i = 0; i < iNbElementMenu && cChoix != Menu[i].Touche; i++ );


            //If the character is in the menu
            if ( i < iNbElementMenu )
            {

                //clear the screen
                CLEAR_SCREEN ( );

                //Run the program
                Menu[i].pFct ( );

            }
            else
            {

                CLEAR_SCREEN ( );
                printf ( "Invalide option\n" );
                PAUSE ( );
            }

        }

        CLEAR_SCREEN ( );
    }

    printf ( "%s", cArret );

    return EXIT_SUCCESS;
}
