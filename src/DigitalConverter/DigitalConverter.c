/*!  @file                              DigitalConverter.c
     @version                           1.00
     @brief                             This program can do multiple conversions

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-10-31
     @author                            Marc-Antoine
     @note                              Can now convert numbers and characters to hex, dec and bin

     <hr width="100%" height="5">
 */
//** **************************************************************************

#include <stdio.h>
#include <stdlib.h>

#include "..\..\header\Compiler.h"
#include "..\..\header\DigitalConverter\converter.h"

/*
 *
 */
int digitalConverter() {

    int convertMode = 0;
    int numToConvert = 0;
    char restartConverter = 'o';
    char charToConvert = 'a';
    //** tab to insert bit
    char binary[32+1] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

    printf("CONVERTER OF DIFFERENT DIGITAL BASES\n");
    printf("***************************************************\n\n");

    //Ask and convert
    do {
        while (convertMode != 1 && convertMode != 2) {//Demander a l'utilisateur de choisir un mode
            printf("1- Convert character\n2- Convert number\nYour conversion => ");
            scanf("%i", &convertMode);
            //empty the buffer
            fflush(stdin);

        }

        if (convertMode == 1) {

            //get the character to convert
            printf("Insert the character to convert: ");
            scanf("%c", &charToConvert);

            fflush(stdin);
            //convert character
            printf("\nCharacter '%c':\n", charToConvert);
            printf("-----------------\n");
            printf("Hex: %x\n", charToConvert);
            printf("Dec: %i\n", charToConvert);
            printf("Bin: ");

            //Convert and display the character in binairy
            charToBinary(charToConvert,binary);
            for(int i = 1;i<=32;i++){

                printf("%c", binary[i-1]);
                if(i%4 == 0){
                    printf(" ");
                }
            }
        }
        if (convertMode == 2) {
            printf("Insert the number to convert: ");
            scanf("%i", &numToConvert);

            fflush(stdin);
            //display conversions
            printf("\n\nNumber %i:", numToConvert);
            printf("\n----------");
            printf("\nDec: %i", numToConvert);
            printf("\nHex: %x", numToConvert);
            printf("\nBin: ");

            //Convert and display number in binary
            numberToBinary(numToConvert, binary);

            for(int i = 1;i<=32;i++){

                printf("%c", binary[i-1]);
                if(i %4 == 0){
                    printf(" ");
                }
            }
        }
        //Ask if the user wants to reconvert
        do{
            printf("\n\nDo you want to convert again?(O/N) ");
            scanf("%c", &restartConverter);

            fflush(stdin);
            //reinitialize the conversion mode
            convertMode = 0;
        }while(restartConverter != 'o' && restartConverter != 'O' && restartConverter != 'n' && restartConverter != 'N');
    } while (restartConverter == 'o' || restartConverter == 'O');

    PAUSE();
    return (EXIT_SUCCESS);
}

