#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "category.h"

class Product : public Category
{
    private:
    std::string id;
    int stock;
    std::string brand;
    int price;
    std::string definition;

    public:
    //getters
    std::string getId();
    int getPrice();
    std::string getDefinition();
    std::string getBrand();
    int getStock();

    //setters
    void setId(std::string _id);
    void setPrecio(int _price);
    void setDescripcion(std::string _definition);
    void setStock(int _stock);
    void setBrand(int _brand);
};
#endif