#include "system.h"

using namespace std;

void System::register_user()
{
    std::ofstream regis;
    regis.open("users.csv", ios::app); // Abre el archivo
    std::string names, surnames, username, phonenumber, password;
    int age;
    int i = 0;
    std::string role = getRole();
    std::vector<std::string> list = getDataCol("users.csv", 4, 7);
    if(regis.good())
    {
        fflush(stdin);
        //clean_stdin();
        regis << "\n";
        std::cout << "Names: ";
        std::getline(std::cin, names);
        std::cout << std::endl;
        std::cout << "Surnames: ";
        std::getline(std::cin, surnames);
        std::cout << std::endl;
        std::cout << "Age: ";
        std::cin >> age;
        std::cout << std::endl;
        std::cout << "Phone number: ";
        std::cin >> phonenumber;
        std::cout << std::endl;
        do
        {
            if (i > 0) {std::cout << "Username already taken." << std::endl;}
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << std::endl;
            i++;
        } while (std::find(list.begin(), list.end(), username) != list.end());
        std::cout << "Password: ";
        std::cin >> password;
        
        cout << "\t\tRegistrado Correctamente..."<< endl;
        Sleep(2000);
        regis << names << "," << surnames << "," << age << "," << phonenumber << "," << username << "," << password << "," << itemIdMaker(role, 9);
    }
    regis.close();
}

std::string System::log_in()
{
    std::vector<std::vector<std::string>> credentials;
    std::string pass;
    int i = 3;
    std::string user;
    std::cout << "Username: ";
    std::cin >> user;
    credentials = getData(user, 4, "users.csv", 7);
    if (credentials.size() == 0)
    {
        std::cout << "User not found." << std::endl;
        return "0";
    }
    else
    {
        while (i > 0)
        {
            std::cout << "Password: ";
            std::cin >> pass;
            if (pass == credentials[0][5])
            {
                std::cout << "Successfully logged in! " << std::endl;
                return credentials[0][6];
            }
            else
            {
                cout << "You have " << i-1 << " attempts left." << std::endl;
            }
            i--;
        }
        std::cout << "Try again later." << std::endl;
        return "0";
    }
}

void System::printMenu(std::string mode)
{
    if (mode == "logo")
    {
        std::cout <<    "⠁⠁⠁⠁⠁⠁⠐⢶⣶⣶⣶⣤⣤⡀⠁⠁⣠⣀⣀⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁"<< "\n";
        std::cout <<    "⠁⠁⠁⠁⠁⠁⠁⠁⠙⢿⣯⣠⣶⣦⣤⣤⣌⣛⠻⢇⣠⣤⣤⠁⠁⠁⠁⠁⠁⠁"<< "\n";
        std::cout <<    "⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁⠻⣿⣿⣿⡟⢉⡤⢤⣤⣤⡍⠛⢡⢖⣥⣶⣦⣀⠁⠁"<< "\n";
        std::cout <<   " ⠁⠁⠁⠁⠁⠁⠁⠁⠁⠁⣠⣿⣿⣿⡏⣭⣶⣿⣿⠟⢿⣦⡡⣿⣿⡇⠁⡙⣷⡀"<< "\n";
        std::cout <<    "⠁⠁⠁⠁⠁⠁⠁⣀⣴⣿⣿⣿⣿⣿⣿⡞⣿⣿⡟⢀⡀⣿⣿⢻⣿⣿⣀⣁⣿⠏"<< "\n";
        std::cout <<    "⠁⠁⠁⢀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣟⢰⢻⣿⣇⣈⣴⣿⠟⢨⣛⠛⠛⠉⠁⠁"<< "\n";
        std::cout <<    "⠁⣠⣶⣿⣿⡟⢋⠤⣤⠘⢿⣿⣧⡙⠻⠌⠒⠙⠛⢛⣫⣥⣿⣦⡈⠉⣡⣴⣾⠇"<< "\n";
        std::cout <<    "⢰⣿⣿⣿⣿⠁⡇⠁⠙⠷⣤⡙⠻⢿⣿⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⠿⠟⠋⠁⠁"<< "\n";
        std::cout <<    "⠘⣿⣿⣿⣿⣆⠻⣄⠁⣀⡀⠉⠙⠒⠂⠉⠍⠉⠉⠉⠉⣩⣍⣁⣂⡈⠠⠂⠁⠁"<< "\n";
        std::cout <<    "⠁⠘⢿⣿⣿⣿⣦⡉⠳⢬⣛⠷⢦⡄⠁⠁⠁⠁⠁⣀⣼⣿⣿⠿⠛⠋⠁⠁⠁⠁"<< "\n";
        std::cout <<    "⠁⠁⠁⠉⠻⢿⣿⣿⣷⣦⣬⣍⣓⡒⠒⣒⣂⣠⡬⠽⠓⠂⠁⠁⠁⠁⠁⠁" << "\n";
    }
    if (mode == "client")
    {
        std::cout << " ---------------------------------------------------------------------" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                     WELCOME TO PEPEGACODING MARKET                  |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                        Please select an option.                     |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|   [1]Browse products    [2]Add products to cart    [3]Show cart     |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|   [4]Buy products in cart     [5]Delete products from cart          |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|   [6]Add funds           [7]Log out            [8]Close             |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout << " ---------------------------------------------------------------------" << "\n";
    }
    if (mode == "admin")
    {
        std::cout << " ---------------------------------------------------------------------" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                             ADMIN MENU                              |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                       Please select an option.                      |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|   [1]Browse products     [2]Add products        [3]Delete products  |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|   [4]Change price        [5]Change stock        [6]Change discount  |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|   [7]View purchases      [8]Log out             [9]Close            |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout << " ---------------------------------------------------------------------" << "\n";
    }
    if (mode == "browse")
    {
        std::cout << " ---------------------------------------------------------------------" << "\n";
        std::cout <<"|                                                                      |" << "\n";
        std::cout <<"|                             Browse by:                               |" << "\n";
        std::cout <<"|                                                                      |" << "\n";
        std::cout <<"|       [1]Category          [2]Definition          [3]Brand           |" << "\n";
        std::cout <<"|                                                                      |" << "\n";
        std::cout <<"|                                                                      |" << "\n";
        std::cout <<"|                    [4]Id                  [5]All                     |" << "\n";
        std::cout <<"|                                                                      |" << "\n";
        std::cout << " ---------------------------------------------------------------------" << "\n";
    }
    if (mode == "login")
    {
        std::cout << " ---------------------------------------------------------------------" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                          First time here?                           |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                             [1]Register                             |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                      Already have an account?                       |" << "\n";
        std::cout <<"|                                                                     |" << "\n";
        std::cout <<"|                              [2]Log in                              |" << "\n";
        std::cout <<"|                                                        [3]Close     |" << "\n";
        std::cout << " ---------------------------------------------------------------------" << "\n";
    }
}

