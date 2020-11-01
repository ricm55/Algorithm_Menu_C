/*!  @file                              Compiler.h
     @version                           1.00
     @brief                             Déclaration de macros d'adaptation à l'environnement de développment.

     @note                              ANSI.SYS [pour DOS ou l'équivalent sur un autre environnement], un sous-ensemble de la
                                        norme ANSI 3.64-1979), doit être installé pour utiliser le groupe de macro-instructions
                                        génériques (__GENERIC__).

                                        Sous DOS, dans le fichier CONFIG.SYS, la commande pour installer ANSI.SYS est:
                                           device=c:\command\ansi.sys
                                        où "command" est le dossier où se trouve ansi.sys avec le système d'exploitation utilisé.

                                        Sous Windows 95 ou 98, dans le fichier CONFIG.SYS, la commande devient:
                                           device=c:\windows\command\ansi.sys
                                        où "windows" est le dossier où se trouve le système d'exploitation Windows.

     @internal

     @note                              Liste des macro-instructions dans ce fichier de déclaration:
         =================================================================================================================
         Identificateur              Identificateur            Description de l'opération réalisée
         en français                 en anglais
         -----------------------------------------------------------------------------------------------------------------
         PAUSE()                                               Attendre que l'utilisateur appuie sur une touche du clavier.
         PAUSE_MSG(Msg)                                        Afficher le message spécifié à l'écran et attendre que
                                                               l'utilisateur appuie sur une touche du clavier
         EFFACER_ECRAN()             CLEAR_SCREEN()            Effacer le contenu de l'écran.
         DEPLACER_CURSEUR(r,c)       MOVE_CURSOR(r,c)          Déplacer le curseur à la position spécifiée.
         EFFACER_FIN_LIGNE()         ERASE_END_OF_LINE()       Effacer de la position du curseur à la fin de la ligne.
         CACHER_CURSEUR()            HIDE_CURSOR()             Cacher le curseur (le rendre invisible).
         MONTRER_CURSEUR             SHOW_CURSOR()             Montrer le curseur (le rendre visible).
         SUPPRIMER_LIGNE_COURANTE()  DELETE_CURRENT_LINE()     Supprimer la ligne à la position du curseur de l'écran.
         INSERER_LIGNE()             INSERT_LINE()             Insérer une ligne à la position du curseur à l'écran.
         OUVRIR_FENETRE()            OPEN_SCREEN()             Ouvrir (créer) une fenêtre à l'écran.
         FERMER_FENETRE()            CLOSE_SCREEN()            Fermer (supprimer) la fenêtre de l'écran.
         -----------------------------------------------------------------------------------------------------------------

     @note                              Les environnements de développement ajoutent automatiquement une déclaration (macros)
                                        indiquant le compilateur utilisé. Ces macros sont utilisés pour déterminer
                                        la version des macro-instructions à utiliser de ce fichier de déclarations.

                                        Déclarations permettant d'identifier l'environnement de développement:
         =================================================================================================================
                  Compilateur                        |  Macros
         -----------------------------------------------------------------------------------------------------------------
         Identificateur | Description                |  Nom de la routine
         =================================================================================================================
         à utiliser       peu importe                  __FUNCTION_NAME__
         -----------------------------------------------------------------------------------------------------------------
         __GENERIC__      Aucun spécifié
                          (il faut ajouter cette
                          déclaration à vos fichiers)
         __BORLANDC__     Borland C/C++
         __TURBOC__       Borland Turbo C/C++
         __CODEGEARC__    C++ Builder 2006
         __GNUC__         gcc                          __FUNCTION__ ou
         __GNUC__         gcc                          __PRETTY_FUNCTION__
                                                       (nom long)
         __MSC__          Microsoft C /
                          MS Visual Studio 2015
         _MSC_VER         N° version du compilateur    __FUNCTION__ (si WIN32)
                                                       __func__     (sinon)
         _MSC_FULL_VER    N° version du compilateur
                          (si >=6.0 SP6)
         __SC__           Symantec C/C++               __func__
         __CC_ARM         ARM Compiler                 __func__
         __MINGW32__      MingGW                       __FUNCTION__
         __MINGW64__      MingW-w64                    __FUNCTION__
         ---------------- Version ----------------------------------------------------------------------------------------
         __cplusplus      >= 201103L                   __FUNC__
         __cplusplus      >= 201103L                   __func__ (?)
         __STDC_VERSION__ >= 199409L                   __func__
         =================================================================================================================
		 La macro pour l'identification de la routine est déclarée par le traducteur dès l'accolade d'ouverture de la routine.
         Par exemple:
 			 static const char __func__[] = "function-name";

     @note                              Déclarations permettant d'identifier la version active de la norme:
         =================================================================================================================
         Version de    Macro               = Valeur            Signification
         la norme                            (const long int)  (nom complet de la version de la norme)
         -----------------------------------------------------------------------------------------------------------------
         C89           __STDC__ 	                           ANSI X3.159-1989
         C90           __STDC__ 	                           ISO/IEC 9899:1990
         C94           __STDC_VERSION__    = 199409L 	       ISO/IEC 9899-1:1994
         C99           __STDC_VERSION__    = 199901L 	       ISO/IEC 9899:1999
         C11           __STDC_VERSION__    = 201112L 	       ISO/IEC 9899:2011
         C++98         __cplusplus         = 199711L 	       ISO/IEC 14882:1998
         C++11         __cplusplus         = 201103L 	       ISO/IEC 14882:2011
         C++14         __cplusplus         = 201402L 	       ISO/IEC 14882:2014
         C++/CLI       __cplusplus_cli     = 200406L 	       ECMA-372
         DSP-C                                                 ISO/IEC JTC1/SC22 WG14/N854
         EC++          __embedded_cplusplus 	               Embedded C++
         =================================================================================================================
         Format de la valeur: yyyymmL
         où                   yyyy     année
                              mm       mois

     @note                              Déclarations permettant d'identifier le système cible:
         =================================================================================================================
         Identification      Version           Système cible         Codage de la version
         -----------------------------------------------------------------------------------------------------------------
         __ANDROID__         __ANDROID_API__   Android
         _AIX                                  AIX                   _AIX'VR' où	V = Version  R = Revision
         __TOS_AIX__
         =================================================================================================================

     @note                              Exemple d'utilisation:
		#if defined(__STDC__)
		#    define PREDEF_STANDARD_C_1989
		#    if defined(__STDC_VERSION__)
		#        if (__STDC_VERSION__ >= 199409L)
		#            define PREDEF_STANDARD_C_1994
		#        endif
		#        if (__STDC_VERSION__ >= 199901L)
		#            define PREDEF_STANDARD_C_1999
		#        endif
		#    endif
		#endif

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              1998-11-05
     @author                            Denis Lavoie
     @note                              Entrée du code.

     <hr width="100%" height="1">
     @date                              2000-10-25
     @author                            Révision (langue et commentaire) et ajout des macro-instructions génériques.
     @note                              Entrée du code.

     <hr width="100%" height="1">
     @date                              2002-09-23
     @author                            Ajout de la taille des types.
     @note                              Entrée du code.

     <hr width="100%" height="1">
     @date                              2016-04-05
     @author                            Denis Lavoie
     @note                              Ajout de __FUNCTION_NAME__ (pour normaliser le nom de la routine).

     <hr width="100%" height="1">
     @date                              2017-11-07
     @author                            Denis Lavoie
     @note                              Mise-à-jour de la documentation.
                                        Ajout de __FUNCTION_NAME__ pour gcc.

     <hr width="100%" height="5">
 */
