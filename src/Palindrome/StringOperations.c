/*!  @file                              StringOperations.c
     @version                           1.00
     @brief                             this library obtain many operation about strings

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2017-10-25
     @author                            Marc-Antoine
     @note                              Many operation on strings can be done

     <hr width="100%" height="5">
 */
//** **************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\..\header\Palindrome\StringOperations.h"

#define TAILLE_MAX 500
//** **************************************************************************
/*!  @brief                             remove all spaces in a string
     @param                             userSentence string to remove space
     @retval                            userSentenceMod    new string without spaces
 */
unsigned char* removeSpaces ( unsigned char* userSentence )
{
    //**string that contains only space
    char* userSentenceMod = NULL;

    //index to memorize character shifting
    int countCharacter = 0;

    //the content of the user's string is associated to another pointer
    userSentenceMod = userSentence;

    //analyze each character
    while ( *userSentence != NULL )
    {
        //printf("In boucle => %c\n",*userSentence);
        //Verify if the character is a space
        if ( *userSentence != ' ' )
        {
            //put the character in the new string
            *userSentenceMod = *userSentence;

        }

        //go to the next character
        userSentenceMod++;
        userSentence++;
        //count the number of place characters
        countCharacter++;

    }
    //Last character is NULL
    *userSentenceMod = NULL;

    //Reset the pointer to the beginning of the string
    userSentenceMod -= countCharacter;

    //Return the user string without spaces
    return userSentenceMod;

}
//** **************************************************************************
/*!  @brief                             remove all uppercase in a string
     @param                             userSentence string to remove uppercase
     @retval                            userSentenceMod    new string without uppercase
 */
unsigned char* removeUppercase ( unsigned char* userSentence )
{
    //**string that contain only lowercase character
    unsigned char* userSentenceMod = NULL;

    //store user sentence in the new sentence
    userSentenceMod = userSentence;

    //index to memorize character shifting
    int countCharacter = 0;

    //browse each character
    while ( *userSentence != NULL )
    {
        //verify if the character is uppercase
        if ( *userSentence >= 65 && *userSentence <= 90 )
        {
            //convert to lowercase
            *userSentenceMod += 32;
        }
        else
        {
            //put the character in the new string
            *userSentenceMod = *userSentence;
        }

        //go to the next character
        userSentenceMod++;
        userSentence++;

        //count the number of place characters
        countCharacter++;
    }

    //Last character is NULL
    *userSentenceMod = NULL;

    //Reset the pointer to the beginning of the string
    userSentenceMod -= countCharacter;

    //return the string
    return userSentenceMod;

}
//** **************************************************************************
/*!  @brief                             remove all punctuation in a string
     @param                             userSentence string to remove punctuation
     @retval                            userSentenceMod    new string without punctuation
 */
unsigned char* removePunctuation ( unsigned char* userSentence )
{
    //**string that does not contain punctuation
    unsigned char* userSentenceMod = NULL;

    //index to memorize character shifting
    int countCharacter = 0;

    //store user sentence in the new sentence
    userSentenceMod = userSentence;

    //browse each character
    while ( *userSentence != NULL )
    {
        //verify if the character is a punctuation
        while ( *userSentence == '.' || *userSentence == ',' || *userSentence == '!' ||
               *userSentence == '?' || *userSentence == ';' || *userSentence == ':' ||
               *userSentence == '-' || *userSentence == '_' || *userSentence == 34 ||
               *userSentence == 39 )
        {
            //go to the next character
            userSentence++;
        }

        //put the character in the new string
        *userSentenceMod = *userSentence;

        //go to the next character
        userSentenceMod++;
        userSentence++;

        //count the number of place characters
        countCharacter++;

    }

    //Last character is NULL
    *userSentenceMod = NULL;

    //Reset the pointer to the beginning of the string
    userSentenceMod -= countCharacter;

    //return user sentence without punctuation
    return userSentenceMod;

}
//** **************************************************************************
/*!  @brief                             remove all accents in a string
     @param                             userSentence string to remove accents
     @retval                            userSentence    new string without accents
 */
