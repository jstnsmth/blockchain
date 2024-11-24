#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
private:
    std::string sender;
    std::string receiver;
    int amount;

public:
    Data();
    Data(std::string sender, std::string receiver, int amount);
    std::string getSender();
    std::string getReceiver();
    int getAmount();
};

#endif // DATA_HPP