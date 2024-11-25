#include "data.hpp"
#include <iostream>

Data::Data() {
    this->sender = "";
    this->receiver = "";
    this->amount = 0;
}

Data::Data(std::string sender, std::string receiver, int amount) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
}

std::string Data::getSender() const {
    return sender;
}

std::string Data::getReceiver() const {
    return receiver;
}

int Data::getAmount() const {
    return amount;
}
