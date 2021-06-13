#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

#include "user.h"
#include "category.h"
#include "product.h"
#include "utils.h"

using namespace std;

class Administrador: public User{
    public:

    void addProducts()
    {
        
    }

    void deleteProducts()
    {
        
    }

    void changePrice()
    { 
        
    }

    void changeStock()
    {
   
    }
};

class Cliente: public User{
    
    private:
    vector<int> shoppingCart;
    int credit;
 
    public:

    void addProductsToShoppingCart()
    {
        
    }
    
    void viewShoppingCartProducts()
    {

    }

    void deleteProducsToShoppingCart()
    {

    }

};

int main(void)
{
    deleteElementTest("010-RA7y8n");
}
