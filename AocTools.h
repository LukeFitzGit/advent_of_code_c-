#ifndef AOCTOOLS_H
#define AOCTOOLS_H

class AocTools{
    public:
        std::vector<std::string> GetStringVectorFromTextFile(std::string filename);
        bool ValueFromSet1InSet2(std::unordered_set<int> set1, std::unordered_set<int> set2);
        bool ValueXBetweenYandZ(int x, int y, int z);
};
#endif