#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

#include "user.h"
#include "item.h"
#include "product.h"
#include "utils.h"
#include "admin.h"
#include "client.h"

using namespace std;

int main(void)
{
    Admin da;
    da.addProducts();
    da.changePrice("002-H9Ssw6", 727);
    da.changeStock("002-H9Ssw6", 69);
}
