#include "purchase.h"

Purchase::Purchase(Item _pdt, int _amount, std::string client_id)
{
    buyer = client_id;
    itemId = _pdt.getId();
    itemDefinition = _pdt.getDefinition();
    itemBrand = _pdt.getBrand();
    itemDiscount = _pdt.getDiscount();
    itemPrice = _pdt.getPrice();
    itemStock = _pdt.getStock();
    if (_amount > _pdt.getStock())
    {
        amount = _pdt.getStock();
    }
    else
    {
        amount = _amount;
    }
    total = (itemPrice - (itemPrice*(itemDiscount/100.0)) )* (float) amount;
}

std::string Purchase::getBuyer() {return buyer;}
std::string Purchase::getItemId() {return itemId;}
std::string Purchase::getItemDefinition() {return itemDefinition;}
std::string Purchase::getItemBrand() {return itemBrand;}
float Purchase::getItemPrice() {return itemPrice;}
int Purchase::getItemDiscount() {return itemDiscount;}
float Purchase::getTotal() {return total;}
int Purchase::getAmount() {return amount;}
int Purchase::getStock() {return itemStock;}
