#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "../data/data.hpp"
#include <iostream>

class Transaction {
private:
    Data data;
    std::string transactionID;
    std::string signature;
    time_t timestamp;

    std::string calculateTransactionID();

public:
    Transaction(const Data& data, const std::string& signature);

    void printTransaction() const;

    std::string getTransactionID() const;
    std::string getSignature() const;
    time_t getTimestamp() const;
    Data getData() const;
};

#endif // TRANSACTION_HPP