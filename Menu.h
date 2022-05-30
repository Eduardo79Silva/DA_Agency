//
// Created by zediogo96 on 30/05/22.
//

#ifndef DA_TRAVEL_MENU_H
#define DA_TRAVEL_MENU_H

#include "Application.h"

/**
 * @brief Virtual Class to be used to create all the other menus
 *
 */
class Menu {

protected:

    /**
     * @brief Singleton for acess to application functionalities
     */
    Application * application = Application::getInstance();
    Menu * next_menu = nullptr;

public:

    /**
     * @brief Constructs a new Menu object
     */
    explicit Menu();

    /**
     * @brief Destroy the Menu object, clearing it from memory
     *
     */
    virtual ~Menu();

    /**
     * @brief Virtual function for display the contents of the menu in the terminal
     *        This function also declared Menu() as a virtual base Class.
     *
     */
    virtual void display() = 0;

    /**
     * @brief Returns a pointer to the next menu it has assigned
     *
     * @return Menu *
     */
    virtual Menu* getNextMenu();

    /**
     * @brief Sets the field next_menu tom the pointer passed as parameter, used for menu navigation
     *
     * @param new_menu * pointer
     */
    virtual void setNextMenu(Menu* new_menu);
};

/**
 * @brief Main menu of the application
 */
class MainMenu: public Menu {
public:
    explicit MainMenu();
    void display() override;
};

/**
 * @brief Menu to support Scenery 1 demonstration
 */
class Scenery1_Menu: public Menu {
public:

    explicit Scenery1_Menu();
    void display() override;
};

/**
 * @brief Menu to support Scenery 2 demonstration
 */
class Scenery2_Menu: public Menu {
public:

    explicit Scenery2_Menu();
    void display() override;

};

/**
 * @brief Menu to support Scenery 3 demonstration
 */
class Scenery3_Menu: public Menu {
public:

    explicit Scenery3_Menu();
    void display() override;
};


#endif //DA_TRAVEL_MENU_H
