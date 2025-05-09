#include "Functions.h"
#include <iostream> 
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include <thread>
#include "OrderBook.h"
#include "csvReader.h"
#include "OrderBookOperations.h"
#include <limits>
#include "Wallet.h"
#include "User.h"

#include "Colors.h"

Functions::Functions(){
    
}

/** Starts the entire program */
void Functions::init(){
    std::cout << Colors::BLUE << "Welcome to the stock exchange!" << Colors::RESET << std::endl;

    currentTime = OrderBookOperations.getEarliestTimestamp(); // First timestamp in csv file
        
    while(true){       
        printMenu();
        int choice = userChoice();  // Taking user's choice
        processChoice(choice);
    }
}

void Functions::printMenu(){
    std::cout << Colors::BLUE << "\nMENU" << Colors::RESET << std::endl;
    std::cout << "1: Help" << std::endl;
    std::cout << "2: Print exchange statistics" << std::endl;
    std::cout << "3: Make an offer (ask)" << std::endl;
    std::cout << "4: Make a bid" << std::endl;
    std::cout << "5: View wallet" << std::endl;
    std::cout << "6: Next time step" << std::endl;
    std::cout << "7: Login" << std::endl;
    std::cout << "8: Register" << std::endl;
    std::cout << "9: View your offers" << std::endl;
    std::cout << "10: Remove all of your offers" << std::endl;
    std::cout << "11: Logout" << std::endl;
    std::cout << "12: Exit" << std::endl;
}

/** Converts vector of strings of size 3 to size 5 by adding type and timestamp. Accessed by the makeOffer function */
std::vector<std::string> Functions::convertTokensToSize5(std::vector<std::string>& tokens){     // returns 5 strings, including timestamp and order type
    // tokens = timestamp, product, orderType, price, amount
    std::string product = tokens[0];
    std::string price = tokens[1];
    std::string amount = tokens[2];
    tokens[0] = currentTime;
    tokens[1] = product;
    tokens[2] = "ask";  // Convert to OB type using csvReader::str2OB
    tokens.resize(5);
    tokens[3] = price;      // Defined as per OrderBook format
    tokens[4] = amount;
    
    return tokens;
}

int Functions::userChoice(){
    int choice;
    std::string input;
    std::getline(std::cin, input);
    try{
        choice = std::stoi(input);
    }
    catch(const std::exception& e){
        std::cout << "Non integer input" <<std::endl;
        choice = 0;
    }
    return choice;
}

void Functions::printHelp(){
    std::cout << "Help - Your aim is to make profits by analysing the market. Sell high, buy low" << std::endl;
    std::cout << "Continue to trading? (Y/N)" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    if (input == "N" || input == "n"){
        std::cout << "Exiting..." << std::endl;
        exit(0);
    }
    else if (input == "Y" || input == "y"){
        std::cout << "Continuing..." << std::endl;
    }
    else{
        std::cout << "Invalid input. Please enter Y or N" << std::endl;
    }
}

