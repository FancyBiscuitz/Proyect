#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>
#include "client.h"
#include "utils.h"

class Purchase
{
private:
    std::string purchaseDate;
    std::string time;
    int discount;
    std::string purchaseNumber;
    int Total;
    int tax;
public:

    bool validatePurchase(std::vector<Item> items);
    
    std::string getPurchaseDate();
    std::string getTime();
    int getDiscount();
    std::string getPurchaseNumber();
    int getTotal();
    int getTax();

    void setPurchaseDate(string _purchaseDate);
    void setTime(string _time);
    void setDiscount(int _discount);
    void setPurchaseNumber(string _purchaseNumber);
    void setTotal(int _Total);
    void setTax(int _tax);

};
  
/*
Metodos:
-Validar compra
-Comprar
*/
#endif