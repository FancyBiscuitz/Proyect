#ifndef USER_H
#define USER_H
#include <iostream>

class User
{

    std::string names;
    std::string surnames;
    std::string userName;
    int age;
    std::string phoneNumber;
    std::string id;
    std::string password;

public:
    //getters
    std::string getNames();
    std::string getSurnames();
    std::string getUsername();
    int getAge();
    std::string getPhoneNumber();
    std::string getId();
    std::string getPassword();
    
    //setters
    void setNames(std::string _names);
    void setSurnames(std::string _surnames);
    void setUsername(std::string _username);
    void setEdad(int _age);
    void setPhoneNumber(std::string _phonenumber);
    void setId(std::string _id);
    void setPassword(std::string _password);
};
#endif