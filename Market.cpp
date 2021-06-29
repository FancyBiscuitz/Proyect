#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

#include "user.h"
#include "item.h"
#include "product.h"
#include "utils.h"
#include "admin.h"
#include "client.h"
#include "purchase.h"
#include "bill.h"
#include "system.h"

using namespace std;

int main(void)
{
    System sys;
    Client current_user;
    Admin current_admin;
    std::string mode;
    std::string sup_id;
    std::string option;

    while (true)
    {
        system("CLS");
        sup_id = sys.loginMenu();
        std::vector<std::vector<std::string>> credentials = getData(sup_id, 6, "users.csv", 7);
        
        if (getInitials(sup_id, 3) == "usr")
        {
            current_user = Client(credentials);
            current_user.loadShopCart();
            mode = "client";
        }
        else
        {
            current_admin = Admin(credentials);
            mode = "admin";
        }
        while (true)
        {
            system("CLS");
            option = sys.mainMenu(mode);
            if (option == "logout")
            {
                if (mode == "client")
                {
                    current_user.saveShopCart();
                }
                break;
                current_user.~Client();
                current_admin.~Admin();
            }
            option = sys.processMainMenuOption(mode ,option);
            switch(std::stoi(option))
            {
            case 1:
                {
                    std::string choice;
                    do
                    {
                        sys.browseProducts();
                        std::cout << std::endl << "[1]Keep browsing  [2]Return" << std::endl;
                        std::cout << ">> ";
                        std::cin >> choice;
                        choice = checkValidOption(choice, 2, "2");
                    } while (choice == "1");
                    break;
                }
            case 2:
                current_user.addProductsToShoppingCart();   
                break;
            case 3:
                current_user.viewShoppingCartProducts();
                std::cout << std::endl;
                system("PAUSE");
                break;
            case 4:
                sys.buyProductsInCart(current_user);
                current_user.emptyShoppingCart();
                std::cout << std::endl;
                system("PAUSE");
                break;
            case 5:
                current_user.viewShoppingCartProducts();
                std::cout << std::endl;
                current_user.deleteProducsFromShoppingCart();
                break;
            case 6:
                current_admin.addProducts();
                break;
            case 7:
                {
                    std::string id;
                    bool check;
                    showData(getData("products.csv", 8), "products");
                    std::cout << std::endl << "Insert the id of the product to be deleted" << std::endl;
                    std::cout << ">> ";
                    std::cin >> id;
                    check = current_admin.deleteProducts(id);
                    if (!check)
                    {
                        std::cout << "Id not found" << std::endl;
                    }
                    system("PAUSE");
                }
                break;
            case 8:
                {
                    std::string id;
                    float nvalue;
                    showData(getData("products.csv", 8), "products");
                    std::cout << std::endl << "Insert the id of the product of which you want to chage the price" << std::endl;
                    std::cout << ">> ";
                    std::cin >> id;
                    std::cout << std::endl << "New price: ";
                    std::cin >> nvalue;
                    current_admin.changePrice(id, nvalue);
                    system("PAUSE");
                    break;
                }
            case 9:
                {
                    std::string id;
                    int nstock;
                    showData(getData("products.csv", 8), "products");
                    std::cout << std::endl << "Insert the id of the product of which you want to chage the stock" << std::endl;
                    std::cout << ">> ";
                    std::cin >> id;
                    std::cout << std::endl << "New stock: ";
                    std::cin >> nstock;
                    current_admin.changeStock(id,nstock);
                    system("PAUSE");
                    break;
                }
            case 10:
                {
                    std::string id;
                    int ndiscount;
                    showData(getData("products.csv", 8), "products");
                    std::cout << std::endl << "Insert the id of the product of which you want to chage the discount" << std::endl;
                    std::cout << ">> ";
                    std::cin >> id;
                    std::cout << std::endl << "New discount: ";
                    std::cin >> ndiscount;
                    current_admin.changeDiscount(id, ndiscount);
                    system("PAUSE");
                    break;
                }
            case 11:
                showData(getData("users.csv", 7), "users");
                std::cout << endl;
                system("CLS");
                current_admin.viewPurchases();
                std::cout << std::endl;
                system("PAUSE");
            }                                
        }
    }
}