// Printing wrong entry and entry2 sizes. Gives 3540 for both, for all products
void Functions::printStatistics(){ 
    for(std::string const& product : OrderBookOperations.getProducts()){
        std::cout << "\n\nProduct: " << product << std::endl;
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
    std::getline(std::cin, userLine);    

    std::vector<std::string> tokens = csvReader::tokenise(userLine, ',');
    if (tokens.size() != 3){
        std::cout << "Invalid input. Please enter in the format Product, Price, Amount" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return;
    }
    std::cout << "Product: " << tokens[0] << " Price: " << tokens[1] << " Amount: " << tokens[2] << std::endl;
    
    try{
        tokens = convertTokensToSize5(tokens);
    }
    catch(const std::exception& e){
        std::cout << "Input not in correct format" << std::endl;     
    }

    try{
        if (tokens.size()==5){
            std::cout << "Dubugging in Functions::makeOffer. This line should appear" << std::endl;
        }
    }
    catch(const std::exception& e){
        std::cout << "Error: Size of entered input not five " << std::endl;
        throw;
    }
    OrderBook order = csvReader::str2OB(tokens);
    order.username = currentUser;  // Use current user instead of hardcoded "user"

    if (order.product == "ERROR"){
        std::cout << Colors::RED << "An error occurred with your input. Kindly retry" << Colors::RESET << std::endl;
    }
    else{   //Pushing to csv
        OrderBookOperations.insertEntry(order);
        std::cout << Colors::GREEN << "Offer successfully placed" << Colors::RESET << std::endl;
    }
}

void Functions::makeBid(){
    while (true){
        std::string type;
        double amount;
        double price;
        std::cout << "Enter currency to be traded: " << std::endl;
        std::getline(std::cin, type);
        std::cout << "Enter amount: " << std::endl;
        std::cin >> amount;

        Wallet wallet;
        if (wallet.checkWallet(type, amount)){
            // Make bid
            std::string timestamp = currentTime;
            std::cout << "Enter price: " << std::endl;
            std::cin >> price;
            OrderBook order{price, amount, timestamp, type, orderBookType::bid, currentUser};  // Use current user
            // Finally
            OrderBookOperations.insertEntry(order);
            std::cout << Colors::GREEN << "Bid successfully placed" << Colors::RESET << std::endl;
        }
        else{
            std::cout << Colors::RED << "Sufficient funds do not exist in wallet for this currency" << Colors::RESET << std::endl;
        }
        std::cout << "Continue trading? (Y/N)" << std::endl;
        std::string input;
        std::cin >> input;
        if (input == "N" || input == "n"){
            std::cout << "Exiting..." << std::endl;
            exit(0);
        }
        else if (input == "Y" || input == "y"){
            std::cout << "Continuing..." << std::endl;
        }
        else{
            std::cout << "Invalid input. Please enter Y or N" << std::endl;
        }
    }
}

void Functions::viewPortfolio(){
    try{
        wallet.accessWallet();
    }
    catch(std::exception& e){
        std::cout << "Error: Wallet not found\n\n\n" << std::endl;
    }
}

void Functions::simulateNextTimeframe(){
    std::cout << Colors::YELLOW << "Moving on..." << Colors::RESET << std::endl;
    currentTime = OrderBookOperations.getNextTimestamp(currentTime);
}

void Functions::displayInputError(){
    std::cout << Colors::RED << "Invalid input. Please enter a number 1-7" << Colors::RESET << std::endl;
}

void waitForThreeSeconds() {
    std::cout << Colors::YELLOW << "Processing..." << Colors::RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

void Functions::processChoice(int choice){
    if ((choice == MENU_OFFER || choice == MENU_BID || 
         choice == MENU_PORTFOLIO || choice == MENU_VIEW_OFFERS || 
         choice == MENU_REMOVE_OFFERS) && currentUser.empty()) {
        std::cout << Colors::RED << "Please login first to access this feature." << Colors::RESET << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return;
    }

    if (choice == MENU_HELP){
        printHelp();
    }
    else if (choice == MENU_STATS){
        printStatistics();
        waitForThreeSeconds();
    }
    else if (choice == MENU_OFFER){
        makeOffer();
    }
    else if (choice == MENU_BID){
        makeBid();
    }
    else if (choice == MENU_PORTFOLIO){
        viewPortfolio();
        waitForThreeSeconds();
    }
    else if (choice == MENU_NEXT){
        simulateNextTimeframe();
    }
    else if (choice == MENU_LOGIN){
        login();
    }
    else if (choice == MENU_REGISTER){
        registerUser();
    }
    else if (choice == MENU_VIEW_OFFERS){
        viewOffers();
        waitForThreeSeconds();
    }
    else if (choice == MENU_REMOVE_OFFERS){
        bool success = OrderBookOperations.removeOffers(currentUser);
        if (success) {
            std::cout << Colors::GREEN << "All your offers have been removed." << Colors::RESET << std::endl;
        } else {
            std::cout << Colors::YELLOW << "No offers found to remove." << Colors::RESET << std::endl;
        }
    }
    else if (choice == MENU_LOGOUT){
        logout();
        waitForThreeSeconds();
    }
    else if (choice == MENU_EXIT){
        std::cout << "Exiting..." << std::endl;
        exit(0);
    }
    else{
        displayInputError();
    }    

    if (!currentUser.empty()) {
        std::cout << Colors::BLUE << "Logged in as: " << currentUser << Colors::RESET << std::endl;
    }
    std::cout << "Current time is: " << currentTime << std::endl;
}

void Functions::login() {
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
    std::cin.ignore(); // Clear the newline from the input buffer

    auto userIt = users.find(username);
    if (userIt != users.end() && userIt->second.checkPassword(password)) {
        currentUser = username;
        std::cout << Colors::GREEN << "Login successful! Welcome, " << username << Colors::RESET << std::endl;
    } else {
        std::cout << Colors::RED << "Invalid username or password." << Colors::RESET << std::endl;
    }
}

void Functions::registerUser() {
    std::string username, password, confirmPassword;
    std::cout << "Enter a new username: ";
    std::cin >> username;
    
    if (users.find(username) != users.end()) {
        std::cout << Colors::RED << "Username already exists. Please choose a different username." << Colors::RESET << std::endl;
        std::cin.ignore();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return;
    }

    do {
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Confirm password: ";
        std::cin >> confirmPassword;
        
        if (password != confirmPassword) {
            std::cout << Colors::RED << "Passwords do not match. Please try again." << Colors::RESET << std::endl;
        }
    } while (password != confirmPassword);

    users[username] = User(username, password);
    currentUser = username;
    std::cout << Colors::GREEN << "Registration successful! Welcome, " << username << Colors::RESET << std::endl;
    std::cin.ignore(); // Clear the newline from the input buffer
}

void Functions::viewOffers() {
    if (currentUser.empty()) {
        std::cout << Colors::RED << "You must be logged in to view your offers." << Colors::RESET << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return;
    }

    bool hasOffers = false;
    std::cout << Colors::GREEN << "\nOffers for user: " << currentUser << Colors::RESET << std::endl;
    
    // Show asks
    std::cout << Colors::YELLOW << "\nASK ORDERS:" << Colors::RESET << std::endl;
    for (const auto& order : OrderBookOperations.getAllOrders()) {
        if (order.username == currentUser && order.orderType == orderBookType::ask) {
            std::cout << "Type: ASK, Product: " << order.product 
                     << ", Price: " << order.price 
                     << ", Amount: " << order.amount 
                     << ", Timestamp: " << order.timestamp << std::endl;
            hasOffers = true;
        }
    }

    // Show bids
    std::cout << Colors::YELLOW << "\nBID ORDERS:" << Colors::RESET << std::endl;
    for (const auto& order : OrderBookOperations.getAllOrders()) {
        if (order.username == currentUser && order.orderType == orderBookType::bid) {
            std::cout << "Type: BID, Product: " << order.product 
                     << ", Price: " << order.price 
                     << ", Amount: " << order.amount 
                     << ", Timestamp: " << order.timestamp << std::endl;
            hasOffers = true;
        }
    }

    if (!hasOffers) {
        std::cout << Colors::YELLOW << "No offers found." << Colors::RESET << std::endl;
    }
}

void Functions::logout() {
    if (currentUser.empty()) {
        std::cout << Colors::YELLOW << "No user is currently logged in." << Colors::RESET << std::endl;
    } else {
        std::cout << Colors::GREEN << "Goodbye, " << currentUser << "!" << Colors::RESET << std::endl;
        currentUser = "";
    }
}
