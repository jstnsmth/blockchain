#include <iostream>
#include <vector>
#include "./blocks/block.hpp"
#include "./data/data.hpp"

int main() {
    std::vector<uint8_t>previousHash = {};
    Data data("Alice", "Bob", 100);
    Block newBlock(previousHash, data);
    newBlock.printBlock();
    newBlock.mineBlock(2);
    return 0;
}