/*!  @file                              DigitalConverter.c
     @version                           1.00
     @brief                             This program creates temperature table of differents rooms in a house

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-10-31
     @author                            Marc-Antoine
     @note                              allows to have a visual on the ambient temperature of the house

     <hr width="100%" height="5">
 */
//** **************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\..\header\Compiler.h"

#include "..\..\header\DigitalConverter\converter.h"

//!contains piece name and temperature for the house
struct thermometer {

    char sRoom[15 + 1];
    float fTempCelsius;
    float fTempFah;
    float fTempKelvin;

};

#define NUMBER_OF_ROOMS 4

//time and date of compilation
#define TIME __TIME__
#define DATE __DATE__
//** **************************************************************************
/*!
     This program allows to the user to have a visual on the ambient temperature of the house
     @return                Error code
     @retval  EXIT_SUCCESS  no runtime error
     @retval  EXIT_FAILED   failure
 */
int houseTemp() {

    //** table titles
    char titleRooms[] = "Rooms";
    char titleCelsius[] = "Celsius";
    char titleFah[] = "Fahrenheit";
    char titleKelvin[] = "Kelvin";

    printf("HOUSE TEMPERATURE\n");
    printf("************************\n");

    //Create a thermometer-type matrix for each room
    struct thermometer t[NUMBER_OF_ROOMS];

    //Ask to the user about each room
    for (int i = 0; i < NUMBER_OF_ROOMS; i++) {


        printf("ROOM %d: ",i+1);

        //User can only input 15 character
        fgets(t[i].sRoom, 15, stdin);
        fflush(stdin);

        //Replace \n with a null character
        t[i].sRoom[strlen(t[i].sRoom)-1] = 0;

        printf("Room temperature: ");

        //store temperature
        scanf("%f", &t[i].fTempCelsius);
        fflush(stdin);

        //Conversion
        t[i].fTempFah = celsiusToFah(t[i].fTempCelsius);
        t[i].fTempKelvin = celsiusToKelvin(t[i].fTempCelsius);

    }

    //Display table
    printf("\n\n|===========================================================================================|\n");
    printf("|ROOM TEMPERATURE  (%s %s)                                                   |\n", DATE, TIME);
    printf("|-------------------------------------------------------------------------------------------|\n");
    printf("| %20s | %20s | %20s | %20s |\n", titleRooms, titleCelsius, titleFah, titleKelvin);
    printf("| -------------------- | -------------------- | -------------------- | -------------------- |\n");
    printf("| %20s | %20.2f | %20.2f | %20.2f |\n", t[0].sRoom, t[0].fTempCelsius, t[0].fTempFah, t[0].fTempKelvin);
    printf("| %20s | %20.2f | %20.2f | %20.2f |\n", t[1].sRoom, t[1].fTempCelsius, t[1].fTempFah, t[1].fTempKelvin);
    printf("| %20s | %20.2f | %20.2f | %20.2f |\n", t[2].sRoom, t[2].fTempCelsius, t[2].fTempFah, t[2].fTempKelvin);
    printf("| %20s | %20.2f | %20.2f | %20.2f |\n", t[3].sRoom, t[3].fTempCelsius, t[3].fTempFah, t[3].fTempKelvin);
    printf("|-------------------------------------------------------------------------------------------|\n");

    PAUSE();
    return (EXIT_SUCCESS);
}

