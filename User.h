#pragma once
#include <string>
#include <vector>
#include "Wallet.h"

class User {
public:
    User() : 
    username(""), password("") {}  // Default constructor
    User(std::string username, std::string password);
    std::string getUsername() const { return username; }
    bool checkPassword(const std::string& inputPassword) const { return password == inputPassword; }
    Wallet& getWallet() { return wallet; }
    void addTrade(const std::string& tradeDetails);
    std::vector<std::string> getTradeHistory() const { return tradeHistory; }

private:
    std::string username;
    std::string password;
    Wallet wallet;
    std::vector<std::string> tradeHistory;
};