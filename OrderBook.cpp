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

