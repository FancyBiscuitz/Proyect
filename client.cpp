#include "client.h"

using namespace std;

void Client::addProductsToShoppingCart()
{
    string id;
    string check;
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
        }
        if (check2)
        {
            std::cout << "Already in shopping cart." << std::endl;
        }
        else
        {
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

}

void Client::deleteProducsFromShoppingCart()
{

}

std::vector<Item> Client::getShoppingCart()
{
    return shoppingCart;
}