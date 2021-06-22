#include "client.h"

using namespace std;

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
