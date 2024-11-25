#include "../transactions/transaction.hpp"
#include <ctime>
#include <sstream>
#include <openssl/sha.h>

Transaction::Transaction(const Data& data, const std::string& signature) {
    this->data = data;
    this->signature = signature;
    this->timestamp = time(nullptr);
    this->transactionID = calculateTransactionID();
}

std::string Transaction::calculateTransactionID() {
    std::stringstream ss;

    ss << data.getSender();
    ss << data.getReceiver();
    ss << std::to_string(data.getAmount());
    ss << std::to_string(timestamp);

    std::string str = ss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    std::string transactionID;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        std::stringstream byteStream;
        byteStream << std::hex << static_cast<int>(hash[i]);
        transactionID += byteStream.str();
    }
    return transactionID;
}

void Transaction::printTransaction() const {
    struct tm *timeinfo = localtime(&this->timestamp);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    std::cout << "Transaction Information:" << std::endl;
    std::cout << "Sender: " << data.getSender() << std::endl;
    std::cout << "Receiver: " << data.getReceiver() << std::endl;
    std::cout << "Amount: " << std::to_string(data.getAmount()) << std::endl;
    std::cout << "Transaction ID: " << transactionID << std::endl;
    std::cout << "Timestamp: " << buffer << std::endl;
    std::cout << "Signature: " << signature << std::endl;
}

std::string Transaction::getTransactionID() const { return transactionID; }
std::string Transaction::getSignature() const { return signature; }
time_t Transaction::getTimestamp() const { return timestamp; }
Data Transaction::getData() const { return data; }