std::string System::loginMenu()
{
    int option;
    std::string sup_id = "1";
    while (sup_id.size() == 1)
    {
       printMenu("login");
       std::cout << "\n" << ">> ";
       std::cin >> option;
       system("CLS");
       switch (option)
       {
            case 1:
                register_user();
                system("PAUSE");
                system("CLS");
                break;

            case 2:
                do
                {
                    sup_id = log_in();
                    if (sup_id == "0")
                    {
                        std::cout << "couldnt log in." << std::endl;
                        std::cout << "[1]Try again       [2]Return" << std::endl << ">> ";
                        std::cin >> sup_id;
                        sup_id = checkValidOption(sup_id, 2, "2");
                    }
                } while (sup_id == "1");
                system("PAUSE");
                system("CLS");
                break;

            case 3:
                std::cout << "Program closed";
                exit(1);
                break;
            
            default:
                break;
       }
    }
    return sup_id;
}

std::string System::mainMenu(std::string mode)
{
    std::string option;
    printMenu(mode);
    std::cout << ">> ";
    std::cin >> option;
    option = checkValidOption(option, 9, "0");
    if (mode == "client")
    {
        switch (std::stoi(option))
        {

        case 7:
            return "logout";
            break;
        case 8:
            exit(1);
            break;
        
        default:
            return option;
            break;
        }
    }
    if (mode == "admin")
    {
        switch (std::stoi(option))
        {

        case 8:
            return "logout";
            break;
        case 9:
            exit(1);
            break;
        
        default:
            return option;
            break;
        }
    }
    return option;
}

std::string System::processMainMenuOption(std::string mode, std::string option)
{
    if (option == "1")
    {
        return option;
    }
    if (mode == "client")
    {
        switch (std::stoi(option))
        {
        case 2:
            return option;
            break;
        case 3:
            return option;
            break;
        case 4:
            return option;
            break;
        case 5:
            return option;
            break;
        case 6:
            return option;
            break;
        default:
            break;
        }
    }
    if (mode == "admin")
    {
        switch (std::stoi(option))
        {
        case 2:
            return "7";
            break;
        case 3:
            return "8";
            break;
        case 4:
            return "9";
            break;
        case 5:
            return "10";
            break;
        case 6:
            return "11";
            break;
        case 7:
            return "12";
            break;
        default:
            break;
        }
    }
    return "nan";
}

void System::browseProducts()
{
    system("CLS");
    int option;
    std::string choice;
    printMenu("browse");
    std::cout << ">> ";
    std::cin >> option;
    option = std::stoi(checkValidOption(std::to_string(option), 5, "5"));
    switch(option)
    {
        case 1:
            fflush(stdin);
            std::cout << "Category: ";
            std::getline(std::cin, choice);
            showData(getData(choice, 0, "products.csv", 8), "products");
            break;
        case 2:
            fflush(stdin);
            std::cout << "Definition: ";
            std::getline(std::cin, choice);
            showData(getData(choice, 2, "products.csv", 8), "products");
            break;            
        case 3:
            fflush(stdin);
            std::cout << "Brand: ";
            std::getline(std::cin, choice);
            showData(getData(choice,5,"products.csv",8), "products");
            break;
        case 4:
            fflush(stdin);
            std::cout << "Id: ";
            std::getline(std::cin, choice);
            showData(getData(choice,7,"products.csv",8), "products");
            break;
        case 5:
            showData(getData("products.csv",8), "products");
            break;
    }
}

bool System::buyProductsInCart(Client &cliente)
{
    std::vector<Purchase> content;
    for (int i = 0; i < cliente.getShoppingCart().size(); i++)
    {
        Purchase compra(cliente.getShoppingCart()[i], cliente.getQuantity()[i], cliente.getId());
        content.push_back(compra);
    }
    if (content.size() == 0)
    {
        std::cout << "No items in shopping cart." << std::endl;
        return false;
    }
    Bill check(content);
    if (!check.validateBill(cliente))
    {
        std::cout << "Not enough funds to purchase the desired products." << std::endl;
        return false;
    }
    check.processBill(cliente);
    cliente.setCredit(cliente.getCredit() - check.getTotal());
    return true;
}
