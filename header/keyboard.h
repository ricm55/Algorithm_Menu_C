/*!  @file                              clavier.h
     @version                           1.00
     @brief                             Déclarations pour le clavier.

     @internal

     @note                              Sources (références):
                                        1) IBM PC, Appendix G-6
                                        2) IBM PC BIOS, p.2-14 Keyboard Encoding
                                        3) Feuille d'origine inconnue
                                        4) Programming/Utilities, PC Magazine, 1987-05-26, p.352
 
     @note      Alt + Ctrl + Del        Provoque la réinitilisation du système («reboot») {gestion interne par le clavier}.

                Ctrl + Break            Provoque une interruption 1Ah.

                Ctrl + NumLock          Provoque la mise en boucle de la routine d'interruption du clavier,
                                        attendant pour n'importe quelle touche sauf la touche NumLock.

                Shift + PrintScreen     Provoque une interruption invoquant la routine d'impression du contenu de l'écran.
                (touche 55)

     @note                              Masques des combinaisons des touches spéciales
                                        ---------+-----+-----+-----+-----+-----------
                                        Valeur du  Alt   Ctrl Left  Right Note
                                        masque                Shift Shift
                                        ---------+-----+-----+-----+-----+-----------
                                         0   0      0     0     0     0   aucun
                                         1   1      0     0     0     1
                                         2   2      0     0     1     0
                                         3   3      0     0     1     1
                                         4   4      0     1     0     0
                                         5   5      0     1     0     1
                                         6   6      0     1     1     0
                                         7   7      0     1     1     1
                                         8   8      1     0     0     0
                                         9   9      1     0     0     1
                                        10   A      1     0     1     0
                                        11   B      1     0     1     1
                                        12   C      1     1     0     0
                                        13   D      1     1     0     1
                                        14   E      1     1     1     0
                                        15   F      1     1     1     1
                                        ---------+-----+-----+-----+-----+-----------
 
     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              1989-09-30
     @author                            Denis Lavoie
     @note                              Entrée des déclaration des constantes des numéros de touches 
                                        («scan code» ou « extended code »). [terminal.h]

     <hr width="100%" height="1">
     @date                              2002-12-04
     @author                            Denis Lavoie
     @note                              Nouveaux noms pour les numéros de touches: début avec « K_ ».
                                        Remplacement des commentaires par //.
                                        Déplacement des déclarations des numéros de touche dans un fichier spécifique [clavier.h].

     <hr width="100%" height="5">
 */
//** **************************************************************************

#ifndef CLAVIER_H                       //## Si la sentinelle n'est pas déclarée
#define CLAVIER_H                       //## Déclarer la sentinelle.

                                        //** ***********************************
                                        //** Déclaration des numéros de touches.
                                        //** ***********************************
#define K_ESC                         1 //** Échappement (Escape).
                                        //** -----------------------------------
                                        //** Touche numérique de la partie
                                        //** centrale (principale) du clavier.
                                        //** -----------------------------------
#define K_1                           2 //** Touche 1 et !.
#define K_2                           3 //** Note: « Nul Character » selon les
                                        //** sources 1 et 2.
