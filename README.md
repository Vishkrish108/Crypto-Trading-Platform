# Crypto-Trading-Platform

## Running the code
To run the code, clone the repo and use 
- g++ main.cpp OrderBook.cpp Functions.cpp csvReader.cpp OrderBookOperations.cpp Wallet.cpp User.cpp
- ./a   (./a.out for some systems)


## Order book contains the following
- Timestamp, c1/c2 ('Buy c1 for c2'), Task (Bid or Ask), Amount (c1), Price (c2)
- "I want to buy amount (c1) for price*c2" and  
- "I have amount(c1). I will sell it for price*c2 each"

## Functionalities of each file:
- main : Calls the other functions to initialise the program.
- OrderBook : Deals with setting up the values of price, amount etc.
- OrderBookOperations : Sets up a split into asks and bids and the currencies within them for matching trades.
- Functions : Contains most of the basic functions. These are mostly visual for the user and to call the back-end functions. 
- csvReader : Reads the csv file, parses and tokenises it, and converts to an orderbook entry, correctly storing data in terms of doubles, enums, and strings. 
- csv_tokenise_algorithm : Contains early versions of code which has been used within csvReader.cpp for parsing.
- Wallet : Contains every function that deals with the handling of currencies, including but not restricted to insertion, removal, updation, and viewing details.
- User : Manages user authentication, registration, and trading history.
- Colors : Defines ANSI color codes for enhanced terminal output.

## Features
- User Authentication: Secure login and registration system
- Order Management: Place and track both bid and ask orders
- Portfolio View: Check your wallet and order history
- User-specific Orders: View and manage your own orders
- Color-coded Interface: Enhanced visual feedback for better user experience
- Processing Delays: Added wait times for better user experience in key operations

## Menu Options
1. Help
2. Print exchange statistics
3. Make an offer (ask)
4. Make a bid
5. View wallet
6. Next time step
7. Login
8. Register
9. View your offers
10. Remove all of your offers
11. Logout
12. Exit

# To Dos
- Function for removal of specific orders
- Implement the matching function properly
- Check if required funds available in wallet before placing orders (asks only. bids check done)
- Add database for persistent data retention
