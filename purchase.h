#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>
#include "client.h"
#include "utils.h"
#include "item.h"

class Purchase
{
    private:
    std::string buyer;
    std::string itemId;
    std::string itemDefinition;
    std::string itemBrand;
    float itemPrice;
    int itemDiscount;
    int itemStock;
    float total;
    int amount;
    public:

    Purchase();
    Purchase(Item pdt, int _amount, std::string client_id);
    
    std::string getBuyer();
    std::string getItemId();
    std::string getItemDefinition();
    std::string getItemBrand();
    float getItemPrice();
    int getItemDiscount();
    float getTotal();
    int getAmount();
    int getStock();
};

#endif