unsigned char* removeAccents ( unsigned char *userSentence )
{

    //All accents that we want to remove
    char accentCharacters[2][27] = {
        {'ב', 'ג', 'ה', 'ח', 'י', 'כ', 'ם', 'מ', 'ף', 'פ', 'צ', 'ת', 'ü', '‎', 'ֱ', 'ֲ', 'ִ', '׃', 'װ', 'ײ', 'ֹ', 'ֻ', 'ֽ', '־', 'Ú', 'Ü', 'ַ' },
        {'a', 'a', 'a', 'c', 'e', 'e', 'i', 'i', 'o', 'o', 'o', 'u', 'u', 'y', 'A', 'A', 'A', 'O', 'O', 'O', 'E', 'E', 'I', 'I', 'U', 'U', 'C' }
    };

    //index to memorize character shifting
    int countCharacter = 0;

    //browse each character
    while ( *userSentence != NULL )
    {
        //verify if the character has an accent
        for ( int i = 0; i < 27; i++ )
        {
            if ( *userSentence == accentCharacters[0][i] )
            {
                //replace the accent character with his equivalent
                *userSentence = accentCharacters[1][i];
            }

        }
        //go to the next character
        userSentence++;

        //count the number of place characters
        countCharacter++;
    }

    //Reset the pointer to the beginning of the string
    userSentence -= countCharacter;

    //return user sentence without accent
    return userSentence;

}
//** **************************************************************************
/*!  @brief                             reverse a string
     @param                             userSentenceUtilisateur string to reverse
     @param                             pReverseSentence string to store the reverse string
     @retval                            pReverseSentence    new reverse string
 */
unsigned char reverseString ( unsigned char* userSentenceUtilisateur, unsigned char* pReverseSentence )
{
    //define the size of the user's string
    int iTailleTab = strlen ( userSentenceUtilisateur );

    //define the index to browse the array
    int iIndex = iTailleTab - 1;

    //browse each character
    for ( int i = 0; i < iTailleTab; i++ )
    {

        //Put the last character of the user sentence in the first character of the reverse sentence
        pReverseSentence[i] = userSentenceUtilisateur[iIndex];

        //go to the next character
        iIndex--;

    }
    //Last character is NULL
    pReverseSentence[iTailleTab] = NULL;

    //Return the reverse sentence
    return pReverseSentence;

}
//** **************************************************************************
/*!  @brief                             verify if two strings are equals
     @param                             userSentence string to compare
     @param                             pReverseSentence string to compare
     @retval                            boolean    0:different 1:equals
 */
int stringEquals ( char* userSentence, char* pReverseSentence )
{
    //Define user sentence length
    int userStringSize = ( strlen ( userSentence ) + strlen ( pReverseSentence ) ) / 2;


    //Browse each character
    for ( int i = 0; i < userStringSize; i++ )
    {
        //verify if the characters are equals
        if ( *userSentence != *pReverseSentence )
        {
            //return false
            return 0;

        }

        //go to the next character
        userSentence++;
        pReverseSentence++;

    }

    //return true
    return 1;
}
//** **************************************************************************
/*!  @brief                             remove all accents in a string  (2nd algorithm)
     @param                             userSentence string to remove accents
     @retval                            p    new string without accents
 */
char* removeAccents2 ( unsigned char *userSentence ){

    char* p = userSentence;
    unsigned char correspondenceTable1[] =
        /*  "ַüיגה??ח?כ??מ?ִ?ֹ??פ" */
        "CueaaaaceeeiiiAAE??ooouuyOU";
    unsigned char correspondenceTable2[] =
        "aiounN";
    unsigned char correspondenceTable3[] =
        "AAA";
    unsigned char correspondenceTable4[] =
        "aA";
    unsigned char correspondenceTable5[] =
        "EEE";
    unsigned char correspondenceTable6[] =
        "obOOoO";
    unsigned char correspondenceTable7[] =
        "UUUyY";



    while ( *userSentence != 0 )
    {

        if ( *userSentence >= 128 && *userSentence <= 154 )
        {
            *userSentence = correspondenceTable1[*userSentence - 128];
        }
        else if ( *userSentence >= 160 && *userSentence <= 165 )
        {
            *userSentence = correspondenceTable2[*userSentence - 160 ];
        }
        else if ( *userSentence >= 181 && *userSentence <= 183 )
        {
            *userSentence = correspondenceTable3[*userSentence - 181];
        }
        else if ( *userSentence >= 198 && *userSentence <= 199 )
        {
            *userSentence = correspondenceTable4[*userSentence - 198];
        }
        else if ( *userSentence >= 210 && *userSentence <= 212 )
        {
            *userSentence = correspondenceTable5[*userSentence - 210];
        }
        else if ( *userSentence >= 224 && *userSentence <= 229 )
        {
            *userSentence = correspondenceTable6[*userSentence - 224];
        }
        else if ( *userSentence >= 233 && *userSentence <= 237 )
        {
            *userSentence = correspondenceTable7[*userSentence - 233];
        }

        userSentence++;


    }

    return p;
}
