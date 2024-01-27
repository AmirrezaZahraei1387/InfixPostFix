//
// Created by KAVOSH on 1/20/2024.
//
#ifndef INFIXPOSTFIX_INOUTE_HPP
#define INFIXPOSTFIX_INOUTE_HPP

#include "loader/loader.hpp"
#include "../preCheck/except.hpp"
#include <istream>
#include <ostream>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>


static const std::array<char, 11> NUMBERS{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

template<typename NUMBER_t>
struct InputOrd{
    char tag{};
    NUMBER_t number{};
};

struct NegPosFlags{
    bool with_neg;
    bool with_pos;
};

template<typename NUMBER_t>
using InputOrdFlow = std::vector<InputOrd<NUMBER_t>>;


// this function gets the string and the input ordr flow to 
// to resolve the number in the string and pusg it into the flow
/*
it is currently overloaded to work for the types
int
float
long long
double 
long double
*/

template<typename NUMBER_t>
void resolveNumber(InputOrdFlow<NUMBER_t>& inputOrdFlow, std::string& strSeq);


template<typename NUMBER_t>
bool handleOperators(NegPosFlags& np,
                     InputOrdFlow<NUMBER_t>& inputOrdFlow,
                     std::string& resolve_number,
                     char x){
    for(auto par: OPD::opRules.operators){
        if(x == par.first){
            resolveNumber(inputOrdFlow, resolve_number);
            inputOrdFlow.push_back(InputOrd<NUMBER_t>{.tag = x});
            np.with_neg = false;
            np.with_pos = false;

            if(x == OPD::opRules.numPos){
                np.with_pos = true;
                return true;
            }else if(x == OPD::opRules.numNeg){
                np.with_neg = true;
                return true;
            }else{
                return true;
            }
        }
    }
    return false;
}

template<typename NUMBER_t>
bool handleOrganizer(NegPosFlags& np,
                     InputOrdFlow<NUMBER_t>& inputOrdFlow,
                     std::string& resolve_number,
                     char x){

    for(auto par: OPD::opRules.organizers){
        if(x == par.opening){

            resolveNumber(inputOrdFlow, resolve_number);
            inputOrdFlow.push_back(InputOrd<NUMBER_t>{.tag = OPD::opRules.default_neg_num_org.opening});
            np.with_neg = false;
            np.with_pos = false;
            return true;

        }else if(x == par.closing){

            resolveNumber(inputOrdFlow, resolve_number);
            inputOrdFlow.push_back(InputOrd<NUMBER_t>{.tag = OPD::opRules.default_neg_num_org.closing});
            np.with_neg = false;
            np.with_pos = false;
            return true;

        }
    }
    return false;
}

template<typename NUMBER_t>
bool handleSNPN(NegPosFlags& np,
                InputOrdFlow<NUMBER_t>& inputOrdFlow,
                std::string& resolve_number,
                char x){
    if(x == ' '){
        resolveNumber(inputOrdFlow, resolve_number);
        np.with_neg = false;
        np.with_pos = false;
        return true;

    }else if(std::find(NUMBERS.begin(), NUMBERS.end(), x) != NUMBERS.end()){
            if(np.with_neg){
                np.with_neg = false;
                resolve_number.push_back('-');
                inputOrdFlow.pop_back();
            }else if(np.with_pos){
                np.with_pos = false;
                inputOrdFlow.pop_back();
            }
        resolve_number.push_back(x);
        return true;
    }
    return false;
}


// get user input will extract the user input into a InputorderFlow object making
// it easier for the program to load and print it different exp formats.
template<typename NUMBER_t>
void getUserInput(InputOrdFlow<NUMBER_t>& inputOrdFlow, std::istream& inputStream) {

    std::string resolve_number;
    NegPosFlags np{};
    std::string inputSeq;
    std::getline(inputStream, inputSeq);

    for(auto x: inputSeq){
        if(!handleOperators(np, inputOrdFlow, resolve_number, x)){
            if(!handleOrganizer(np, inputOrdFlow, resolve_number, x)){
                if(!handleSNPN(np, inputOrdFlow, resolve_number, x)){
                    throw OperatorNotFoundError();
                }
            }
        }
    }
    resolveNumber(inputOrdFlow, resolve_number);
}

// this function is designed for printing 
// the Input order p with paranthesis for the 
// neg numbrs
// mainly used for infix printing printing
template<typename NUMBER_t>
void printW(InputOrd<NUMBER_t>& p, std::ostream& outStream, bool resolveNegNum){
    if(p.tag == OPD::opRules.number_ind){
        outStream <<OPD::opRules.default_neg_num_org.opening<<OPD::opRules.sep
                    <<p.number<<OPD::opRules.sep<<OPD::opRules.default_neg_num_org.closing<<OPD::opRules.sep;
    }else{
        for(auto par: OPD::opRules.operators){
            if(p.tag == par.first){
                outStream<<par.first<<OPD::opRules.sep;
            }
        }
    }
}

// this function is designed for printing 
// the Input order p without any paranthesis
// mainly used for prefix and postfix printing
template<typename NUMBER_t>
void printW(InputOrd<NUMBER_t>& p, std::ostream& outStream){
    if(p.tag == OPD::opRules.number_ind){
        outStream <<p.number<<OPD::opRules.sep;
    }else{
        for(auto par: OPD::opRules.operators){
            if(p.tag == par.first){
                outStream<<par.first<<OPD::opRules.sep;
            }
        }
    }
}


bool isParOpen(char tag);
bool isParClose(char tag);
bool isNumber(char tag);
bool isOperator(char tag);
// checks to see if the operator 1 is an operator and have higher
// precedence over the second one or not.
bool isHigherPriorityInfixLoad(char tag_1, char tag_2);
#endif //INFIXPOSTFIX_INOUTE_HPP
