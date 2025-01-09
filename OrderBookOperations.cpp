#include "OrderBookOperations.h"
#include <iostream>
#include <vector>
#include <string>
#include "OrderBook.h"
#include "csvReader.h"

OrderBookOperations::OrderBookOperations(std::string filename){
    orders = csvReader::readCSV(filename);
    
}

std::vector<std::string> OrderBookOperations::getProducts(){
    std::vector<std::string> products;
    return products;
}

std::vector<OrderBook> OrderBookOperations::getOrders(std::string product, orderBookType type, std::string timestamp){
    std::vector<OrderBook> orders;
    return orders;
}