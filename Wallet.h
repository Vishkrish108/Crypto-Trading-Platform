# pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Wallet{
    public:
        Wallet();
        void insertCurrency(std::string type, double amount);
        void removeCurrency(std::string type, double amount);
        void printWallet();
        std::string toString();

    private:
        std::map<std::string, double> currencies;      

    };