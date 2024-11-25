#include <iostream>
#include <vector>
#include "./blocks/block.hpp"
#include "./data/data.hpp"
#include "./transactions/transaction.hpp"

int main() {
    std::vector<uint8_t>previousHash = {};
    Data data("Alice", "Bob", 100);
    Transaction transaction(data, "test");
    transaction.printTransaction();
    return 0;
}