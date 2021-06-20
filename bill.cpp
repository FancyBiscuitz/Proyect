#include "bill.h"

Bill::Bill(std::vector<Purchase> _contents)
{
    contents = _contents;
    for (int i = 0; i < contents.size(); i++)
    {
        total += contents[i].getTotal();
    }
}

void Bill::processBill(Client _cliente)
{
    Admin master;
    std::vector<std::vector<std::string>> sup;
    for (int i = 0; i < contents.size(); i++)
    {
        master.changeStock(contents[i].getItemId(), contents[i].getStock() - contents[i].getAmount());
    }
    addPurchasesToRecord();
    sup = makeBill();
    std::string str = "history|" + _cliente.getId();
    addBillToRecord(sup, str);
}

bool Bill::validateBill(Client _cliente)
{
    if (_cliente.getCredit() < total)
    {
        return false;
    }
    return true;
}

void Bill::printBill()
{

}

void Bill::addPurchasesToRecord()
{
    std::fstream purchases;
    purchases.open("purchases.csv", std::ios::app);
    for (int i = 0; i < contents.size(); i++)
    {
        purchases << contents[i].getItemId();
        purchases << contents[i].getItemBrand();
        purchases << contents[i].getItemDefinition();
        purchases << contents[i].getItemPrice();
        purchases << contents[i].getAmount();
        purchases << contents[i].getItemDiscount();
        purchases << contents[i].getTotal();
        purchases << contents[i].getBuyer();
        purchases << "\n";
    }
    purchases.close();
}

std::vector<std::vector<std::string>> Bill::makeBill()
{
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> sup;
    for (int i = 0; i < contents.size(); i++)
    {
        sup.push_back(contents[i].getItemId());
        sup.push_back(contents[i].getItemBrand());
        sup.push_back(contents[i].getItemDefinition());
        sup.push_back(std::to_string(contents[i].getItemPrice()));
        sup.push_back(std::to_string(contents[i].getAmount()));
        sup.push_back(std::to_string(contents[i].getItemDiscount()));
        sup.push_back(std::to_string(contents[i].getTotal()));
        sup.push_back(contents[i].getBuyer());
        res.push_back(sup);
        sup = {};
    }
    return res;
}

void Bill::addBillToRecord(std::vector<std::vector<std::string>> _content, std::string userHistoryFile)
{
    std::fstream history;
    history.open(userHistoryFile, std::ios::app);
    if(!history.good())
    {
        history.close();
        std::ofstream newHistory(userHistoryFile);
        newHistory << _content.size() << ",";
        newHistory << "-,-,-,-,-,-,-" << "\n";
        for (int i = 0; i < _content.size(); i++)
        {
            for (int j = 0; j < _content[0].size(); j++)
            {
                if (j == _content[0].size() - 1)
                {
                    newHistory << _content[i][j] << "\n";
                    break;
                }
                newHistory << _content[i][j] << ",";
            }
        }
        newHistory.close();
        return;
    }
    history << _content.size() << ",";
    history << "-,-,-,-,-,-,-" << "\n";
    for (int i = 0; i < _content.size(); i++)
    {
        for (int j = 0; j < _content[0].size(); j++)
        {
            if (j == _content[0].size() - 1)
            {
                history << _content[i][j] << "\n";
                break;
            }
            history << _content[i][j] << ",";
        }
    }
    history.close();
}
