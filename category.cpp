#include "category.h"


std::string Category::getCategory()
{
    return category;
}
std::string Category::getDescription()
{
    return description;
}

void Category::setCategory(std::string _category) {category = _category;};
void Category::setDescription(std::string _description) {description = _description;}; 