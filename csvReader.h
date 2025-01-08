#pragma once

#include "OrderBook.h"
#include <vector>
#include <string>

class csvReader{
    public:
        csvReader();
        std::vector<OrderBook> readCSV(std::string csvFile);
    
    private:
        std::vector<std::string> tokenise(std::string csvLine, char separator);
        OrderBook str2OB(std::vector<std::string> strings);     
        // Converts strings to OrderBook entries. Converts str to double and enum

};