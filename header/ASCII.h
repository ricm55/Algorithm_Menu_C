/*!  @file                              ascii.h
     @version                           1.00
     @brief                             Déclarations pour la table du code ASCII.

     @internal

     @note                              Sources (références):

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              1989-09-30
     @author                            Denis Lavoie
     @note                              Entrée des déclarations des constantes des numéros de touches («scan code» ou
                                        « extended code ») et des codes ASCII (sous DOS). [terminal.h]
 
     <hr width="100%" height="1">
     @date                              2002-12-04
     @author                            Denis Lavoie
     @note                              Nouveaux noms pour les constantes et rangement dans un fichier à part [ascii.h].
                                        Remplacement du début des commentaires par //.
 
     <hr width="100%" height="5">
 */
//** **************************************************************************

#ifndef ASCII_H                         //## Si la sentinelle n'est pas déclarée
#define ASCII_H                         //## Déclarer la sentinelle.

//** **************************************************************************
//** Déclaration des codes ASCII(sous DOS).
//** **************************************************************************
#ifndef NUL
#define NUL                           0 //** Caractère nul.
#endif

#define DEBUT_EN_TETE                 1 //** Début d'en-tête (Start Of Heading).
#define START_OF_HEADING  DEBUT_EN_TETE
#define SOH               DEBUT_EN_TETE
#define SOURIRE_BLANC     DEBUT_EN_TETE
#define SMILE             DEBUT_EN_TETE

#define DEBUT_DE_TEXTE                2 //** Début du texte (Start of TeXt).
#define START_OF_TEXTE   DEBUT_DE_TEXTE
#define STX              DEBUT_DE_TEXTE
#define SOURIRE_NOIR     DEBUT_DE_TEXTE
#define BLACKSMILE       DEBUT_DE_TEXTE

#define FIN_DE_TEXTE                  3 //** Fin de texte (End of TeXt).
#define END_OF_TEXT        FIN_DE_TEXTE
#define ETX                FIN_DE_TEXTE
#define COEUR              FIN_DE_TEXTE
#define HEART              FIN_DE_TEXTE

#define FIN_DE_TRANSMISSION           4 //** Fin de transmission (End Of Transmission).
#define END_OF_TRANSMISSION FIN_DE_TRANSMISSION 
#define EOT                 FIN_DE_TRANSMISSION
#define CARREAU             FIN_DE_TRANSMISSION
#define DIAMAND             FIN_DE_TRANSMISSION
#define DIAMOND             FIN_DE_TRANSMISSION

#define DEMANDE_DE_RENSEIGNEMENT      5 //** Demande de renseignement (Enquiry).
#define ENQUIRY  DEMANDE_DE_RENSEIGNEMENT 
#define ENQ      DEMANDE_DE_RENSEIGNEMENT
#define TREFLE   DEMANDE_DE_RENSEIGNEMENT

#define ACCUSE_DE_RECEPTION           6 //** Accusé de réception (ACKnowledgement).
#define ACKNOWLEDGEMENT  ACCUSE_DE_RECEPTION 
#define ACK              ACCUSE_DE_RECEPTION
#define PIQUE            ACCUSE_DE_RECEPTION

#define SONNERIE                      7 //** Cloche / sonnerie (BELl)
#define CLOCHE                 SONNERIE
#define BEL                    SONNERIE
#define BEEP                   SONNERIE

#define RECUL                         8 //** Recul (Point blanc au centre d'un carré noir).
#define BACKSPACE                 RECUL
#define BS                        RECUL

#define TABULATION                    9 //** Tabulation [horizontale] (Horizontal Tab).
#define TABULATION_HORIZONTALE TABULATION
#define HORIZONTAL_TAB       TABULATION
#define TAB                  TABULATION
#define HT                   TABULATION

#define LIGNE_SUIVANTE             0x0A //** Ligne suivante (Line Feed).
#define LINE_FEED        LIGNE_SUIVANTE
#define LF               LIGNE_SUIVANTE

#define TABULATION_VERTICALE       0x0B //** Début de l'écran (tabulation verticale).
#define VERTICAL_TAB TABULATION_VERTICALE
#define VT           TABULATION_VERTICALE
#define DEBUT_ECRAN  TABULATION_VERTICALE

#define FEUILLE_SUIVANTE           0x0C //** Feuille suivante (Form Feed).
#define FORM_FEED      FEUILLE_SUIVANTE
#define FF             FEUILLE_SUIVANTE

#define RETOUR_CHARIOT             0x0D //** Retour de chariot (carriage return).
#define CARRIAGE_RETURN  RETOUR_CHARIOT
#define CR               RETOUR_CHARIOT

#define CARACTERE_HORS_CODE        0x0E //** Caractère hors code (Shift-Out).
#define SHIFT_OUT   CARACTERE_HORS_CODE
#define SO          CARACTERE_HORS_CODE
#define NOTE        CARACTERE_HORS_CODE //** Note de musique.

#define CARACTERE_EN_CODE          0x0F //** Caractère en code (Shift-In).
#define SHIFT_IN      CARACTERE_EN_CODE
#define SI            CARACTERE_EN_CODE
#define SOLEIL        CARACTERE_EN_CODE