//** **************************************************************************

#ifndef COMPILER_H                      //## Si ce fichier de déclarations n'est pas déjà inclu
#define COMPILER_H                      //## Déclarer le fichier.

#ifdef __cplusplus
extern "C"
{
#endif

//** **************************************************************************************************************
//** **************************************************************************************************************
//**
//** Inclusion des fichiers de déclaration.
//**
//** **************************************************************************************************************
//** **************************************************************************************************************

//** -------------------------------------------------------------------
//** Norme du langage de programmation.
//** -------------------------------------------------------------------
#include <stdio.h>                      //## Entrée/sorties normalisées: printf().
#include <conio.h>                      //## Entrées/sorties directes à la console: getch().
#include <limits.h>                     //## Valeurs limites du compilateur.

#if defined(__SC__)                     //## Si le compilateur est Symantec C++
#include <disp.h>                       //##     Inclure les déclarations pour les routines d'affichage.
#endif                                  //## Fin du si.

//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//**
//** Déclaration des constantes de base.
//**
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//** **************************************************************************************************************
//** **************************************************************************************************************
//**
//** Déclaration des constantes « simples ».
//**
//** **************************************************************************************************************
//** **************************************************************************************************************

#define AUCUNE_ERREUR                 0 //** Code d'erreur: aucune erreur.

#define FIN_CHAINE                    0 //** Délimiteur de fin de chaîne.

#define NB_BITS_ENTIER               16 //** Nombre de bits dans un entier.
#define NB_BITS_CAR            CHAR_BIT //** Nombre de bits dans un caractère.

#ifndef ESC
#define ESC                       0x1B  //** Caractère d'échappement (escape).
#endif

//** **************************************************************************************************************
//** **************************************************************************************************************
//**
//** Messages.
//**
//** **************************************************************************************************************
//** **************************************************************************************************************

#if 0    //## Français.
#define MSG_ECRAN_EFFACE      "Écran effacé!\n"
#define MSG_POSITION_CURSEUR  "Ligne = %3u   Colonne = %3u\n"
#define MSG_PAUSE             "Tapez n'importe quelle touche pour continuer!"
#else    //## Anglais.
#define MSG_ECRAN_EFFACE      "Screen cleared!\n"
#define MSG_POSITION_CURSEUR  "Line = %3u   Colon = %3u\n"
#define MSG_PAUSE             "Hit any key to continue!"
#endif

//** **************************************************************************************************************
//** **************************************************************************************************************
//**
//** Formats d'entrée et sortie (indépendants de la langue)
//**
//** **************************************************************************************************************
//** **************************************************************************************************************

#define FMT                   "%5u %5u %5u %5u  %6i  %14.2f    %3u\n"

//** **************************************************************************************************************
//** **************************************************************************************************************
//**
//** Traiter selon la version de la norme du langage de programmation utilisé.
//**
//** **************************************************************************************************************
//** **************************************************************************************************************

//** ==========================================================================
//** C99: __func__
//** ==========================================================================
#if !defined(__FUNCTION_NAME__) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199409L)
#define __FUNCTION_NAME__    __func__
#endif

//** ==========================================================================
//** C++11: __func__
//** ==========================================================================
#if !defined(__FUNCTION_NAME__) && defined(__cplusplus) && (__cplusplus >= 201103L)
#define __FUNCTION_NAME__    __func__
#endif

//** **************************************************************************************************************
//** **************************************************************************************************************
//**
//** Traiter selon l'environnement de développement utilisé.
//**
//** **************************************************************************************************************
//** **************************************************************************************************************

//** **************************************************************************************************************
//** GNU C/C++
//** @note En C++, __FUNCTION__ et __PRETTY_FUNCTION__ sont des macros déclarées de la même manière que __func__.
//** **************************************************************************************************************
#if !defined(__FUNCTION_NAME__) && defined (__GNUC__)
#if 1   //## Sélection du nom de fonction à  afficher: nom court.
#define __FUNCTION_NAME__     __FUNCTION__
#else   //## Sélection du nom de fonction à  afficher: nom long.
#define __FUNCTION_NAME__     __PRETTY_FUNCTION__,
#endif  //## Sélection du nom de fonction à  afficher: fin.
#endif

//** ==========================================================================
//** MinGW
/*   @note

     Type              Macro (nom)                Description  MinGW32  MinGW-w64 MinGW-w64
                                                                        32 bits   64 bits
     ---------------------------------------------------------------------------------------
     Identification    __MINGW32__ 		          defined      defined 	defined   -
     Version 	       __MINGW32_MAJOR_VERSION    Version      defined  defined   defined
     Version 	       __MINGW32_MINOR_VERSION    Revision     defined  defined   defined
     Identification    __MINGW64__ 		          -            -        defined
     Version 	       __MINGW64_VERSION_MAJOR    Version      -        defined   defined
     Version 	       __MINGW64_VERSION_MINOR    Revision     -        defined   defined

     @note Ces macros sont déclarées seulement si les en-têtes appropriées sont incluses:
           <stdlib.h>, <stdio.h>, <windows.h>, <windef.h> et probablement d'autres.
 */
//** ==========================================================================
#if !defined(__FUNCTION_NAME__) && defined (__MINGW32__)
#define __FUNCTION_NAME__     __FUNCTION__
#endif

#if !defined(__FUNCTION_NAME__) && defined (__MINGW64__)
#define __FUNCTION_NAME__     __FUNCTION__
#endif

//** **************************************************************************************************************
//** Borland C++ / Boland C++ Builder
//** **************************************************************************************************************
//## Si la version C++ est au moins aussi récente que mars 2011 (2011-03)
#if !defined(__FUNCTION_NAME__) && defined(__cplusplus) && (__cplusplus >= 201103L)
#define __FUNCTION_NAME__    __FUNC__
#endif                                  //## Fin du si.


//** **************************************************************************************************************
//** MS Visual Studio 2015/2012
//**
//** Nom [sans décoration] de la fonction
//** MS Visual Studio 2015: __func__
//** MS Visual Studio 2015/2012: __FUNCTION__
//**
//** Nom [avec décoration] de la fonction
//** MS Visual Studio 2015/2012: _FUNCDNAME__
//**
//** Signature du nom de la fonction
//** MS Visual Studio 2015/2012: __FUNCSIG__
//** **************************************************************************************************************

#if !defined(__FUNCTION_NAME__) && defined (__MSC_VER__)
    #ifdef WIN32   //WINDOWS
        #define __FUNCTION_NAME__   __FUNCTION__
    #else          //*NIX
        #define __FUNCTION_NAME__   __func__
    #endif
#endif

//** **************************************************************************************************************
//** Symantec C++
//** **************************************************************************************************************

#if !defined(__FUNCTION_NAME__) && defined (__SC__)
#define __FUNCTION_NAME__     __func__
#endif

//** **************************************************************************************************************
//** ARM Compiler
//**
//** Identification 	__CC_ARM
//** Version 	__ARMCC_VERSION 	VRPBBB 	V = Version
//** R = Revision
//** P = Patch
//** BBB = Build
//** **************************************************************************************************************

#if !defined(__FUNCTION_NAME__) && defined (__CC_ARM)
#define __FUNCTION_NAME__     __func__
#endif

//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//**
//** Déclaration des macro-instructions.
//**
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//** **************************************************************************************************************
//**
//** Déclarations indépendantes du système.
//**
//** **************************************************************************************************************

//** Attendre que l'utilisateur appuie sur une touche du clavier (n'importe laquelle).
#define  PAUSE()                     { printf(MSG_PAUSE);\
                                       if ( getch()==0 ) getch();\
                                       printf("\n"); }
