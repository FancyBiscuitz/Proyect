#include "product.h"

std::string Product::getId()
{
    return id;
}
int Product::getPrice()
{
    return price;
}
std::string Product::getDefinition()
{
    return definition;
}
std::string Product::getBrand(){
    return brand;
}
int Product::getStock()
{
    return stock;
}

void Product::setId(std::string _id)
{
    id = _id;
}
void Product::setPrecio(int _price)
{
    price = _price;
}
void Product::setDescripcion(std::string _definition)
{
    definition = _definition;
}
void Product::setStock(int _stock)
{
    stock = _stock;
}
void Product::setBrand(int _brand)
{
brand = _brand;
}

