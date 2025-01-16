#include "Functions.h"
#include <iostream> 
#include <vector>
#include <string>
#include "OrderBook.h"
#include "csvReader.h"
#include "OrderBookOperations.h"
#include <limits>

Functions::Functions(){
    
}

/** Starts the entire program */
void Functions::init(){
    std::cout << "Welcome to the stock exchange!" << std::endl;

    currentTime = OrderBookOperations.getEarliestTimestamp(); // First timestamp in csv file
    while(true){       
        printMenu();
        int choice = userChoice();  // Taking user's choice
        processChoice(choice);
    }
}

void Functions::printMenu(){
    std::cout << "======================" << std::endl;
    
    // 1. Help
    std::cout << "[1] Print help" << std::endl;

    // 2. Print the stats/orders
    std::cout << "[2] Print exchange stats" << std::endl;
    
    // 3. Make an offer
    std::cout << "[3] Make an offer " << std::endl;
    
    // 4. Make a bid
    std::cout << "[4] Make a bid " << std::endl;
    
    // 5. View personal portfolio
    std::cout << "[5] Print wallet" << std::endl;
    
    // 6. Continue
    std::cout << "[6] Continue to next timeframe" << std::endl;
    
    std::cout << "======================" << std::endl;
    std::cout << "Enter a number 1-6: " << std::endl;
}

std::vector<std::string> Functions::convertTokensToSize5(std::vector<std::string>& tokens){     // returns 5 strings, including timestamp and order type
    // tokens = timestamp, product, orderType, price, amount
    std::string product = tokens[0];
    double price = std::stod(tokens[1]);
    double amount = std::stod(tokens[2]);
    tokens[0] = currentTime;
    tokens[1] = product;
    tokens[2] = "ask";  // Convert to OB type using csvReader::str2OB
    tokens.resize(5);
    tokens[3] = std::to_string(price);      // Defined as per OrderBook format
    tokens[4] = std::to_string(amount);
    return tokens;
}

int Functions::userChoice(){
    int choice;
    std::cin >> choice;
    std::cout << "You chose: " << choice << std::endl;
    return choice;
}

void Functions::printHelp(){
    std::cout << "Help - Your aim is to make profits by analysing the market. Sell high, buy low" << std::endl;
}

// Printing wrong entry and entry2 sizes. Gives 3540 for both, for all products
void Functions::printStatistics(){ 
    for(std::string const& product : OrderBookOperations.getProducts()){
        std::cout << "Product: " << product << std::endl;
        std::vector<OrderBook> entry = OrderBookOperations.getOrders(product, orderBookType::ask, currentTime); 
        std::cout << "Asks per product: " << entry.size() << std::endl;
        std::cout << "Highest: " << OrderBookOperations.getHighestPrice(entry) << std::endl;
        std::cout << "Lowest: " << OrderBookOperations.getLowestPrice(entry) << std::endl;
        std::vector<OrderBook> entry2 = OrderBookOperations.getOrders(product, orderBookType::bid, currentTime); 
        std::cout << "Bids per product: " << entry2.size() << std::endl;
        
    }
//    std::cout << "Market contains: " << orders.size() << " entries" << std::endl;
}

/** Putting out an offer and storing in the orderbook */
void Functions::makeOffer(){
    std::string userLine;
    std::cout << "Enter the ask in format Product to be sold, Price, Amount" << std::endl;
    std::cout << "For example: BTC/USDT, 10000, 0.5" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clearing the buffer, allowing the input to be read properly.
    std::getline(std::cin, userLine);    

    std::vector<std::string> tokens = csvReader::tokenise(userLine, ',');
    if (tokens.size() != 3){
        std::cout << "Invalid input. Please enter in the format Product, Price, Amount" << std::endl;
        return;
    }
    std::cout << "Product: " << tokens[0] << " Price: " << tokens[1] << " Amount: " << tokens[2] << std::endl;
    tokens = convertTokensToSize5(tokens);
    try{
        if (tokens.size()==5){
            ;
        }
    }
    catch(const std::exception& e){
        std::cout << "Error: Size of entered input not five " << std::endl;
        throw;
    }
    OrderBook order = csvReader::str2OB(tokens);
    // Need to now push this to the csv file
}

void Functions::makeBid(){
    std::cout << "TO DO" << std::endl;
}

void Functions::viewPortfolio(){
    std::cout << "TO DO" << std::endl;
}

void Functions::simulateNextTimeframe(){
    std::cout << "Moving on..." << std::endl;
    currentTime = OrderBookOperations.getNextTimestamp(currentTime);
}

void Functions::displayInputError(){
    std::cout << "Invalid input. Please enter a number 1-6" << std::endl;
}

void Functions::processChoice(int choice){
    if (choice == 1){   // help
        printHelp();
    }
    else if (choice == 2){ // print stats
        printStatistics();
    }
    else if (choice == 3){  // make an offer
        makeOffer();
    }
    else if (choice == 4){  // make a bid
        makeBid();
    }
    else if (choice == 5){  // view personal portfolio
        viewPortfolio();
    }
    else if (choice == 6){  // continue
        simulateNextTimeframe();
    }
    else{
        displayInputError();
    }    
    std::cout << "Current time is: " << currentTime << std::endl;
}
