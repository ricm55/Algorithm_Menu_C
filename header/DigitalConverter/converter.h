/*!  @file                              converter.h
     @version                           1.00
     @brief                             All converter function declaration

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-10-31
     @author                            Marc-Antoine
     <hr width="100%" height="5">
 */
//** **************************************************************************

#ifndef CONVERSION_H
#define CONVERSION_H

#ifdef __cplusplus
extern "C" {
#endif

int numberToBinary(int numberToConvert, char *pBinary);
int charToBinary(int characterToConvert, char *pBinary);
int celsiusToFah(int celsius);
int celsiusToKelvin(int celsius);


#ifdef __cplusplus
}
#endif

#endif /* CONVERSION_H */

