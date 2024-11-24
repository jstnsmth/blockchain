#include "block.hpp"
#include "../data/data.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <openssl/sha.h>

Block::Block(const std::vector<uint8_t>& previousHash, const Data& data) {
    this->previousHash = previousHash;
    this->timestamp = time(nullptr);
    this->data = data;
    this->nonce = 0;
    calculateHash();
}

std::string Block::uint8ToString(const std::vector<uint8_t>& bytes) {
    std::string str = "";
    for (auto byte: bytes) {
         char buffer[3];
         snprintf(buffer, sizeof(buffer), "%02x", byte);
         str += buffer;
    }
    return str;
}

void Block::calculateHash() {
    std::stringstream ss;

    ss << timestamp;
    ss << nonce;
    ss << data.getSender();
    ss << data.getReceiver();
    ss << data.getAmount();

    for (auto byte : previousHash) {
        ss << static_cast<int>(byte);
    }

    std::string str = ss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    this->hash.clear();
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        this->hash.push_back(hash[i]);
    }
}

void Block::mineBlock(int difficulty) {
    std::cout << "Mining Block: " << std::endl;
    std::string target = "";
    for (int i = 0; i < difficulty; i++) {
        target.append("0");
    }
    do {
        ++nonce;
        calculateHash();
        std::cout << uint8ToString(hash) << std::endl;
    } while (uint8ToString(hash).substr(0, difficulty) != target);
}

void Block::printBlock() {
    struct tm *timeinfo = localtime(&this->timestamp);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    std::cout << "Block Information:" << std::endl;
    std::cout << "Timestamp: " << buffer << std::endl; 
    std::cout << "Nonce: " << this->nonce << std::endl;
    std::cout << "Sender: " << this->data.getSender() << std::endl;
    std::cout << "Receiver: " << this->data.getReceiver() << std::endl;
    std::cout << "Amount: " << this->data.getAmount() << std::endl;
    std::cout << "Previous Hash: " << uint8ToString(this->previousHash) << std::endl;
    std::cout << "Hash: " << uint8ToString(this->hash) << std::endl;
    std::string target(4, '0');
}
