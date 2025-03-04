#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Wallet.h"

Wallet::Wallet(){

}


void Wallet::insertCurrency(std::string type, double amount){
    double balance;
    if (currencies.count(type)==0){
        balance = 0;
    }
    else{
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;   
}



void Wallet::removeCurrency(std::string type, double amount){
    if (currencies.count(type)==0){
        throw "Currency not found";
    }
    else{
        double balance = currencies[type];
        if (balance < amount){
            throw "Insufficient funds";
        }
        balance -= amount;
        currencies[type] = balance;
    }
}


void Wallet::printWallet(){ // empty wallet handled in Functions.cpp
    for (int i=0; i<currencies.size(); ++i){
        std::cout << currencies[0] << std::endl;
        //std::cout << currencies[0] << currencies[1] << std::endl; //In my head currencies[0]->type, currencies[1]->amount but this throws an error
    }
}


std::string Wallet::toString(){
    return "Wallet";
}
