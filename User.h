#pragma once
#include <string>
#include <vector>
#include "Wallet.h"

class User {
public:
    User() : username("") {}  // Default constructor
    User(std::string username);
    std::string getUsername() const { return username; }
    Wallet& getWallet() { return wallet; }
    void addTrade(const std::string& tradeDetails);
    std::vector<std::string> getTradeHistory() const { return tradeHistory; }

private:
    std::string username;
    Wallet wallet;
    std::vector<std::string> tradeHistory;
};