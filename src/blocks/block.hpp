#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iostream>
#include <vector>
#include <string>
#include "../data/data.hpp"

class Block{
public:
    std::vector<uint8_t> previousHash;  // Hash of previous block
    std::vector<uint8_t> hash;          // Hash of current block
    Data data;                          // Data in block
    time_t timestamp;                   // Timestamp when block was created
    int nonce;                          // Nonce used for mining

    Block(const std::vector<uint8_t>& previousHash = {}, const Data& data = Data());

    void calculateHash();

    void mineBlock(int difficulty);

    void printBlock();

private:
    std::string unit8ToString(const std::vector<uint8_t>& bytes);
};

#endif