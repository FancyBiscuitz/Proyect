#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include "product.h"

class Category : public Product
{
    std::string category;
    std::string description;

    public:
    
    std::string getCategory();
    std::string getDescription();
    
    void setCategory(std::string _category);
    void setDescription(std::string _description);

};
#endif