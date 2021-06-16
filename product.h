#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product
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
    void setPrice(int _price);
    void setDefinition(std::string _definition);
    void setStock(int _stock);
    void setBrand(std::string _brand);
};
#endif