#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <cctype>
#include <vector>

bool ValueIsDigit(std::string value){
    for (char c: value){
        if (!std::isdigit(c)){
            return false;
        }
    } 
    return true;
}

std::vector<int> GetListTotals(std::vector<std::string> vec){
    std::vector<int> totalsVec;
    int sampleTotal = 0;
    for (std::string value : vec){
        if (ValueIsDigit(value) && value != ""){
            sampleTotal += stoi(value);
        }
        else {
            totalsVec.push_back(sampleTotal);
            sampleTotal = 0;
        }
    }
    totalsVec.push_back(sampleTotal);
    std::sort(totalsVec.begin(), totalsVec.end());
    return totalsVec;
}

int main() {
    std::ifstream calories ; calories.open("cal.txt");
    std::string line;
    std::vector<std::string> calVec;

    if (calories.is_open()) {
        while (!calories.eof()){
            getline(calories, line);
            calVec.push_back(line);
        }
        calories.close();
    }

    std::vector<int> totalsVector = GetListTotals(calVec);
    std::cout << totalsVector[totalsVector.size()-1] << std::endl;
    int top3 = totalsVector[totalsVector.size()-1] + totalsVector[totalsVector.size()-2] + totalsVector[totalsVector.size()-3];
    std::cout << top3;
    return 0;
}