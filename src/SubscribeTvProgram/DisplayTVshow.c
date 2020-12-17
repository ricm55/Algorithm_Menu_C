/*!  @file                              DisplayTVshow.h
     @version                           1.00
     @brief                             This program can display customer's television subscription

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-10-31
     @author                            Marc-Antoine
     @note                              Ask and display television subscription

     <hr width="100%" height="5">
 */
//** **************************************************************************

#include "..\..\header\SubscribeTvProgram\DisplayTVshow.h"

//** **************************************************************************
/*!
     This program display the customer subscription
     @param   subscription      Subscription number
     @param   tvSet[]          TV show information
     @retval  Error Code       0
 */
int DisplayTvSet ( int subscription, int* tvSet )
{
    printf ( "\n====================================================\n" );
    printf ( "%5s%8s%10s%7s%8s\n","set","Date","start","end","Mode");
    printf ( "----------------------------------------------------\n" );

    int p = 0;
    while ( tvSet[p] != -1 )
    {

        if ( ( subscription == 0 && tvSet[p] <= 16 ) ||
             ( subscription == 1 && tvSet[p] <= 26 ) ||
             ( subscription == 2 && tvSet[p] <= 40 ) )
        {
            printf ( "%5i %4i-%02i-%02i %3.2i:%2.2i %4.2i:%2.2i %4i\n",
                     tvSet[p], tvSet[p + 1], tvSet[p + 2], tvSet[p + 3],
                     tvSet[p + 4] / 60, tvSet[p + 4] % 60,
                     tvSet[p + 5] / 60, tvSet[p + 5] % 60, tvSet[p + 6] );


        }

        p += 7;

    }
    return 0;
}
