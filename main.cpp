#include <iostream>

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


int main(){
    std::cout << "Welcome to the stock exchange!" << std::endl;
    while(true){
        printMenu();
        int choice = userChoice();      // Taking user's choice
        processChoice(choice);        
    }
    return 0;
}


void printMenu(){
    std::cout << "======================" << std::endl;
    
    // 1. Help
    std::cout << "1: Print help" << std::endl;
        
    // 2. Print the stats/orders
    std::cout << "2: Print exchange stats" << std::endl;
    
    // 3. Make an offer
    std::cout << "3. Make an offer " << std::endl;
    
    // 4. Make a bid
    std::cout << "4. Make a bid " << std::endl;
    
    // 5. View personal portfolio
    std::cout << "5: Print wallet" << std::endl;
    
    // 6. Continue
    std::cout << "6: Continue" << std::endl;
    
    std::cout << "======================" << std::endl;
    std::cout << "Enter a number 1-6: " << std::endl;
}

int userChoice(){
    int choice;
    std::cin >> choice;
    std::cout << "You chose: " << choice << std::endl;
    return choice;
}

void printHelp(){
    std::cout << "Help - Your aim is to make profits by analysing the market. Sell high, buy low" << std::endl;
}

void printStatistics(){
    std::cout << "TO DO" << std::endl;
}

void makeOffer(){
    std::cout << "TO DO" << std::endl;
}

void makeBid(){
    std::cout << "TO DO" << std::endl;
}

void viewPortfolio(){
    std::cout << "TO DO" << std::endl;
}

void simulateNextTimeframe(){
    std::cout << "Moving on..." << std::endl;
}

void displayInputError(){
    std::cout << "Invalid input. Please enter a number 1-6" << std::endl;
}

void processChoice(int choice){
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
