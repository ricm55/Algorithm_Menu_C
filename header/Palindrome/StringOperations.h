/*!  @file                              StringOperations.h
     @version                           1.00
     @brief                             Declaration of string operations

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-10-31
     @author                            Marc-Antoine
     <hr width="100%" height="5">
 */
 //** **************************************************************************

#ifndef TRAITERCHAINECARACTERES_H
#define TRAITERCHAINECARACTERES_H


#ifdef __cplusplus
extern "C"
{
#endif


    unsigned char* removeSpaces ( unsigned char* userSentence );
    unsigned char* removeUppercase ( unsigned char* userSentence );
    unsigned char* removePunctuation ( unsigned char* userSentence );
    unsigned char* removeAccents ( unsigned char *userSentence );
    char* removeAccents2 ( unsigned char *userSentence );
    unsigned char reverseString ( unsigned char* cChaineUtilisateur, unsigned char* pChaineInverse );
    int stringEquals ( char* userSentence, char* pChaineInverse );



#ifdef __cplusplus
}
#endif

#endif /* TRAITERCHAINECARACTERES_H */