#define K_3                           4 //** Touche 3 et #.
#define K_4                           5 //** Touche 4 et $.
#define K_5                           6 //** Touche 5 et %.
#define K_6                           7 //** Touche 6 et ^.
#define K_7                           8 //** Touche 7 et &.
#define K_8                           9 //** Touche 8 et *.
#define K_9                          10 //** Touche 9 et (.
#define K_0                          11 //** Touche 0 et ).
#define K_DASH                       12 //** Tiret / souligné.
#define K_EQUAL                      13 //** Égalité / plus.
#define K_BS                         14 //** Recul (Back Space).
#define K_TAB                        15 //** Tabulation / Majuscule+Tabulation (Shift+Tab).
#define K_MAJ_TAB                 K_TAB
#define K_SHIFT_TAB               K_TAB
#define K_ALT_Q                      16
#define K_ALT_W                      17
#define K_ALT_E                      18
#define K_ALT_R                      19
#define K_ALT_T                      20
#define K_ALT_Y                      21
#define K_ALT_U                      22
#define K_ALT_I                      23
#define K_ALT_O                      24
#define K_ALT_P                      25
#define K_ALT_CROCHETG               26
#define K_ALT_CROCHETD               27
#define K_ALT_CR                     28 //** Retour de chariot (Carriage Return).
#define K_CTRL                       29 //** Contr“le (Control).
#define K_ALT_A                      30
#define K_ALT_S                      31
#define K_ALT_D                      32
#define K_ALT_F                      33
#define K_ALT_G                      34
#define K_ALT_H                      35
#define K_ALT_J                      36
#define K_ALT_K                      37
#define K_ALT_L                      38
#define K_ALT_POINT_VIRGULE          39 //** Touche ; et :.
#define K_ALT_APOS                   40 //** Touche ' et ".
#define K_ALT_TILDA                  41 //** Touche ~ et `.
#define K_LSHIFT                     42 //** Majuscule gauche (Left Shift).
#define K_ALT_OBLIQUEG               43 //** Oblique gauche (\) et barre verticlae (|).
#define K_ALT_Z                      44
#define K_ALT_X                      45
#define K_ALT_C                      46
#define K_ALT_V                      47
#define K_ALT_B                      48
#define K_ALT_N                      49
#define K_ALT_M                      50
#define K_ALT_VIRGULE                51 //** Virgule (… la gauche du M) et <.
#define K_ALT_POINT                  52 //** Point (… la gauche de la virgule) et >.
#define K_ALT_OBLIQUED               53 //** Oblique droite (/) et point d'interrogation (?).
#define K_RSHIFT                     54 //** Majuscule droite (Right Shift).
#define K_PRTSC                      55 //** Imprimer écran (Print Screen).
#define K_ALT                        56 //** Alt gauche (Left Alt).
#define K_SPACE                      57 //** Barre d'espacement (Space bar).
#define K_CAPSLOCK                   58 //** Fixe majuscule (Caps Lock).
#define K_F1                         59 //** F1.
#define K_F2                         60 //** F2.
#define K_F3                         61 //** F3.
#define K_F4                         62 //** F4.
#define K_F5                         63 //** F5.
#define K_F6                         64 //** F6.
#define K_F7                         65 //** F7.
#define K_F8                         66 //** F8.
#define K_F9                         67 //** F9.
#define K_F10                        68 //** F10.
#define K_NUMLOCK                    69 //** Fixe numérique (Num Lock).
#define K_SCROLL                     70 //** Fixe défilement (Scroll Lock).
#define K_HOME                       71 //** Origine (Home).
#define K_FLECHE_HAUT                72 //** Flèche vers le haut.
#define K_UP              K_FLECHE_HAUT //** Up.
#define K_PGUP                       73 //** Page Up.
#define K_LESS                       74 //** «-» du tampon numérique déporté.
#define K_FLECHE_GAUCHE              75 //** Flèche vers la gauche.
#define K_LEFT          K_FLECHE_GAUCHE //** Left (<-).
#define K_VIDE                       76 //** vide (5) du tampon numérique déporté.
#define K_FLECHE_DROITE              77 //** Flèche vers la droite.
#define K_RIGHT                      77 //** Right (->).
#define K_MORE                       78 //** Plus «+» (More).
#define K_END                        79 //** Fin (End).
#define K_FLECHE_BAS                 80 //** Flèche vers le bas.
#define K_DOWN             K_FLECHE_BAS //** Down.
#define K_PGDN                       81 //** Page Down.
#define K_INS                        82 //** Insérer (Insert).
#define K_DEL                        83 //** Supprimer (Delete).
#define K_SF1                        84 //** Shift F1.
#define K_SF2                        85 //** Shift F2.
#define K_SF3                        86 //** Shift F3.
#define K_SF4                        87 //** Shift F4.
#define K_SF5                        88 //** Shift F5.
#define K_SF6                        89 //** Shift F6.
#define K_SF7                        90 //** Shift F7.
#define K_SF8                        91 //** Shift F8.
#define K_SF9                        92 //** Shift F9.
#define K_SF10                       93 //** Shift F10.
#define K_CF1                        94 //** Control F1.
#define K_CF2                        95 //** Control F2.
#define K_CF3                        96 //** Control F3.
#define K_CF4                        97 //** Control F4.
#define K_CF5                        98 //** Control F5.
#define K_CF6                        99 //** Control F6.
#define K_CF7                       100 //** Control F7.
#define K_CF8                       101 //** Control F8.
#define K_CF9                       102 //** Control F9.
#define K_CF10                      103 //** Control F10.
#define K_AF1                       104 //** Alt F1.
#define K_AF2                       105 //** Alt F2.
#define K_AF3                       106 //** Alt F3.
#define K_AF4                       107 //** Alt F4.
#define K_AF5                       108 //** Alt F5.
#define K_AF6                       109 //** Alt F6.
#define K_AF7                       110 //** Alt F7.
#define K_AF8                       111 //** Alt F8.
#define K_AF9                       112 //** Alt F9.
#define K_AF10                      113 //** Alt F10.
#define K_CTRL_PRINT_SCREEN         114 //** Control Print Screen.
#define K_CTRL_LEFT                 115 //** Control Left (<-).
#define K_CTRL_RIGHT                116 //** Control Right (->).
#define K_CTRL_END                  117 //** Control End.
#define K_CTRL_PGDN                 118 //** Control Page Down.
#define K_CTRL_HOME                 119 //** Control Home.
#define K_ALT_1                     120 //** Alt 1.
#define K_ALT_2                     121 //** Alt 2.
#define K_ALT_3                     122 //** Alt 3.
#define K_ALT_4                     123 //** Alt 4.
#define K_ALT_5                     124 //** Alt 5.
#define K_ALT_6                     125 //** Alt 6.
#define K_ALT_7                     126 //** Alt 7.
#define K_ALT_8                     127 //** Alt 8.
#define K_ALT_9                     128 //** Alt 9.
#define K_ALT_0                     129 //** Alt 0.
#define K_ALT_DASH                  130 //** Alt -.
#define K_ALT_EQUAL                 131 //** Alt =.
#define K_CTRL_PGUP                 132 //** Control Page Up.
#endif                                  //## Fin du si (sentinelle).