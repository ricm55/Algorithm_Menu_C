/*!  @file                              Menu.h
     @version                           1.00
     @brief                             This file contain the tests function declaration and the menu

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-10-31
     @author                            Marc-Antoine
     @note                              Add some test function and the menu information

     <hr width="100%" height="5">
 */
//** **************************************************************************

#ifndef MENU_H
#define MENU_H

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct TMenu TMenu;

    //! Contain the elements inside 1 element of the menu
    struct TMenu
    {
        //!Input character to run the program
        char Touche;

        //!Description for the program
        char* Description;

        //!Pointer to the program to execute
        int (* pFct ) ( );

    };

    int Test1 ( );
    int Test2 ( );


#ifdef __cplusplus

#endif

#endif /* MENU_H */
