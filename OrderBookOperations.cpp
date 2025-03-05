#include "OrderBookOperations.h"
#include <iostream>
#include <vector>
#include <string>
#include "OrderBook.h"
#include "csvReader.h"
#include <map>
#include <limits> // for infinity
#include <algorithm> // for sort

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
    return temp_orders;
}


double OrderBookOperations::getHighestPrice(std::vector<OrderBook>& orders){
    double max_price = 0.0;
    for (int i=0; i<orders.size(); ++i){
        if (orders[i].price>max_price){
            max_price = orders[i].price;
        }
    }   
    return max_price;
}

double OrderBookOperations::getLowestPrice(std::vector<OrderBook>& orders){
    double min_price = std::numeric_limits<double>::infinity();
    for (int i=0; i<orders.size(); ++i){
        if (orders[i].price<min_price){
            min_price = orders[i].price;
        }
    }
    return min_price;
}


std::string OrderBookOperations::getEarliestTimestamp(){
    return orders[0].timestamp;
}

std::string OrderBookOperations::getNextTimestamp(std::string timestamp){
    std::string next_timestamp="";
    for (int i=0; i<orders.size(); ++i){
        if (orders[i].timestamp > timestamp){
            next_timestamp = orders[i].timestamp;
            break;
        }
    }

    if (next_timestamp==""){
        // return getNextTimestamp(orders[0].timestamp); // If i want to loop back to the start
        return "No next timestamp";
    }

    return next_timestamp;
}

/** Adds the entry to end of orderbook. Sorts it to place in correct position */
void OrderBookOperations::insertEntry(OrderBook& order){
    orders.push_back(order);
    std::cout << "Push back works!" << std::endl;
    std::sort(orders.begin(), orders.end(), OrderBook::sortByTimestamp);   
}

// Using pseudocode as reference 
std::vector<OrderBook> OrderBookOperations::matchAsksToBids(std::string product, std::string timestamp){
    //asks = orderbook.asks
    std::vector<OrderBook> asks = getOrders(product, orderBookType::ask, timestamp);    

    //bids= orderbook.bids
    std::vector<OrderBook> bids = getOrders(product, orderBookType::bid, timestamp);

    //sales=[]
    std::vector<OrderBook> sales;

    // Sort the asks and bids in ascending
    std::sort(asks.begin(), asks.end(), OrderBook::sortByPrice); 
    std::sort(bids.begin(), bids.end(), OrderBook::sortByPrice);
    
    for (OrderBook& ask : asks){
        for (OrderBook& bid : bids){
            if (bid.price >= ask.price){
                OrderBook sale{ask.price, 0.0, timestamp, product, orderBookType::sale};
                if (bid.amount == ask.amount){
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    break;
                }
                if (bid.amount > ask.amount){
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount - ask.amount;
                    break;
                }
                if (bid.amount < ask.amount){
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    ask.amount = ask.amount - bid.amount;
                    bid.amount = 0;
                    continue;
                }
            }
        }
    }   
    return sales;

};