#define ECHAPPEMENT_TRANSMISSION   0x10 //** Caractère d'échappement de transmission (Data Link Escape).
#define DATA_LINK_ESCAPE  ECHAPPEMENT_TRANSMISSION
#define DLE     ECHAPPEMENT_TRANSMISSION

#define CMD_DISPOSITIF_1           0x11 //** Commande du dispositif 1 (Device Control 1).
#define DEVICE_CONTROL_1  CMD_DISPOSITIF_1

#define CMD_DISPOSITIF_2           0x12 //** Commande du dispositif 2 (Device Control 2).
#define DEVICE_CONTROL_2  CMD_DISPOSITIF_2

#define CMD_DISPOSITIF_3           0x13 //** Commande du dispositif 3 (Device Control 3).
#define DEVICE_CONTROL_3  CMD_DISPOSITIF_3

#define CMD_DISPOSITIF_4           0x14 //** Commande du dispositif 4 (Device Control 4).
#define DEVICE_CONTROL_4  CMD_DISPOSITIF_4

#define ACCUSE_RECEPTION_NEGATIF   0x15 //** Accusé de réception négatif (Negative AcKnowledgement).
#define NEGATIVE_ACKNOWLEDGEMENT  ACCUSE_RECEPTION_NEGATIF
#define NAK                       ACCUSE_RECEPTION_NEGATIF
#define INTCIRC                   ACCUSE_RECEPTION_NEGATIF

#define FIN_BLOC_TRANSMISSION      0x17 //** Fin de bloc de transmission (End of Transmisison Block).
#define END_OF_TRANSMISSION_BLOCK FIN_BLOC_TRANSMISSION
#define ETB                       FIN_BLOC_TRANSMISSION

#define ANNULATION                 0x18 //** Annulation
#define CTRL_X               ANNULATION //** ctrl-x.
#define CANCEL               ANNULATION //** (CANcel).
#define CAN                  ANNULATION
#define FLECHE_HAUT          ANNULATION //** Flèche vers le haut.

#define FIN_DE_SUPPORT             0x19 //** Fin de support (End of Medium).
#define END_OF_MEDIUM    FIN_DE_SUPPORT
#define EM               FIN_DE_SUPPORT
#define FLECHE_BAS       FIN_DE_SUPPORT //** Flèche vers le bas.

#define SUBSTITUT                  0x1A //** Substitut (Substitute).
#define SUBSTITUTE            SUBSTITUT
#define SUB                   SUBSTITUT
#define FLECHE_DROITE         SUBSTITUT //** Flèche vers la droite.

#define ECHAPPEMENT                0x1B //** Echappement (ESCape).
#define ESCAPE              ECHAPPEMENT
#ifndef ESC
#define ESC                 ECHAPPEMENT
#endif
#define FLECHE_GAUCHE       ECHAPPEMENT //** Flèche vers la gauche.

#define SEPARATEUR_DE_FICHIERS     0x1C //** Séparateur de fichiers (File Separator).
#define FILE_SEPARATOR  SEPARATEUR_DE_FICHIERS
#define FS              SEPARATEUR_DE_FICHIERS
#define CURSEUR_DROIT   SEPARATEUR_DE_FICHIERS //** Curseur vers la droite.
#define CURSOR_RIGHT    SEPARATEUR_DE_FICHIERS

#define SEPARATEUR_DE_GROUPES      0x1D //** Séparateur de groupes (Group Separator).
#define GROUP_SEPARATOR  SEPARATEUR_DE_GROUPES
#define GS               SEPARATEUR_DE_GROUPES
#define CURSEUR_GAUCHE   SEPARATEUR_DE_GROUPES //** Curseur vers la gauche.
#define CURSOR_LEFT      SEPARATEUR_DE_GROUPES

#define SEPARATEUR_ENREGISTREMENTS 0x1E //** Séparateur d'enregistrements (Record Separator).
#define RECORD_SEPARATOR SEPARATEUR_ENREGISTREMENTS
#define RS               SEPARATEUR_ENREGISTREMENTS
#define CUSREUR_HAUT     SEPARATEUR_ENREGISTREMENTS //** Curseur vers le haut.
#define CURSOR_UP        SEPARATEUR_ENREGISTREMENTS

#define SEPARATEUR_UNITES          0x1F //** Séparateurs d'unités (Unit Separator).
#define UNIT_SEPARATOR   SEPARATEUR_UNITES
#define US               SEPARATEUR_UNITES
#define CURSEUR_BAS      SEPARATEUR_UNITES //** Curseur vers le bas.
#define CURSOR_DOWN      SEPARATEUR_UNITES

#define ESPACE                      ' ' //** Espace blanc (SPACE).
#define SPACE                    ESPACE

#define SUPPRESSION                0x7F //** Suppression (DELete).
#define DELETE              SUPPRESSION
#define DEL                 SUPPRESSION

#define VIDE                       0xFF //** Vide (BLANK).
#define BLANK                      VIDE

#endif                                  //## Fin du si (sentinelle).
