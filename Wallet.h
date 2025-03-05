# pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Wallet{
    public:
        Wallet();
        void accessWallet();
        void insertCurrency(std::string type, double amount);
        void removeCurrency(std::string type, double amount);
        void printWallet();
        bool checkWallet(std::string type, double amount);

    private:
        std::map<std::string, double> currencies;      

    };