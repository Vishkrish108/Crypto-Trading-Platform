class Functions{
    public:
        Functions();
        void init();    // To start the program
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
};