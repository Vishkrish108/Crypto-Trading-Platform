# include "OrderBook.h"
OrderBook::OrderBook(double price, double amount, std::string timestamp, 
                    std::string product, orderBookType orderType)
        : price(price), amount(amount), timestamp(timestamp),
         product(product), orderType(orderType)
        {

        }
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        orderBookType orderType;

orderBookType OrderBook::str2orderBookType(std::string s){
    if (s == "bid"){
        return orderBookType::bid;
    }
    else if (s == "ask"){
        return orderBookType::ask;
    }
    else{
        throw std::exception{};
    }
}

bool OrderBook::sortByTimestamp(OrderBook& A, OrderBook& B){
    return A.timestamp < B.timestamp;
}
