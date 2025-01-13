#include "OrderBookOperations.h"
#include <iostream>
#include <vector>
#include <string>
#include "OrderBook.h"
#include "csvReader.h"
#include <map>

OrderBookOperations::OrderBookOperations(std::string filename){
    orders = csvReader::readCSV(filename);
    
}

/** Maps the set of exchanges and keeps track of unique ones for matching */
std::vector<std::string> OrderBookOperations::getProducts(){
    std::vector<std::string> products;
    std::map<std::string, bool> productMap;
    for (int i=0; i<orders.size(); ++i){
        productMap[orders[i].product] = true; 
    }

    // flattening the map to a vector of strings
    // pulls each element from productMap. x.first gives key, x.last gives value
    for (auto const& x : productMap){
        products.push_back(x.first);
    }

    return products;
}

std::vector<OrderBook> OrderBookOperations::getOrders(std::string product, orderBookType type, std::string timestamp){
    std::vector<OrderBook> temp_orders{};
    for (OrderBook& i : orders){
        if (i.orderType == type && i.product == product && i.timestamp == timestamp){
            //std::cout << "Product: " << i.product << " " << product << std::endl;
            temp_orders.push_back(i);
        }
    }
    return orders;
}