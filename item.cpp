#include "item.h"

//constructor default para instanciar un objeto sin necesidad de pasar ningun parametro
Item::Item()
{
    category = "nan";
    description = "nan";
    setDefinition("nan");
    setPrice(-1);
    setStock(-1);
    setBrand("nan");
    discount = -1; 
    setId("nan");
}

//constructor de item usando la id de un producto para obtener la informacion del archivo csv
Item::Item(std::string _id)
{
    std::vector<std::vector<std::string>> data = getData(_id, 7, "products.csv", 8);
    category = data[0][0];
    description = data[0][1];
    setDefinition(data[0][2]);
    setPrice(std::stof(data[0][3]));
    setStock(std::stoi(data[0][4]));
    setBrand(data[0][5]);
    discount = std::stoi(data[0][6]);
    setId(data[0][7]);
}

//getters 
std::string Item::getCategory() {return category;}
std::string Item::getDescription() {return description;}
int Item::getDiscount() {return discount;}

//setters
void Item::setCategory(std::string _category) {category = _category;};
void Item::setDescription(std::string _description) {description = _description;}
void Item::setDiscount(int _discount) {discount = _discount;}