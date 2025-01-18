// Removes specification of the class. 
//Tells us how we can use it, not how it actually works.

#pragma once       // Uses the file only once even if called multiple times
#include <string>

enum class orderBookType {bid, ask};

class OrderBook{
    public:
        OrderBook(double price, double amount, std::string timestamp, 
                    std::string product, orderBookType orderType);
        
        /** Converts strings to Order book type of bid / ask */
        static orderBookType str2orderBookType(std::string s);

        /** Returns true if A's timestamp is lesser than B's timestamp */
        static bool sortByTimestamp(OrderBook& A, OrderBook& B);

        double price;
        double amount;
        std::string timestamp;
        std::string product;
        orderBookType orderType;
};
