#include "csvReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "OrderBook.h"


csvReader::csvReader(){
    
}


std::vector<OrderBook> csvReader::readCSV(std::string csvFile){    // returns vector of orderbook
    std::vector<OrderBook> orders;
    std::ifstream file{csvFile};
    std::string line;
    if (file.is_open()){
        while (std::getline(file, line)){
            try{
                OrderBook order = str2OB(tokenise(line, ','));  // tokenise returns vector of strings
                orders.push_back(order);
            }
            catch(const std::exception& e){
                std::cout << "Error: Bad data. Could not convert str to obe" << std::endl;
                continue;
            }
        }
        file.close();
    }
    else{
        std::cout << "file not opened" << std::endl;
    }
    return orders;
}    

std::vector<std::string> csvReader::tokenise(std::string csvLine, char separator){ // returns vector of strings
    std::vector<std::string> tokens;
    std::string token;
    for(int i = 0; i < csvLine.size(); i++){
        if(csvLine[i] != separator){
            token += csvLine[i];
        } 
        else{
            tokens.push_back(token);
            token = "";
        }
    }
    tokens.push_back(token);
    return tokens;
}


/** Converts strings to required double and enum formats */
OrderBook csvReader::str2OB(std::vector<std::string> tokens){ // returns OrderBook itself
    // tokens = timestamp, product, orderType, price, amount
    double price, amount;
    if (tokens.size()!=5){
        //std::cout << "Error: wrong number of tokens" << std::endl;
        throw std::exception{};
    }
    
    try{
        price = std::stod(tokens[3]); // Price
        amount = std::stod(tokens[4]); // Amount
    }
    catch(const std::exception& e){
        std::cout << "Error: value is not a double" << tokens[3] << " or " << tokens[4] << std::endl;
        throw;
    }
        
    OrderBook order{price,amount,tokens[0],tokens[1], OrderBook::str2orderBookType(tokens[2])};
    return order;
}

