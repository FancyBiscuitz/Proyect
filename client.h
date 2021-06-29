#ifndef CLIENT_H
#define CLIENT_H

#include "user.h"
#include "item.h"
#include "utils.h"
#include "purchase.h"
#include <fstream>
#include <vector>

class Client: public User
{

    std::vector<Item> shoppingCart;
    std::vector<int> quantity;
    float credit = 100000.0;
 
    public:

    Client();
    
    Client(std::vector<std::vector<std::string>> data);

    void addProductsToShoppingCart();
    
    void viewShoppingCartProducts();

    void deleteProducsFromShoppingCart();

    void emptyShoppingCart();

    std::vector<Item> getShoppingCart();

    std::vector<int> getQuantity();

    float getCredit();

    void loadShopCart();

    void saveShopCart();

};
#endif