#define  PAUSE_MSG(Msg)              { printf(Msg);\
                                       if ( getch()==0 ) getch();\
                                       printf("\n"); }

//** ===================================================================
//** Déboguer.

#ifdef DEBUG                            //## Commande de débogage (début).
#define FMT_MSG_DEBUG       "*** %s: %s\n"
#define MSG_DEBUT           "Debut"
#define MSG_FIN             "Fin"
#endif                                  //## Commande de débogage (fin).

//** **************************************************************************************************************
//**
//** Traiter les environnements de développement inconnus.
//**
//** **************************************************************************************************************

#if 0                                   //## Ne pas les déclarer: ainsi cela causera un avertissement à la compilation.

                                        //## Si le compilateur n'est pas Symantec C++, Borland C ou Microsoft C
#if !defined(__SC__)  && !defined(__BORLANDC__) && !defined(__MSC__) && !defined(__GENERIC__)
#define  CLEAR_SCREEN()
#define  MOVE_CURSOR(r,c)
#define  ERASE_END_OF_LINE()
#define  HIDE_CURSOR()
#define  SHOW_CURSOR()
#define  DELETE_CURRENT_LINE()
#define  INSERT_LINE()
#define  OPEN_SCREEN()
#define  CLOSE_SCREEN()
#endif                                  //## Fin du si.

