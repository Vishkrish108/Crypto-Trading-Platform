#include "Functions.h"
#include <iostream> 
#include <vector>
#include <string>
#include "OrderBook.h"
#include "csvReader.h"

Functions::Functions(){
    
}

/** Starts the entire program */
void Functions::init(){
    std::cout << "Welcome to the stock exchange!" << std::endl;
//    loadOrderBook();
    while(true){       
        printMenu();
        int choice = userChoice();  // Taking user's choice
        processChoice(choice);
    }
}

// Function can be removed. OrderBookOperations object is created in Functions.h

// void Functions::loadOrderBook(){
//     // orders defined in Functions.h
//     orders = csvReader::readCSV("order_book.csv");
// }


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
    std::cout << "[6] Continue" << std::endl;
    
    std::cout << "======================" << std::endl;
    std::cout << "Enter a number 1-6: " << std::endl;
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

void Functions::printStatistics(){ // tempoarary comment till i figure out how to access the orders
//    std::cout << "Market contains: " << orders.size() << " entries" << std::endl;
}

void Functions::makeOffer(){
    std::cout << "TO DO" << std::endl;
}

void Functions::makeBid(){
    std::cout << "TO DO" << std::endl;
}

void Functions::viewPortfolio(){
    std::cout << "TO DO" << std::endl;
}

void Functions::simulateNextTimeframe(){
    std::cout << "Moving on..." << std::endl;
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
}
