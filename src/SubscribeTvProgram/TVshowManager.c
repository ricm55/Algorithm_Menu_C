/*!  @file                              TVshowManager.c
     @version                           1.00
     @brief                             This program simulate a TV subscription

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2017-09-07
     @author                            Marc-Antoine
     @note                              It can display TV set according to user subscription

     <hr width="100%" height="5">
 */
//** **************************************************************************

#include <stdio.h>
#include <stdlib.h>

#include "..\..\header\Compiler.h"/*PAUSE()*/

#include "..\..\header\SubscribeTvProgram/DisplayTVshow.h"
//** **************************************************************************
/*!
     This program can display TV set according to user subscription
     @return                Error code
     @retval  EXIT_SUCCESS  no runtime error
     @retval  EXIT_FAILED   failure
 */
int TVshowManager ()
{

    int subscription = 0;

    //TV schedule set, year, month, day, start, end, mode
    int tvSet[] = {6,  2010,   8,   22,   450,  510,  1,
                   12, 2010,   8,   30,   1020, 1080, 1,
                   16, 2010,   8,   28,   1140, 1170, 0,
                   24, 2011,   8,   26,   1140, 1170, 0,
                   26, 2010,   8,   18,   450,  510,  1,
                   40, 2010,   8,   22,   450,  510,  1,
                   -1};

    //Display title
    printf("*********************************\n");
    printf("What TV set are you allowed to watch?\n");
    printf("Enter your subscription:\n=> 0\n=> 1\n=> 2\n");
    printf("*********************************\n");

    //Ask subscription
    do
    {
        printf ( "Your subscription: " );
        scanf ( "%i", &subscription );
        if ( subscription > 2 )
        {
            printf ( "This subscription does not exist\n" );
        }

    }
    while ( subscription != 0 && subscription != 1 && subscription != 2 );

    //Display customer subscription
    DisplayTvSet( subscription, tvSet );

    PAUSE();
    return (EXIT_SUCCESS );
}

