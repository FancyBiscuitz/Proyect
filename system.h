#ifndef SYSTEM_H
#define SYSTEM_H

#include <fstream>
#include <Windows.h>
#include <iostream>
#include "utils.h"
#include "client.h"
#include "bill.h"
#include "purchase.h"

class System
{
    public:

    void register_user();
    std::string log_in();
    void printMenu(std::string mode);
    std::string loginMenu();
    std::string mainMenu(std::string mode);
    std::string processMainMenuOption(std::string mode, std::string option);
    void browseProducts();
    bool buyProductsInCart(Client &cliente);
};

#endif