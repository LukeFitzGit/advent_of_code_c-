#include <iostream>
#include<string>
#include<vector>
#include<fstream>

char GetCommonCharacter(std::string firstHalf, std::string secHalf){
     for (char c : firstHalf){
        for (char c2 : secHalf){
            if (c == c2){
                return c;
            }
        }
     }
}

int main(){
    std::ifstream lines ; lines.open("stringData.txt");
    std::string line;
    std::vector<std::string> linesVec;
    if (lines.is_open()) {
        while (!lines.eof()){
            getline(lines, line);
            linesVec.push_back(line);
        }
        lines.close();
    }

    std::string firstHalf;
    std::string secHalf;
    char value;
    int total = 0;
    for (std::string line : linesVec){
        firstHalf = line.substr(0, line.size()/2);
        secHalf = line.substr(line.size()/2, line.size()-1);
        value = GetCommonCharacter(firstHalf, secHalf);
        if (isupper(value)){
            total += value - 38;
        }
        else{
            total += value - 96;
        }
    }
    std::cout << total << std::endl;

    return 0;
}