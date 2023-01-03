#ifndef TWO_SAT
#define TWO_SAT
#include <string>
#include <regex>
#include <exception>
#include "Digraph.cpp"
#include "KosarajuSharirSCC.h"
#include <iostream>
#include <vector>

using SET = std::vector<char>;

class TwoSAT
{
private:
    std::vector<std::string> split(std::string &, const std::string &);
    std::vector<std::pair<char, bool>> assignment;
    bool satisfiable;
    // use set data structure implemented yourself
    SET set;

public:
    TwoSAT(const std::string &);
    bool isSatisfiable();
    std::vector<std::pair<char, bool>> getAssignment();
    ~TwoSAT();
};

#endif