#endif                                  //## Fin du si.

//** **************************************************************************************************************
//**
//** Traiter les déclarations génériques.
//**
//** **************************************************************************************************************

#if defined(__GENERIC__)                //## S'il faut utiliser les déclarations génériques

//** Effacer le contenu de l'écran (et positionner le curseur au début de l'écran).
#define  CLEAR_SCREEN()              printf("\x1b[2J");

//** Positionner le curseur à la ligne r et à la colonne c.
#define  MOVE_CURSOR(r,c)            printf("\x1b[%u;%uH",c,r);
#define  ERASE_END_OF_LINE()
#define  HIDE_CURSOR()
#define  SHOW_CURSOR()
#define  DELETE_CURRENT_LINE()
#define  INSERT_LINE()
#define  OPEN_SCREEN()
#define  CLOSE_SCREEN()
#endif                                  //## Fin du si.

//** **************************************************************************************************************
//**
//** Traiter l'environnement de GNU C.
//**
//** Windows: system("cls");
//** Linux:   system("clear");
//** __MINGW32__      MingGW
//** __MINGW64__      MingW-w64
//** **************************************************************************************************************

#if defined(__GNUC__)                   //## S'il s'agit de l'environnement de Borland C

//## Note: ne fonctionne pas => affiche le symbole ankh.
//#define  CLEAR_SCREEN()              { printf ("\f"); }

//## Méthode non sécuritaire: on peut remplacer la commande cls (Windows) ou clear (Linux).
#if defined(__MINGW32__) || defined(__MINGW64__)
#define  CLEAR_SCREEN()              { system("cls"); }
#else
#define  CLEAR_SCREEN()              { system("clear"); }
#endif

