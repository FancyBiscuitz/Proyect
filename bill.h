#ifndef BILL_H
#define BILL_H

#include "purchase.h"
#include "client.h"
#include "admin.h"
#include "utils.h"
#include <iostream>
#include <chrono>
#include <ctime>

class Bill
{
private:
    std::vector<Purchase> contents;
    float total;
public:
    Bill(std::vector<Purchase> _contents);

    void processBill(Client &_cliente);
    bool validateBill(Client &_cliente);
    void printBill(Client &_cliente);
    void addPurchasesToRecord();
    std::vector<std::vector<std::string>> makeBill();
    void addBillToRecord(std::vector<std::vector<std::string>> _content, std::string userHistoryFile);
    float getTotal();
};

#endif