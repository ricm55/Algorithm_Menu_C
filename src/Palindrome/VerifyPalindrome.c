/*!  @file                              VerifyPalindrome.c
     @version                           1.00
     @brief                             Can verify if a sentence is a palindrome

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2017-10-25
     @author                            Marc-Antoine
     @note                              code is complete, can now verify

     <hr width="100%" height="5">
 */
//** **************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\..\header\Palindrome\stringOperations.h"
#include "..\..\header\Palindrome\VerifyPalindrome.h"
#define TAILLE_MAX 500
//** **************************************************************************
/*!  @brief                             Can verify if a sentence is a palindrome

     @param                             userSentence user input
     @retval                            isPalindrome    return if user input is a palindrome.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2017-10-25
     @author                            Marc-Antoine Ricard
     @note                              can now detect palindrome removing accent, space and uppercase

     <hr width="100%" height="5">
 */
unsigned char* verifyPalindrome( unsigned char* userSentence )
{
    //reverse user sentence
    unsigned char pReverseSentence[TAILLE_MAX];

    //contain if the sentence is a palindrome
    int isPalindrome = 0;

    //remove all useless character (uppercase, accent...)
    userSentence = removeUppercase(removePunctuation(removeUppercase(removeAccents2(removeSpaces(userSentence)))));

    //reverse user sentence
    reverseString(userSentence, pReverseSentence);

    //Compare user sentence and reverse user sentence
    isPalindrome = stringEquals(userSentence, pReverseSentence);


    return isPalindrome;
}
