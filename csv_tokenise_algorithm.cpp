// for reading data from csv files
#include <string>
#include <vector>
#include <iostream>
#include <fstream>      // for file handling

std::vector<std::string> tokenise(std::string csvLine, char separator){
    std::vector<std::string> tokens;
    std::string token;
    for(int i = 0; i < csvLine.size(); i++){
        if(csvLine[i] != separator){
            token += csvLine[i];
        } 
        else{
            tokens.push_back(token);
            token = "";
        }
    }
    tokens.push_back(token);
    return tokens;
}

int main(){
    std::vector<std::string> tokens;

    // Taken the string directly from csv file. Works as intended
    std::string s= "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";    // Testing the algorithm
    tokens=tokenise(s, ',');
    
    for (int i=0; i<tokens.size(); ++i){
        std::cout << tokens[i] << std::endl;
    }

    std::ifstream csvFile{"order_book.csv"};       // Default is opening file for reading
    
    if (csvFile.is_open()){
        std::cout << "file opened successfully" << std::endl;
        csvFile.close();
    }
    else{
        std::cout << "file not opened" << std::endl;
    }

    return 0;
}


// Another method of tokenising csv files

// std::vector<std::string> tokenise(std::string csvLine, char separator){
//     std::vector<std::string> tokens;
//     signed int start, end;
//     std::string token;
//     start = csvLine.find_first_not_of(separator,0);
//     do{
//         end = csvLine.find_first_of(separator,start);
//         if (start==csvLine.length() || start==end){
//             break;
//         } 
//         if (end>=0){
//             token = csvLine.substr(start,end-start);
//         }
//         else{
//             token = csvLine.substr(start,csvLine.length()-start);
//         }  
//         tokens.push_back(token);
//         start=end+1;
//     }
//     while(end > 0);
//     return tokens;
