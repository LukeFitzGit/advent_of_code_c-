#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<unordered_set>

char GetCommonCharacter(std::string& firstPart, std::string& secPart, std::string thirdPart = ""){
    std::unordered_set<char> firstString(firstPart.begin(), firstPart.end());
    std::unordered_set<char> secondString(secPart.begin(), secPart.end());
    if (thirdPart != ""){
        std::unordered_set<char> thirdString(thirdPart.begin(), thirdPart.end());
        for (char c : firstString) {
            if (secondString.count(c) && thirdString.count(c)) {
                return c;
            }
        }
    }
    else{
        for (char c : firstString) {
            if (secondString.count(c)) {
                return c;
            }
        }
    }
}

int GetNumberFromCharacter(char character, int charOffsetForUpper, int charOffsetForLower){
        if (isupper(character)){
            return character + charOffsetForUpper;
        }
        else{
            return character + charOffsetForLower;
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

    std::string* firstHalf = new std::string;
    std::string* secHalf = new std::string;
    char value;
    int total = 0;
    for (std::string line : linesVec){
        *firstHalf = line.substr(0, line.size()/2);
        *secHalf = line.substr(line.size()/2, line.size()-1);
        value = GetCommonCharacter(*firstHalf, *secHalf);
        total += GetNumberFromCharacter(value, -38, -96);
    }
    delete firstHalf;
    delete secHalf;
    std::cout << total << std::endl;

    total = 0;
    for (int i = 0; i < linesVec.size(); i+=3){
        value = GetCommonCharacter(linesVec[i], linesVec[i+1], linesVec[i+2]);
        total += GetNumberFromCharacter(value, -38, -96);
    }
    std::cout << total << std::endl;
    
    return 0;
}