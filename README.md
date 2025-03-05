# Crypto-Trading-Platform
Learning C++ through a project

# Running the code
To run the code, clone the repo and use 
- g++ main.cpp OrderBook.cpp Functions.cpp csvReader.cpp OrderBookOperations.cpp Wallet.cpp
- ./a   (./a.out for some systems)


## Order book contains the following
- Timestamp, c1/c2 ('Buy c1 for c2'), Task (Bid or Ask), Amount (c1), Price (c1)

## Functionalities of each file:
- main : Calls the other functions to initialise the program.
- OrderBook : Deals woth setting up the values of price, amount etc.
- OrderBookOperations : Sets up a split into asks and bids and the currencies within them for matching trades.
- Functions : Contains most of the basic functions. These are mostly visual for the user and to call the back-end functions. 
- csvReader : Reads the csv file, parses and tokenises it, and converts to an orderbook entry, correctly storing data in terms of doubles, enums, and strings. 
- csv_tokenise_algorithm : Contains early versions of code which has been used within csvReader.cpp for parsing.
- Wallet : Contains every function that deals with the handling of currencies, including but not restricted to insertion, removal, updation, and viewing details.  

# TO DO (for my reference)
- Add a 'removeOffers' function
- Add coloring to the terminal commands 
