#include "User.h"

User::User(std::string username) : username(username) {}

void User::addTrade(const std::string& tradeDetails) {
    tradeHistory.push_back(tradeDetails);
}