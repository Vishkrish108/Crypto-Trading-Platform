#include <iostream>

int main(){
    std::cout << "Welcome to the stock exchange!" << std::endl;
    while(true){
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

        int choice;
        std::cin >> choice;
        std::cout << "You chose: " << choice << std::endl;
        
        if (choice == 1){
            std::cout << "Help - Your aim is to make profits by analysing the market. Sell high, buy low" << std::endl;
        }
        else if (choice == 2){
            std::cout << "TO DO" << std::endl;
        }
        else if (choice == 3){
            std::cout << "TO DO" << std::endl;
        }
        else if (choice == 4){
            std::cout << "TO DO" << std::endl;
        }
        else if (choice == 5){
            std::cout << "TO DO" << std::endl;
        }
        else if (choice == 6){
            std::cout << "Moving on..." << std::endl;
        }
        else{
            std::cout << "Bad input. Please type a number 1-6" << std::endl;
            continue;
        }
        
    }
    return 0;

}
