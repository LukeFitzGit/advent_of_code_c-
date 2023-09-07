#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<unordered_set>
#include "AocTools.h"

std::vector<std::string> AocTools::GetStringVectorFromTextFile(std::string filename){
        std::ifstream file ; file.open(filename);
        std::string line;
        std::vector<std::string> fileVec;
        if (file.is_open()) {
            while (!file.eof()){
                getline(file, line);
                fileVec.push_back(line);
            }
        file.close();
        }
        return fileVec;
}

bool AocTools::ValueFromSet1InSet2(std::unordered_set<int> set1, std::unordered_set<int> set2){
    for (int i : set1) {
        if (set2.count(i)) {
            return true;
        }
        return false;
    }
}

bool AocTools::ValueXBetweenYandZ(int x, int y, int z){
    if (x <= y && x >= z) return true;
    return false;
}

