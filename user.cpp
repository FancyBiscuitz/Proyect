#include "user.h"

//getters
std::string User::getNames() {return names;}
std::string User::getSurnames() {return surnames;}
std::string User::getUsername() {return userName;}
int User::getAge() {return age;}
std::string User::getPhoneNumber() {return phoneNumber;}
std::string User::getId() {return id;}
std::string User::getPassword() {return password;}
    
//setters
void User::setNames(std::string _names) {names = _names;}
void User::setSurnames(std::string _surnames) {surnames = _surnames;}
void User::setUsername(std::string _username){userName = _username;}
void User::setEdad(int _age) {age = _age;}
void User::setPhoneNumber(std::string _phonenumber) {phoneNumber = _phonenumber;}
void User::setId(std::string _id) {id = _id;}
void User::setPassword(std::string _password) {password = _password;}
