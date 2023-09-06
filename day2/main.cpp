#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Shape {
    public:
        Shape(char _character, char _winsAgainst, int _winPoints, char _losesAgainst){
            character = _character;
            winsAgainst = _winsAgainst;
            winPoints = _winPoints;
            losesAgainst = _losesAgainst;
        }

        char character;
        char winsAgainst;
        int winPoints;
        char losesAgainst;
};

Shape GetShape(char character){
    switch (character){
        case 'X': return Shape('A', 'Z', 1, 'Y'); //rock
        case 'Y': return Shape('B', 'X', 2, 'Z'); //paper
        case 'Z': return Shape('C', 'Y', 3, 'X'); //scissors
        case 'A': return Shape('X', 'C', 1, 'B'); //rock
        case 'B': return Shape('Y', 'A', 2, 'C'); //paper
        case 'C': return Shape('Z', 'B', 3, 'A'); //scissors
        default: std::cout << "shape not found\n";
    }
}

int main(){
    std::ifstream gestures ; gestures.open("stratValues.txt");
    std::string line;
    std::vector<std::string> gestureVec;
    if (gestures.is_open()) {
        while (!gestures.eof()){
            getline(gestures, line);
            gestureVec.push_back(line);
        }
        gestures.close();
    }

    int points = 0;
    for (std::string i : gestureVec){ 
        Shape opponents = GetShape(i[0]);
        Shape my = GetShape(i[2]);
        if (my.character == opponents.losesAgainst){
            points += my.winPoints + 6;
        }
        else if (my.character == opponents.winsAgainst){
            points += my.winPoints;
        }
        else {
            points += my.winPoints +3;
        }
    }
    std::cout << "points: " << points << std::endl;

    int pointsTwo = 0;
    for (std::string i : gestureVec){ 
        Shape opponent = GetShape(i[0]);
        if(i[2] == 'X'){
            Shape myChoice = GetShape(opponent.winsAgainst);
            pointsTwo += myChoice.winPoints;
        }
        else if(i[2] == 'Z'){
            Shape myChoice = GetShape(opponent.losesAgainst);
            pointsTwo += myChoice.winPoints + 6;
        }
        else {
            pointsTwo += opponent.winPoints +3;
        }
    }
    std::cout << "points two " << pointsTwo;

    return 0;
} 