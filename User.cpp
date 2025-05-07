#include "User.h"

User::User(std::string username, std::string password) 
    : username(username), password(password) {}

void User::addTrade(const std::string& tradeDetails) {
    tradeHistory.push_back(tradeDetails);
}