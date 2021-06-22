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
#include "purchase.h"
#include "bill.h"

using namespace std;

int main(void)
{
    Client cliente;
    cliente.setId("testid");
    std::vector<Purchase> billData;
    cliente.addProductsToShoppingCart();
    
    for (int i = 0; i < cliente.getShoppingCart().size(); i++)
    {
        Purchase compra(cliente.getShoppingCart()[i], cliente.getQuantity()[i], cliente.getId());
        billData.push_back(compra);
    }
    for (int j = 0; j < cliente.getShoppingCart().size(); j++)
    {
        std::cout << cliente.getShoppingCart()[j].getId() << std::endl;
    }
    Bill factura(billData);
    if (factura.validateBill(cliente))
    {
        factura.processBill(cliente);
    }
}