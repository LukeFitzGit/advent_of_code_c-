#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<unordered_set>

#include "../AocTools.h"

AocTools aocTools;

int main(){
    std::vector<std::string> data = aocTools.GetStringVectorFromTextFile("sectiondata.txt");
    int total = 0;
    std::string firstHalf;
    std::string secHalf;
    std::vector<int> intsVector;
    for (std::string line : data){
        firstHalf = line.substr(0, line.find(','));
        secHalf = line.substr(line.find(',')+1, line.size());
        intsVector = {
            stoi(firstHalf.substr(0,'-')), stoi(firstHalf.substr(firstHalf.find('-')+1, firstHalf.size())),
            stoi(secHalf.substr(0,'-')), stoi(secHalf.substr(secHalf.find('-')+1, secHalf.size()))
        };
        if (intsVector.at(0) >= intsVector.at(2) && intsVector.at(1) <= intsVector.at(3)){
            total += 1;
        }
        else if (intsVector.at(0) <= intsVector.at(2) && intsVector.at(1) >= intsVector.at(3)){
            total += 1;
        }
    }
    std::cout << "total " << total << std::endl;
    total = 0;

    for (std::string line: data){
        firstHalf = line.substr(0, line.find(','));
        secHalf = line.substr(line.find(',')+1, line.size());
        intsVector = {
            stoi(firstHalf.substr(0,'-')), stoi(firstHalf.substr(firstHalf.find('-')+1, firstHalf.size())),
            stoi(secHalf.substr(0,'-')), stoi(secHalf.substr(secHalf.find('-')+1, secHalf.size()))
        };
        if(aocTools.ValueXBetweenYandZ(intsVector.at(2), intsVector.at(1), intsVector.at(0))) {total += 1;}
        else if(aocTools.ValueXBetweenYandZ(intsVector.at(3), intsVector.at(1), intsVector.at(0))) {total += 1;}
        else if(aocTools.ValueXBetweenYandZ(intsVector.at(0), intsVector.at(3), intsVector.at(2))) {total += 1;}
        else if(aocTools.ValueXBetweenYandZ(intsVector.at(1), intsVector.at(2), intsVector.at(2))) {total += 1;}
    }
    std::cout << "total " << total << std::endl;

    return 0;
}