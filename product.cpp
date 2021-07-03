#include "product.h"

//getters para tener acceso a la informacion del producto
std::string Product::getId()
{
    return id;
}
float Product::getPrice()
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

//setters para cambiar las especificaciones del producto
void Product::setId(std::string _id)
{
    id = _id;
}
void Product::setPrice(float _price)
{
    price = _price;
}
void Product::setDefinition(std::string _definition)
{
    definition = _definition;
}
void Product::setStock(int _stock)
{
    stock = _stock;
}
void Product::setBrand(std::string _brand)
{
    brand = _brand;
}
