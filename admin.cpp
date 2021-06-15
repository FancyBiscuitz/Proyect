#include "admin.h"
#include "utils.h"
#include <fstream>
#include <vector>

void Admin::addProducts()
{
    std::ofstream products;
    products.open("products.csv", std::ios::app); // Abre el archivo
    std::string category, description, id, definition, brand;
    int price, stock;
    int i = 0;
    std::vector<std::string> list = getDataCol("products.csv", 2, 7);
    if(products.good())
    {
        products << "\n";
        std::cout << "Category: ";
        std::getline(std::cin, category);
        products << category << ",";
        std::cout << std::endl;

        std::cout << "Description: ";
        std::getline(std::cin, description);
        products << description << ",";
        std::cout << std::endl;

        do
        {
            if (i > 0) {std::cout << "Product already exists." << std::endl;}
            std::cout << "Definition: ";
            std::getline(std::cin, definition);
            std::cout << std::endl;
            i++;
        } while (std::find(list.begin(), list.end(), definition) != list.end());
        products << definition << ",";

        std::cout << "Price: ";
        std::cin >> price;
        products << price << ",";
        std::cout << std::endl;

        std::cout << "Stock: ";
        std::cin >> stock;
        products << stock << ",";
        std::cout << std::endl;

        std::cout << "Brand: ";
        std::getline(std::cin, brand);
        std::getline(std::cin, brand);
        products << brand << ",";
        std::cout << std::endl;

        products << getProductId(category);
    }
    products.close();
}

bool Admin::deleteProducts(std::string id)
{
    std::vector<std::vector<std::string>> data;
    data = getData("products.csv", 7);
    std::remove("products.csv");
    int sup = 0;
    bool res = false;

    std::ofstream newfile("products.csv");
    
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][data[i].size()-1] == id)
        {
            res = true;
            continue;
        }
        for (int j = 0; j < data[0].size(); j++)
        {
            if (j == data[0].size()-1)
            {
                newfile << data[i][j] << "\n";
                continue;
            }
            newfile << data[i][j] << ",";
        }
    }
    newfile.close();
    return res;
}

bool Admin::changePrice(std::string id, int modify)
{
    std::vector<std::vector<std::string>> all = getData("products.csv", 7);
    std::vector<std::string> sup;
    bool res = false;
    for (int i = 0; i < all.size(); i ++)
    {
        if (all[i][all[i].size()-1] == id)
        {
            all[i][3] = std::to_string(modify);
            res = true;
            break;
        }
    }
    if (res)
    {
        std::remove("products.csv");
        std::ofstream newfile("products.csv");
        for (int i = 0; i < all.size(); i++)
        {
            for (int j = 0; j < all[0].size(); j++)
            {
                if (j == all[0].size()-1)
                {
                    newfile << all[i][j] << "\n";
                    continue;
                }
                newfile << all[i][j] << ",";
            }
        }
        return res;
    }
    std::cout << "Id not found." << std::endl;
    return res;
}

bool Admin::changeStock(std::string id, int modify)
{
    std::vector<std::vector<std::string>> all = getData("products.csv", 7);
    std::vector<std::string> sup;
    bool res = false;
    for (int i = 0; i < all.size(); i ++)
    {
        if (all[i][all[i].size()-1] == id)
        {
            all[i][4] = std::to_string(modify);
            res = true;
            break;
        }
    }
    if (res)
    {
        std::remove("products.csv");
        std::ofstream newfile("products.csv");
        for (int i = 0; i < all.size(); i++)
        {
            for (int j = 0; j < all[0].size(); j++)
            {
                if (j == all[0].size()-1)
                {
                    newfile << all[i][j] << "\n";
                    continue;
                }
                newfile << all[i][j] << ",";
            }
        }
        return res;
    }
    std::cout << "Id not found." << std::endl;
    return res;
}
