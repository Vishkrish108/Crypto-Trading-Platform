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


}




void Wallet::printWallet(){

}


std::string Wallet::toString(){
    
}
