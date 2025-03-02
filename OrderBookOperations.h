#pragma once
#include "OrderBook.h"
#include <vector>
#include <string>
#include "csvReader.h"


// Functions are getOrders, getProducts (usd, btc, eth...)
class OrderBookOperations{
    public:
        OrderBookOperations(std::string filename);
        std::vector<std::string> getProducts();
        std::vector<OrderBook> getOrders(std::string product, orderBookType type, std::string timestamp);

        static double getHighestPrice(std::vector<OrderBook>& orders);
        static double getLowestPrice(std::vector<OrderBook>& orders);

        std::string getEarliestTimestamp(); // Returns the first timestamp in the csv file
        std::string getNextTimestamp(std::string timestamp);

        void insertAsks(OrderBook& order);

        std::vector<OrderBook> matchAsksToBids(std::string product, std::string timestamp);

    private:
        std::vector<OrderBook> orders; // to store the orders after reading the csv file
};