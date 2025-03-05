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
        // throw "Currency not found";
        std::cout << "Currency not found in wallet\n" << std::endl;
        return;
    }
    else{
        double balance = currencies[type];
        if (balance < amount){
            // throw "Insufficient funds";
            std::cout << "Insufficient funds. Cannot remove " << amount << " " << type << " from wallet\n" << std::endl;
            return;
        }
        balance -= amount;
        currencies[type] = balance;
        std::cout << "Successfully removed " << amount << " " << type << " from wallet\n" << std::endl;
    }
}


void Wallet::printWallet(){ // empty wallet handled in accessWallet()
    if (currencies.size()==0){
        std::cout << "Wallet is empty\n" << std::endl;
        return;
    }
    for (std::pair<std::string, double> element : currencies){
        std::cout << element.first << ": " << element.second << std::endl;
    }
}


bool Wallet::checkWallet(std::string type, double amount){
    for (std::pair<std::string, double> element : currencies){
        if (element.first == type){
            if (currencies[type]-amount >= 0){
                return true;
            }
            return false;
        }
    }
    return false;
}
