/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\..\header\Palindrome\TraiterChaineCaracteres.h"

#define TAILLE_MAX 500
unsigned char* cEliminerEspaces ( unsigned char* pChaine )
{

    char* pChaineMod = NULL; //Declarer l'espace de stockage de la chaine sans espace
    int iDeplacement = 0; //Declarer les deplacements des caracteres

    pChaineMod = pChaine; //Le contenu de la chaine de l'utilisateur est associe a celui de la chaine modifie

    while ( *pChaine != NULL )//Tant que la valeur de la chaine n'est pas egale a NULL
    {
        if ( *pChaine == ' ' )//Si la valeur du caractere de la chaine est un egale
        {
            pChaine++; //Incrementer le caractere de la chaine de l'utilisateur
        }
        else//Sinon inserer la lettre dans la nouvelle chaine
        {

            *pChaineMod = *pChaine; //La valeur du caractere de la chaine modifie est egale a la valeur de la chaine d'utilisateur
            pChaineMod++; //Incrementer le caractere de la chaine modifie
            iDeplacement++; //Incrementer le deplacement
            pChaine++; //Incrementer le caractere de la chaine de l'utilisateur pour passer au suivant
        }
    }//Findutantque

    *pChaineMod = NULL; //Mettre le 0 a la fin de la chaine de caractere

    pChaineMod -= iDeplacement; //Replacer l'endroit de stockage au debut de la chaine

    //printf ( "Fin de la fonction EliminerEspaces: %s\n", pChaineMod );
    return pChaineMod; //Retourner la chaine sans espace

}
unsigned char* cEliminerMajuscules ( unsigned char* pChaine )
{

    unsigned char* pChaineMod = NULL; //Creer le pointeur vers chaine modifie

    pChaineMod = pChaine; //Egaliser la chaine modifie a la chaine de l'utilisateur

    int Deplacement = 0; //Enregistrer les deplacements dans la chaine

    while ( *pChaine != NULL )//Tant qu'on pointe pas le nul de la chaine.
    {
        if ( *pChaine >= 65 && *pChaine <= 90 )//Si le caractere est une lettre majuscule
        {
            *pChaineMod += 32; //Convertir en minuscule
        }
        else//Sinon
        {
            *pChaineMod = *pChaine; //Egaliser le caractere de la chaine modifie a la chaine saisi
        }
        pChaineMod++; //Incrementer la chaine modifie

        pChaine++; //Incrementer le caractere de la chaine de l'utilisateur

        Deplacement++; //Incrementer le nombre de deplacement a effectuer
    }

    *pChaineMod = NULL; //Mettre le 0 a la fin de la chaine modifie
    pChaineMod -= Deplacement; //Revenir au debut de la chaine

    //printf ( "Fin de la fonction EliminerMajuscules: %s\n", pChaineMod );
    return pChaineMod; //Retourner la chaine modifie

}
unsigned char* cEliminerPonctuation ( unsigned char* pChaine )
{

    unsigned char* pChaineMod = NULL; //Creer un espace pour la chaine modifie

    int Deplacement = 0; //Enregistrer le deplacement des caracteres

    pChaineMod = pChaine; //Egaliser la chaine modifie avec la chaine original

    while ( *pChaine != NULL )//Tant que la chaine original n'est pas fini
    {
        while ( *pChaine == '.' || *pChaine == ',' || *pChaine == '!' || *pChaine == '?' || *pChaine == ';' || *pChaine == ':' || *pChaine == '-' || *pChaine == '_' || *pChaine == 34 || *pChaine == 39 )
        {//Tant que le caractere est une ponctuation

            pChaine++; //Incremente le caractere de la chaine
        }

        *pChaineMod = *pChaine; //Egaliser le caractere de la chaine modifie a la chaine original

        pChaineMod++;

        Deplacement++;
        pChaine++;

    }//Findutantque

    *pChaineMod = 0;

    pChaineMod -= Deplacement;

    //printf ( "Fin de la fonction EliminerPonctuation: %s\n", pChaineMod );
    return pChaineMod; //retourner la chaine sans ponctuation

}
unsigned char* cEnleverAccents ( unsigned char *pChaine )
{

    //Creer un espace avec tous les accents et leur equivalent sans celui-ci
    char cCaractere[2][27] = {
        {'ב', 'ג', 'ה', 'ח', 'י', 'כ', 'ם', 'מ', 'ף', 'פ', 'צ', 'ת', 'ü', '‎', 'ֱ', 'ֲ', 'ִ', '׃', 'װ', 'ײ', 'ֹ', 'ֻ', 'ֽ', '־', 'Ú', 'Ü', 'ַ' },
        {'a', 'a', 'a', 'c', 'e', 'e', 'i', 'i', 'o', 'o', 'o', 'u', 'u', 'y', 'A', 'A', 'A', 'O', 'O', 'O', 'E', 'E', 'I', 'I', 'U', 'U', 'C' }
    };


    int iDeplacement = 0; //Enregistrer le deplacement

    while ( *pChaine != NULL )
    {//Tant que la chaine originale n'est pas fini


        for ( int i = 0; i < 27; i++ )//Tester un seul caractere
        {//Pour tout les accents en commencant pas le premier faire
            //printf ( "Caractere analyse: %c\n", *pChaine );
            //printf ( "Recherche dans le tableau: %c\n", cCaractere[0][i] );

            if ( *pChaine == cCaractere[0][i] )
            {//Si l'accent est egale au caractere
                //printf ( "Detection du caractere accentue: %c\n", *pChaine );
                *pChaine = cCaractere[1][i]; //Remplacer l'accent par son equivalent
                //printf ( "C'est maintenant devenu: %c\n", *pChaine );

            }

        }

        pChaine++; //Incrementer le caractere de la chaine

        iDeplacement++; //Ajouter 1 de deplacement
    }//Findutantque

    pChaine -= iDeplacement; //Retourner au debut de la chaine

    //printf ( "Fin de la fonction EnleverAccent: %s\n", pChaine );
    return pChaine; //Retourner la chaine sans accent

}
unsigned char cInversionChaine ( unsigned char* pChaineUtilisateur, unsigned char* pChaineInverse )
{//Pseudo-code pour la fonction d'inversion de chaines de caractere.



    int iTailleTab = strlen ( pChaineUtilisateur ); //definir la taille de la chaine de l'utilisateur

    int iIndex = iTailleTab - 1; //Definir l'index donc -1 pour le tableau


    for ( int i = 0; i < iTailleTab; i++ )
    {//Pour chaque caractere dans la chaine de l'utilisateur faire
        //printf ( "Chaine utilisateur: %s\n", pChaineUtilisateur );

        //mettre le dernier caractere de la chaine d'utilisateur dans le premier de la chaine inverse

        pChaineInverse[i] = pChaineUtilisateur[iIndex];

        iIndex--; //Reduire l'index
        //printf ( "chaine inverse en construction: %s\n", pChaineInverse );
        // printf("Chaine inverse: %c\n", cChaineInverse[i]);
    }//findupour

    pChaineInverse[iTailleTab] = NULL; //Mettre le zero a la fin de la chaine inverse
    //pChaineInverse[0] = pChaineUtilisateur[iIndex];
    //printf ( "Chaine inverse a la fin de la fonction: %s", pChaineInverse );


    return pChaineInverse; //Retourner la chaine inverse

}
int iComparerChaine ( char* pChaine, char* pChaineInverse )
{
    //Definir la longueur de la chaine
    int iLongueurDeChaine = ( strlen ( pChaine ) + strlen ( pChaineInverse ) ) / 2;


    //Pour chaque addresse allant de 1 a la longueur totale de la chaine initiale
    for ( int i = 0; i < iLongueurDeChaine; i++ )

    {
        //Si le caractere n'est pas egale au caractere de la chaine inverse
        if ( *pChaine != *pChaineInverse )
        {

            return 0; //  Retourner Faux

        }//Findusi

        pChaine++; //Incrementer les caracteres afin de tester les autres
        pChaineInverse++;

    }//Findupour


    return 1; // Retourner Vrai
}
char* ElimineAccents ( unsigned char *pChaine ){

    char* p = pChaine;
    unsigned char TableCorrespondance1[] =
        /*  "ַüיגה??ח?כ??מ?ִ?ֹ??פ" */
        "CueaaaaceeeiiiAAE??ooouuyOU";
    unsigned char TableCorrespondance2[] =
        "aiounN";
    unsigned char TableCorrespondance3[] =
        "AAA";
    unsigned char TableCorrespondance4[] =
        "aA";
    unsigned char TableCorrespondance5[] =
        "EEE";
    unsigned char TableCorrespondance6[] =
        "obOOoO";
    unsigned char TableCorrespondance7[] =
        "UUUyY";



    while ( *pChaine != 0 )
    {
        //printf( "[%c]=>", *Chaine );

        if ( *pChaine >= 128 && *pChaine <= 154 )
        {
            *pChaine = TableCorrespondance1[*pChaine - 128];
        }
        else if ( *pChaine >= 160 && *pChaine <= 165 )
        {
            *pChaine = TableCorrespondance2[*pChaine - 160 ];
        }
        else if ( *pChaine >= 181 && *pChaine <= 183 )
        {
            *pChaine = TableCorrespondance3[*pChaine - 181];
        }
        else if ( *pChaine >= 198 && *pChaine <= 199 )
        {
            *pChaine = TableCorrespondance4[*pChaine - 198];
        }
        else if ( *pChaine >= 210 && *pChaine <= 212 )
        {
            *pChaine = TableCorrespondance5[*pChaine - 210];
        }
        else if ( *pChaine >= 224 && *pChaine <= 229 )
        {
            *pChaine = TableCorrespondance6[*pChaine - 224];
        }
        else if ( *pChaine >= 233 && *pChaine <= 237 )
        {
            *pChaine = TableCorrespondance7[*pChaine - 233];
        }

        pChaine++;


    }

    return p;
}
