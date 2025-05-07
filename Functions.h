#pragma once       // Uses the file only once even if called multiple times
#include <vector>
#include <map>
#include "OrderBook.h"
#include "csvReader.h"
#include "OrderBookOperations.h"
#include "Wallet.h"
#include "User.h"
#include "Colors.h"

class Functions{
    public:
        Functions();
        void init();    // To start the program
    private:    // Exposing only init() to be called from main. Good practice
        static const int MENU_HELP = 1;
        static const int MENU_STATS = 2;
        static const int MENU_OFFER = 3;
        static const int MENU_BID = 4;
        static const int MENU_PORTFOLIO = 5;
        static const int MENU_NEXT = 6;
        static const int MENU_LOGIN = 7;
        static const int MENU_REGISTER = 8;
        static const int MENU_VIEW_OFFERS = 9;
        static const int MENU_REMOVE_OFFERS = 10;
        static const int MENU_LOGOUT = 11;
        static const int MENU_EXIT = 12;

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
        std::vector<std::string> convertTokensToSize5(std::vector<std::string>& tokens);

        void login();
        void registerUser();
        void viewOffers();
        void logout();

        std::string currentUser;  // Stores the username of the logged-in user
        std::map<std::string, User> users;  // Stores user data

        std::string currentTime;  // Represents the current time in the simulation
        OrderBookOperations OrderBookOperations{"order_book.csv"};

        Wallet wallet;
};