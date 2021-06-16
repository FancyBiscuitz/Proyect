#include "purchase.h"

using namespace std;

string Purchase::getPurchaseDate()
{
    return purchaseDate;
}

string Purchase::getTime()
{
    return time;
}

int Purchase::getDiscount()
{
    return discount;
}

string Purchase::getPurchaseNumber()
{
    return purchaseNumber;
}

int Purchase::getTotal()
{
    return Total;
}

int Purchase::getTax()
{
    return tax;
}

void Purchase::setPurchaseDate(string _purchaseDate){purchaseDate = _purchaseDate;}
void Purchase::setTime(string _time){time = _time;} 
void Purchase::setDiscount(int _discount){discount = _discount;}
void Purchase::setPurchaseNumber(string _purchaseNumber){purchaseNumber = _purchaseNumber;}
void Purchase::setTotal(int _Total){Total = _Total;}
void Purchase::setTax(int _tax){tax = _tax;}
