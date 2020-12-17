/*!  @file                              converter.c
     @version                           1.00
     @brief                             Several functions that can convert

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-10-31
     @author                            Marc-Antoine
     @note                              Many value can be convert

     <hr width="100%" height="5">
 */
//** **************************************************************************
#include "..\..\header\DigitalConverter\converter.h"

//** **************************************************************************
/*!
     Converter number --> binary
     @param   numberToConvert      number to convert
     @param   pBinary              stock binary bits
     @retval  Error Code           0
 */
int numberToBinary(int numberToConvert, char *pBinary) {

    int mask = 1 << (sizeof(int)*8 -1);

    for(int i = 0; i<(sizeof(int)*8);i++) {//Inserer un bit à chaque tour de boucle


        if((numberToConvert & mask) ==0){//Inserer les bits dependament du masque
            *pBinary = '0';
        }
        else{
            *pBinary = '1';
        }
        pBinary++;

        numberToConvert = numberToConvert << 1;

    }
    *pBinary = 0;

    return 0;
}
//** **************************************************************************
/*!
     Converter character --> binary (same code as the previous one, dont know why I have the same function)
     @param   characterToConvert      character to convert
     @param   pBinary                 stock binary bits
     @retval  Error Code              0
 */
int charToBinary(int characterToConvert, char *pBinary) {

    int mask = 1 << (sizeof (int) * 8 - 1);


    //store one bit at a time
    for(int i = 0; i<(sizeof(int)*8);i++) {


        if((characterToConvert & mask) ==0){
            *pBinary = '0';
        }
        else{
            *pBinary = '1';
        }

        pBinary++;
        characterToConvert = characterToConvert << 1;



    }
    *pBinary = 0;
    return 0;
}

//** **************************************************************************
/*!
     Converter celsius --> Fahrenheit
     @param   celsius      celsius to convert
     @retval  fah          degrees in fahrenheit
 */
int celsiusToFah(int celsius){

     int fah =( celsius * 1.8 ) + 32;
     return fah;
}
//** **************************************************************************
/*!
     Converter celsius --> Kelvin
     @param   celsius      celsius to convert
     @retval  kelvin       degrees in kelvin
 */
int celsiusToKelvin(int celsius){

    int kelvin = celsius + 273.15;
    return kelvin;
}



