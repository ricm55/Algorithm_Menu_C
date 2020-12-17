/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TraiterChaineCaractere.h
 * Author: User
 *
 * Created on October 25, 2017, 9:33 AM
 */

#ifndef TRAITERCHAINECARACTERES_H
#define TRAITERCHAINECARACTERES_H


#ifdef __cplusplus
extern "C"
{
#endif


    unsigned char* cEliminerEspaces ( unsigned char* pChaine );
    unsigned char* cEliminerMajuscules ( unsigned char* pChaine );
    unsigned char* cEliminerPonctuation ( unsigned char* pChaine );
    unsigned char* cEnleverAccents ( unsigned char *pChaine );
    unsigned char cInversionChaine ( unsigned char* cChaineUtilisateur, unsigned char* pChaineInverse );
    int iComparerChaine ( char* pChaine, char* pChaineInverse );
    


#ifdef __cplusplus
}
#endif

#endif /* TRAITERCHAINECARACTERES_H */

