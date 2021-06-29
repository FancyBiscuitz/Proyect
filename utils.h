#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>

#include "item.h"

std::string itemIdMaker(std::string base, int size);
void register_user();
std::string log_in();
void menuRegisterAndLogin();
void addProduct();
std::string getProductId(std::string category);
bool deleteElementTest(std::string id);
std::vector<std::vector<std::string>> getData(std::string support, int index, std::string file, int columms);
std::vector<std::vector<std::string>> getData(std::string file, int columms);
void outSpaced(std::string word, int spacing);
void showData(std::vector<std::vector<std::string>> data, std::string mode);
std::vector<std::string> getDataCol(std::string file, int columm, int columms);
std::string getRole();
bool validateId(std::string id, std::string mode, int coluums);
std::string getTimeDate();
void printMenu(std::string mode);
std::string getInitials(std::string word, int limit);
std::string checkValidOption(std::string option, int limit, std::string defaul);
std::string loginMenu();
std::string mainMenu(std::string mode);
std::string processMainMenuOption(std::string mode, std::string option);
#endif