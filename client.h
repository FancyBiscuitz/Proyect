#ifndef CLIENT_H
#define CLIENT_H

#include "user.h"
#include <vector>

class Client: public User{

    std::vector<std::string> shoppingCart;
    int credit;
 
    public:

    void addProductsToShoppingCart();
    
    void viewShoppingCartProducts();

    void deleteProducsFromShoppingCart();

};
#endif