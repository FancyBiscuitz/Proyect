#include "utils.h"

using namespace std;

std::string itemIdMaker(std::string base, int size)
{
    srand(time(NULL));
    std::string id;
    int sas;
    std::string sup = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < size; i++)
    {
        sas = rand() % (sup.size()-1) + 1;
        id += sup[sas];
    }
    id = base + "-" + id;
    return id;
}

void register_user()
{ 
    std::ofstream regis;
    regis.open("users.csv", ios::app); // Abre el archivo
    std::string names, surnames, username, phonenumber, password;
    int age;
    if(regis.good())
    {
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
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << std::endl;
        std::cout << "Password: ";
        std::cin >> password;
        
        regis << names << "," << surnames << "," << username << "," << age << "," << phonenumber << "," << password << "," << itemIdMaker("usr", 9);
    }
    regis.close();
}

std::string log_in()
{
    std::vector<std::vector<std::string>> credentials;
    std::string pass;
    int i = 3;
    std::string user;
    std::cout << "Username: ";
    std::cin >> user;
    credentials = getData(user, 2, "users.csv", 7);
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

void menuRegisterAndLogin()
{
    int choice;
    cout<<"--------------------------------------------¡Welcome to PepegaCoding Market!----------------------------------------------------\n";
    cout << "Please choose a option!\n[1] Login\n[2] Register\n[3] Exit" << endl;
    cin >> choice;
    switch(choice){
        case 1:
            log_in();
            break;
        case 2:
            register_user();
            break;
        case 3:
            exit(0);
    }
}

std::string getProductId(std::string category)
{
    vector<string> categories {"Abarrotes", "Desayuno", "Lacteos", "Carnes y pollos", "Frutas y verduras", "Pasteles", "Snacks", "Bebidas", "Licores", "Limpieza", "Cuidado personal"};
    vector<string> initials {"001", "002", "003", "004", "005", "006", "007", "008", "009", "010", "011"};
    int z;

    for (int i = 0; i < categories.size(); i++)
    {
        if (categories[i] == category)
        {
            z = i;
            break;
        }
    }
    return itemIdMaker(initials[z], 6);
}

void addProduct()
{
    std::ofstream products;
    products.open("products.csv", ios::app); // Abre el archivo
    std::string category, description, id, definition, brand;
    int price, stock;
    if(products.good())
    {
        products << "\n";
        std::cout << "Category: ";
        std::getline(std::cin, category);
        products << category << ",";
        std::cout << std::endl;

        std::cout << "Description: ";
        std::getline(std::cin, description);
        products << description << ",";
        std::cout << std::endl;

        std::cout << "Definition: ";
        std::getline(std::cin, definition);
        products << definition << ",";
        std::cout << std::endl;

        std::cout << "Price: ";
        std::cin >> price;
        products << price << ",";
        std::cout << std::endl;

        std::cout << "Stock: ";
        std::cin >> stock;
        products << stock << ",";
        std::cout << std::endl;

        std::cout << "Brand: ";
        std::getline(std::cin, brand);
        std::getline(std::cin, brand);
        products << brand << ",";
        std::cout << std::endl;

        products << getProductId(category);
    }
    products.close();
}

std::vector<std::vector<std::string>> getData(std::string support, int parameter, std::string file, int columms)
{
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> credentials;
    std::string usersup;
    int i = 0;
    std::ifstream users;
    users.open(file, ios::in);
    while (users.good())
    {
        if (i == columms-1)
        {
            std::getline(users, usersup, '\n');
            credentials.push_back(usersup);
            if (credentials[parameter] == support)
            {
                res.push_back(credentials);
            }
            credentials = {};
            i = -1;
        }
        else
        {
            std::getline(users, usersup, ',');
            credentials.push_back(usersup);
        }
        i++;
    }
    users.close();
    return res;
}

std::vector<std::vector<std::string>> getData(std::string file, int columms)
{
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> credentials;
    std::string usersup;
    int i = 0;
    std::ifstream users;
    users.open(file, ios::in);
    while (users.good())
    {
        if (i == columms-1)
        {
            std::getline(users, usersup, '\n');
            credentials.push_back(usersup);
            res.push_back(credentials);
            credentials = {};
            i = -1;
        }
        else
        {
            std::getline(users, usersup, ',');
            credentials.push_back(usersup);
        }
        i++;
    }
    users.close();
    return res;
}

bool deleteElementTest(std::string id)
{
    std::vector<std::vector<std::string>> data;
    data = getData("products.csv", 7);
    std::remove("products.csv");
    int sup = 0;

    std::ofstream newfile("products.csv");
    
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][data[i].size()-1] == id)
        {
            std::cout << "yo?";
            continue;
        }
        for (int j = 0; j < data[0].size(); j++)
        {
            if (j == data[0].size()-1)
            {
                newfile << data[i][j] << "\n";
                continue;
            }
            newfile << data[i][j] << ",";
        }
    }
    newfile.close();
}
