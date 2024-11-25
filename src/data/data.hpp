#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
private:
    std::string sender;    // Person sending amount
    std::string receiver;  // Person receiving amount
    int amount;            // Total amount

public:
    Data();
    Data(std::string sender, std::string receiver, int amount);

    // Getters 
    std::string getSender() const;
    std::string getReceiver() const;
    int getAmount() const;
};

#endif // DATA_HPP