#include "bill.h"

Bill::Bill(std::vector<Purchase> _contents)
{
    contents = _contents;
    for (int i = 0; i < contents.size(); i++)
    {
        total += contents[i].getTotal();
    }
}

void Bill::processBill(Client &_cliente)
{
    Admin master;
    std::vector<std::vector<std::string>> sup;
    for (int i = 0; i < contents.size(); i++)
    {
        master.changeStock(contents[i].getItemId(), contents[i].getStock() - contents[i].getAmount());
    }
    addPurchasesToRecord();
    sup = makeBill();
    std::string str = _cliente.getId() + "_history" + ".csv";
    addBillToRecord(sup, str);
    _cliente.getShoppingCart().clear();
    printBill(_cliente);
}

bool Bill::validateBill(Client &_cliente)
{
    if (_cliente.getCredit() < total)
    {
        return false;
    }
    return true;
}

void Bill::printBill(Client &_cliente)
{
    int biggest = 10;
    std::string ceilfloor;
    std::string spacing;
    std::string halfspacing;
    std::vector<std::string> para = {"Item id", "Brand", "Item", "Item price", "Amount", "Discount", "Total", "Buyer"};
    std::vector<std::vector<std::string>> purchases = makeBill();
    for (int i = 0; i < purchases.size(); i++)
    {
        for (int j = 0; j < purchases[0].size(); j++)
        {
            if (purchases[i][j].size() > biggest)
            {
                biggest = purchases[i][j].size();
            }
        }
    }
    for (int c = 0; c < biggest*(purchases[0].size()); c++)
    {
        if (c < ((biggest*(purchases[0].size()))-45)/2)
        {
            halfspacing += " ";
        }
        ceilfloor += "-";
        spacing += " ";
    }
    std::cout << " " << ceilfloor << std::endl << "|";
    for (int t = 0; t < para.size(); t++)
    {
        outSpaced(para[t], biggest - para[t].size());
    }
    std::cout << "|" << "\n";
    for (int i = 0; i < purchases.size(); i++)
    {
        std::cout << "|";
        for (int j = 0; j < purchases[0].size(); j++)
        {
            outSpaced(purchases[i][j], biggest - purchases[i][j].size());
        }
        std::cout << "|" << "\n";
    }
    std::cout << " " << ceilfloor << std::endl;
    std::cout << halfspacing << "finished purchase at UTC: " << getTimeDate();
    std::cout << halfspacing << "                     Total: " << total << std::endl;
    std::cout << halfspacing << "   Purchased by: " << _cliente.getNames() << " " << _cliente.getSurnames() << std::endl;
    std::cout << " " << ceilfloor << std::endl;
}

void Bill::addPurchasesToRecord()
{
    std::fstream purchases;
    purchases.open("purchases.csv", std::ios::app);
    for (int i = 0; i < contents.size(); i++)
    {
        purchases << contents[i].getItemId() << ",";
        purchases << contents[i].getItemBrand() << ",";
        purchases << contents[i].getItemDefinition() << ",";
        purchases << contents[i].getItemPrice() << ",";
        purchases << contents[i].getAmount() << ",";
        purchases << contents[i].getItemDiscount() << ",";
        purchases << contents[i].getTotal() << ",";
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
    std::ifstream test(userHistoryFile);
    if(!test.good())
    {
        std::ofstream newh(userHistoryFile, std::ios::app);
        newh << _content.size() << ",";
        newh << "-,-,-,-,-,-,-" << "\n";
        for (int i = 0; i < _content.size(); i++)
        {
            for (int j = 0; j < _content[0].size(); j++)
            {
                if (j == _content[0].size() - 1)
                {
                    newh << _content[i][j] << "\n";
                    break;
                }
                newh << _content[i][j] << ",";
            }
        }
        newh.close();
        return;
    }
    test.close();
    std::fstream history;
    history.open(userHistoryFile, std::ios::app);
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
