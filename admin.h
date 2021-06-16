#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin: public User
{
    public:

    void addProducts();

    bool deleteProducts(std::string id);

    bool changePrice(std::string id, int modify);

    bool changeStock(std::string id, int modify);

    bool changeDiscount(std::string id, int modify);
};
#endif