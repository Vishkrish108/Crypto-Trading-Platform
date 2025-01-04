// Removes specification of the class. 
//Tells us how we can use it, not how it actually works.

#include <string>

enum class orderBookType {bid, ask};

class OrderBook{
    public:
        OrderBook(double price, double amount, std::string timestamp, 
                    std::string product, orderBookType orderType);
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        orderBookType orderType;
};
