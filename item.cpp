#include "item.h"
//Category,Description,Definition,Price,Stock,Brand,Discount,Ids
Item::Item(std::string _id)
{
    std::vector<std::vector<std::string>> data = getData(_id, 7, "products.csv", 8);
    category = data[0][0];
    description = data[0][1];
    setDefinition(data[0][2]);
    setPrice(std::stoi(data[0][3]));
    setStock(std::stoi(data[0][4]));
    setBrand(data[0][5]);
    discount = std::stoi(data[0][6]);
    setId(data[0][7]);
}

std::string Item::getCategory() {return category;}
std::string Item::getDescription() {return description;}

void Item::setCategory(std::string _category) {category = _category;};
void Item::setDescription(std::string _description) {description = _description;}
void Item::setDiscount(int _discount) {discount = _discount;}