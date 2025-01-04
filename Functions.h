#pragma once       // Uses the file only once even if called multiple times
#include <vector>
#include "OrderBook.h"

class Functions{
    public:
        Functions();
        void init();    // To start the program
    private:    // Exposing only init() to be called from main. Good practice
        void printMenu();
        void printHelp();
        void printStatistics();
        void makeOffer();
        void makeBid();
        void viewPortfolio();
        void simulateNextTimeframe();
        void displayInputError();
        void processChoice(int choice);
        int userChoice();
        void loadOrderBook();
        std::vector<OrderBook> orders;
};