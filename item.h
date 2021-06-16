#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include "product.h"
#include "utils.h"

class Item : public Product
{
    std::string category;
    std::string description;
    int discount;

    public:
    Item(std::string);
    std::string getCategory();
    std::string getDescription();
    
    void setCategory(std::string _category);
    void setDescription(std::string _description);
    void setDiscount(int _discount);

};
#endif