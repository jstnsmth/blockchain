#include "../transactions/transaction.hpp"
#include <iostream>
#include <vector>

class Mempool {
private:
    std::vector<Transaction> transactions;
    size_t maxCapacity;

public:
    Mempool(size_t maxCapacity);
    bool AddTransaction(const Transaction& tx);
    void removeTransactions(const std::vector<Transaction>& transactions);
    std::vector<Transaction> getTransactions(size_t limit);
    bool validateTransaaction(const Transaction& tx);
    void prioritizeTransactions();
    size_t getSize() const;
};