#if 0   //## @todo  trouver les équivalence pour ce compilateur (inconnues au moment de la mise à jour de ce fichier).
#define  MOVE_CURSOR(r,c)            gotoxy(c+1, r+1)
#define  ERASE_END_OF_LINE()         clreol()
#define  HIDE_CURSOR()               _setcursortype(_NOCURSOR)
#define  SHOW_CURSOR()               _setcursortype(_NORMALCURSOR)
#define  DELETE_CURRENT_LINE()       delline()
#define  INSERT_LINE()               insline()
#define  OPEN_SCREEN()
#define  CLOSE_SCREEN()
#endif

#endif                                  //## Fin du si.

//** **************************************************************************************************************
//**
//** Traiter l'environnement de Symantec.
//**
//** **************************************************************************************************************

#if defined(__SC__)                     //## S'il s'agit de l'environnement de Symantec C
#define  CLEAR_SCREEN()              { disp_open();\
                                       disp_move(0,0);\
                                       disp_eeop();\
                                       disp_close(); }
#define  MOVE_CURSOR(r,c)            disp_move(r,c);    disp_flush()
#define  ERASE_END_OF_LINE()         disp_eeol();       disp_flush()
#define  HIDE_CURSOR()               disp_hidecursor(); disp_flush()
#define  SHOW_CURSOR()               disp_showcursor(); disp_flush()
#define  DELETE_CURRENT_LINE()
#define  INSERT_LINE()
#define  OPEN_SCREEN()               disp_open()
#define  CLOSE_SCREEN()              disp_close()
#endif                                  //## Fin du si.

//** **************************************************************************************************************
//**
//** Traiter l'environnement de Borland C.
//**
//** Embarcadero:        __FUNC__ ou __FUNCTION__
//** C++ Builder:        __FUNC__
//** Borland C++:        __BORLANDC__
//** C++ Builder 2006:   __CODEGEARC__
//** **************************************************************************************************************

#if defined(__BORLANDC__)               //## S'il s'agit de l'environnement de Borland C
#define  CLEAR_SCREEN()              clrscr()
#define  MOVE_CURSOR(r,c)            gotoxy(c+1, r+1)
#define  ERASE_END_OF_LINE()         clreol()
#define  HIDE_CURSOR()               _setcursortype(_NOCURSOR)
#define  SHOW_CURSOR()               _setcursortype(_NORMALCURSOR)
#define  DELETE_CURRENT_LINE()       delline()
#define  INSERT_LINE()               insline()
#define  OPEN_SCREEN()
#define  CLOSE_SCREEN()
#endif                                  //## Fin du si.

//** **************************************************************************************************************
//**
//** Traiter l'environnement de Microsoft C.
//**
//** **************************************************************************************************************

#if defined(__MSC__)                    //## S'il s'agit de l'environnement de Microsoft C
#define  CLEAR_SCREEN()              _clearscreen(_GCLEARSCREEN)
#define  MOVE_CURSOR(r,c)            _settextposition(r, c)

#if 0   //## @todo  trouver les équivalence pour ce compilateur (inconnues au moment de la mise à jour de ce fichier).
#define  ERASE_END_OF_LINE()
#define  HIDE_CURSOR()
#define  SHOW_CURSOR()
#define  DELETE_CURRENT_LINE()
#define  INSERT_LINE()
#define  OPEN_SCREEN()
#define  CLOSE_SCREEN()
#endif                                  //## Inconnues (fin).

#endif                                  //## Fin du si.

//** **************************************************************************************************************
//**
//** Ajouter les déclarations en français.
//**
//** **************************************************************************************************************

#define  EFFACER_ECRAN()             CLEAR_SCREEN()
#define  DEPLACER_CURSEUR(r,c)       MOVE_CURSOR(r,c)
#define  EFFACER_FIN_LIGNE()         ERASE_END_OF_LINE()
#define  CACHER_CURSEUR()            HIDE_CURSOR()
#define  MONTRER_CURSEUR             SHOW_CURSOR()
#define  SUPPRIMER_LIGNE_COURANTE()  DELETE_CURRENT_LINE()
#define  INSERER_LIGNE()             INSERT_LINE()
#define  OUVRIR_FENETRE()            OPEN_SCREEN()
#define  FERMER_FENETRE()            CLOSE_SCREEN()

#ifdef __cplusplus
}
#endif

//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//**
//** Déclarations par défaut pour  les déclarations inexistantes.
//**
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//** XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#if !defined(_Windows)
#define _Windows "non déclaré"
#endif

#if !defined(__FUNCTION_NAME__)
#define __FUNCTION_NAME__ "indéterminé"
#endif

#endif /* COMPILER_H */
