#include "item.h"

Item::Item(std::string _category, std::string _description, std::string _definition, int _price, int _stock, std::string _brand, std::string _id)
{
    category = _category;
    description = _description;
    setDefinition(_definition);
    setPrice(_price);
    setStock(_stock);
    setBrand(_brand);
    setId(_id);
}

std::string Item::getCategory()
{
    return category;
}
std::string Item::getDescription()
{
    return description;
}

void Item::setCategory(std::string _category) {category = _category;};
void Item::setDescription(std::string _description) {description = _description;}; 