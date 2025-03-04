#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Wallet.h"

Wallet::Wallet(){

}

void Wallet::accessWallet(){
    while (true){
        int choice;
        std::cout << "[1] Insert currency into wallet" << std::endl;
        std::cout << "[2] Remove currency from wallet" << std::endl;
        std::cout << "[3] View wallet contents" << std::endl;
        std::cout << "[4] Exit wallet" << std::endl;
        std::cin >> choice;
        if (choice==1){
            std::cout << "Enter currency type: " << std::endl;
            std::string type;
            std::cin >> type;
            std::cout << "Enter amount: " << std::endl; 
            double amount;
            std::cin >> amount;
            insertCurrency(type, amount);
        }
        else if(choice==2){
            std::cout << "Enter currency type: " << std::endl;
            std::string type;
            std::cin >> type;
            std::cout << "Enter amount: " << std::endl; 
            double amount;
            std::cin >> amount;
            removeCurrency(type, amount);
        }
        else if(choice==3){
            try{
                printWallet();
            }
            catch(std::exception& e){
                std::cout << "Error: Wallet not found\n\n\n" << std::endl;
            }
        }
        else if(choice==4){
            break;
        } 
        else{
            std::cout << "Invalid input. Choose between 1, 2, and 3" << std::endl;
        }
    }
}


void Wallet::insertCurrency(std::string type, double amount){
    double balance;
    if (currencies.count(type)==0){
        balance = 0;
    }
    else{
        balance = currencies[type];
//        std::cout << balance << ". The count is: " << currencies.count(type) << std::endl;
    }
    balance += amount;
    currencies[type] = balance;   
    std::cout << "Current balance: " << balance << std::endl;
    std::cout << "Successfully added " << amount << " " << type << " to wallet" << std::endl;
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
        std::cout << "Successfully removed " << amount << " " << type << " from wallet" << std::endl;
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
