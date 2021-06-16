#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "product.h"

class Item : public Product
{
    std::string category;
    std::string description;

    public:
    Item(std::string _category, std::string _description, std::string _definition, int _price, int _stock, std::string _brand, std::string _id);
    std::string getCategory();
    std::string getDescription();
    
    void setCategory(std::string _category);
    void setDescription(std::string _description);

};
#endif