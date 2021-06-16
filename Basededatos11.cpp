#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

#include "user.h"
#include "item.h"
#include "product.h"
#include "utils.h"
#include "admin.h"
#include "client.h"

using namespace std;

int main(void)
{
    Client dod;
    std::string id;
    while(true)
    {
        dod.addProductsToShoppingCart();
        std::cout << "count: " << (dod.getShoppingCart()).size();
    }
}
