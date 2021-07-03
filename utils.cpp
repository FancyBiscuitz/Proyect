#include "utils.h"
#include <stdio.h>
#include <Windows.h>

using namespace std;

//funcion para obtener informacion de archivos csv y sus distintas versiones
std::vector<std::vector<std::string>> getData(std::string support, int index, std::string file, int columms)
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
            if (credentials[index] == support)
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

std::vector<std::string> getDataCol(std::string file, int columm, int columms)
{
    std::vector<std::string> res;
    std::string usersup;
    int i = 0;
    std::ifstream users;
    users.open(file, ios::in);
    while (users.good())
    {
        if (i == columms-1)
        {
            std::getline(users, usersup, '\n');
            if (i == columm)
            {
                res.push_back(usersup);
            }
            i = -1;
        }
        else
        {
            std::getline(users, usersup, ',');
            if (i == columm)
            {
                res.push_back(usersup);
            }
        }
        i++;
    }
    users.close();
    return res;
}

//generador de ids randomizadas
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

//funcion para resolver algunos problemas con el std::cin
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

//funcion para determinar que tipo de usuario se va a registrar
std::string getRole()
{
    int attempts =  3;
    std::string m;
    std::cout << "Who is registering?" << std::endl << "[1] Admin | [2] Client" << std::endl;
    std::cin >> m;
    if (m == "1")
    {
        while (attempts > 0)
        {
            if (attempts < 3) {std::cout << "You have " << attempts << "attempts left." << std::endl;}
            std::cout << "Password to add new admin: " << std::endl << ">";
            std::cin >> m;
            if (m == "ultrasecretpassword")
            {
                return "adm";
            }
            attempts--;
        }
        return "nan";
    }
    return "usr";
}

//funcion para registrar un nuevo usuario
void register_user()
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
        
        system("Color 01");
        cout << "\t\tRegistered Successfully..."<< endl;
        Sleep(2000);
        regis << names << "," << surnames << "," << age << "," << phonenumber << "," << username << "," << password << "," << itemIdMaker(role, 9);
    }
    regis.close();
}

//funcion de inicio de sesion
std::string log_in()
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
        system("Color 02");
        std::cout << "User not found." << std::endl;
        Sleep ( 2000 );
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
                system("Color 03");
                std::cout << "Successfully logged in! " << std::endl;
                Sleep ( 2000 );
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

//generador aleatorio de ids para productos
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

//funcion para imprimir adecuadamente el espacion entre cada campo de la tabla en la terminal
void outSpaced(std::string word, int spacing)
{
    int left = spacing/2;
    int right = spacing - left;
    std::string lefts;
    std::string rights;
    for (int i = 0; i < left; i++)
    {
        lefts += " ";
    }
    for (int j = 0; j < right; j++)
    {
        rights += " ";
    }
    std::cout << lefts << word << rights;
}

//fucnion para mostrar informacion en un formato similar a una tabla
void showData(std::vector<std::vector<std::string>> data, std::string mode)
{
    if (data.size() == 0)
    {
        return;
    }
    std::vector<std::string> first;
    int squares;
    int biggest;
    std::string ceilfloor;
    bool us = false;

    if (mode == "users")
    {
        first = {"Names","Surnames","Age","Phone","Username", "id"};
        biggest = 8;
        us = true;
        squares = data[0].size() - 1;
    }
    else if (mode == "products")
    {
        first = {"Category", "Description", "Definition", "Price", "Stock", "Brand", "Discount", "Id"};
        biggest = 11;
        squares = data[0].size();
    }
    else if (mode == "purchases")
    {
        first = {"Item id", "Brand", "Item", "Item price", "Amount", "Discount", "Total", "Buyer"};
        biggest = 10;
        squares = data[0].size();
    }
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[0].size(); j++)
        {
            if (data[i][j].size() > biggest)
            {
                biggest = data[i][j].size();
            }
        }
    }
    biggest += 2;
    for (int i = 0; i < biggest*squares + data[0].size() + 1; i++)
    {
        ceilfloor += "-";
    }
    std::cout << ceilfloor << std::endl << "|";;
    for (int s = 0; s < first.size(); s++)
    {
        outSpaced(first[s], biggest - first[s].size());
        std::cout << "|";
    }
    std::cout << std::endl;
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << ceilfloor << std::endl << "|";;
        for (int j = 0; j < data[0].size(); j++)
        {
            if (j == 5 && us)
            {
                continue;
            }
            outSpaced(data[i][j], biggest - data[i][j].size());
            std::cout << "|";
        }
        std::cout << std::endl;
    }
    std::cout << ceilfloor;
}

//checkead si una id es valida
bool validateId(std::string id, std::string file, int coluums)
{
    std::vector<std::string> ids = getDataCol(file, coluums-1, coluums);
    for (int i = 0; i < ids.size(); i++)
    {
        if (ids[i] == id)
        {
            return true;
        }
    }
    return false;
}

//funcion para obterner la fecha y hora actual
std::string getTimeDate()
{
    time_t now = time(0);
   // convert now to string form
   char* dt = ctime(&now);
   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   return dt;
}

//funcion de apoyo para saber que tipo de usuario inicia sesion
std::string getInitials(std::string word, int limit)
{
    std::string res;
    for (int i = 0; i < limit; i++)
    {
        res += word[i];
    }
    return res;
}

//funcion de apoyo para confirmar la validez de una opcion dada por el usuario
std::string checkValidOption(std::string option, int limit, std::string defaul)
{
    int sup = std::stoi(option);
    if (sup > limit || sup < 1)
    {
        return defaul;
    }
    return option;
}   
