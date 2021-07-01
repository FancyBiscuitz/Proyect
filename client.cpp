#include "client.h"

using namespace std;

Client::Client(std::vector<std::vector<std::string>> data)
{
    setNames(data[0][0]);
    setSurnames(data[0][1]);
    setAge(std::stoi(data[0][2]));
    setPhoneNumber(data[0][3]);
    setUsername(data[0][4]);
    setPassword(data[0][5]);
    setId(data[0][6]);
    credit = 1000.0;
}

Client::Client()
{
    
}

void Client::addProductsToShoppingCart()
{
    string id;
    string check;
    int amount;
    bool notDone = true;
    bool check2 = false;
    showData(getData("products.csv", 8), "products");
    while (notDone)
    {
        cout << endl << "Insert product ID to add the product: " << endl << ">";
        cin >> id;
        while (!validateId(id, "products.csv", 8))
        {
            std::cout << "ID not found." << std::endl;
            cout << "Insert product ID to add the product: " << endl << ">";
            cin >> id;
        }
        Item pdt = Item(id);
        for (int i = 0; i < shoppingCart.size(); i++)
        {
            if (shoppingCart[i].getId() == pdt.getId())
            {
                check2 = true;
                break;
            }
            check2 = false;
        }
        if (check2)
        {
            std::cout << "Already in shopping cart." << std::endl;
        }
        else
        {
            std::cout << "Amount: ";
            std::cin >> amount;
            quantity.push_back(amount);
            std::cout << std::endl;
            shoppingCart.push_back(pdt);
            cout << "Product added." << endl;
        }
        cout << "[1] Add more products | [2] Finish" << endl << ">";
        cin >> check;
        if (check == "2")
        {
            notDone = false;
        }
    }
}

void Client::viewShoppingCartProducts()
{
    std::vector<std::vector<std::string>> shopcart;
    std::vector<std::string> sup;
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        sup.push_back(shoppingCart[i].getCategory());
        sup.push_back(shoppingCart[i].getDescription());
        sup.push_back(shoppingCart[i].getDefinition());
        sup.push_back(std::to_string(shoppingCart[i].getPrice()));
        sup.push_back(std::to_string(shoppingCart[i].getStock()));
        sup.push_back(shoppingCart[i].getBrand());
        sup.push_back(std::to_string(shoppingCart[i].getDiscount()));
        sup.push_back(shoppingCart[i].getId());
        shopcart.push_back(sup);
        sup = {};
    }
    showData(shopcart, "products");
}

void Client::deleteProducsFromShoppingCart()
{
    std::string _id;
    std::cout << "Insert id of the product you want to remove: ";
    std::cin >> _id;
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        if (shoppingCart[i].getId() == _id)
        {
            shoppingCart.erase(shoppingCart.begin() + i);
            quantity.erase(quantity.begin()+i);
            continue;
        }
    }
}

void Client::emptyShoppingCart()
{
    int sup = shoppingCart.size() - 1;
    for (int i = sup; i >= 0; i--)
    {
        shoppingCart.erase(shoppingCart.begin() + i);
        quantity.erase(quantity.begin()+i); 
    }
}

std::vector<Item> Client::getShoppingCart()
{
    return shoppingCart;
}

std::vector<int> Client::getQuantity()
{
    return quantity;
}

float Client::getCredit()
{
    return credit;
}

void Client::loadShopCart()
{
    std::string fil = getId() + "_shopcart.csv";
    std::string sup;
    std::vector<std::string> sup2;
    int count = 0;
    std::ifstream test(fil);
    if(!test.good())
    {
        return;
    }
    test.close();
    std::ifstream shopcart;
    shopcart.open(fil);
    while (shopcart.good())
    {
        if (count == 2)
        {
            Item appen(sup2[0]);
            shoppingCart.push_back(appen);
            quantity.push_back(std::stoi(sup2[1]));
            count = 0;
            sup2 = {};
        }
        if (count == 1)
        {
            std::getline(shopcart, sup, '\n');
        }
        else
        {
            std::getline(shopcart, sup, ',');
        }
        sup2.push_back(sup);
        count++;
    }
    shopcart.close();
}

void Client::saveShopCart()
{
    std::ofstream newh(getId() + "_shopcart.csv");
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        newh << shoppingCart[i].getId() << "," << quantity[i] << "\n";
    }
    newh.close();
}

void Client::setCredit(float _newCredit)
{
    credit = _newCredit;
}
