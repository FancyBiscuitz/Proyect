#ifndef CLIENT_H
#define CLIENT_H

#include "user.h"
#include "item.h"
#include "utils.h"
#include <fstream>
#include <vector>

class Client: public User
{

    std::vector<Item> shoppingCart;
    int credit;
 
    public:

    void addProductsToShoppingCart();
    
    void viewShoppingCartProducts();

    void deleteProducsFromShoppingCart();

    std::vector<Item> getShoppingCart();

};
#endif