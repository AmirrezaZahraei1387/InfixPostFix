//
// Created by KAVOSH on 1/20/2024.
//
#ifndef INFIXPOSTFIX_INOUTE_HPP
#define INFIXPOSTFIX_INOUTE_HPP
#include <istream>
#include <ostream>
#include <vector>
#include <array>
#include <algorithm>


enum TAG{NUMBER, ADD, SUB, MUL, DEV, PAR_OPEN, PAR_CLOSE};
static const std::array<char, 10> NUMBERS{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

template<typename NUMBER_t>
struct InputOrd{
    TAG tag{};
    NUMBER_t number{};
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


// get user input will extract the user input into a InputorderFlow object making
// it easier for the program to load and print it different exp formats.
template<typename NUMBER_t>
int getUserInput(InputOrdFlow<NUMBER_t>& inputOrdFlow, std::istream& inputStream){


    std::string resolve_number;
    bool with_neg;
    std::string inputSeq;

    std::getline(inputStream, inputSeq);

    for(auto x: inputSeq){

        switch (x) {
            case '+':
                resolveNumber(inputOrdFlow, resolve_number);
                inputOrdFlow.push_back(InputOrd<NUMBER_t>{ADD});
                with_neg = false;
                break;

            case '*':
                resolveNumber(inputOrdFlow, resolve_number);
                inputOrdFlow.push_back(InputOrd<NUMBER_t>{MUL});
                with_neg = false;
                break;

            case '/':
                resolveNumber(inputOrdFlow, resolve_number);
                inputOrdFlow.push_back(InputOrd<NUMBER_t>{DEV});
                with_neg = false;
                break;

            case '(':
                resolveNumber(inputOrdFlow, resolve_number);
                inputOrdFlow.push_back(InputOrd<NUMBER_t>{PAR_OPEN});
                with_neg = false;
                break;

            case ')':
                resolveNumber(inputOrdFlow, resolve_number);
                inputOrdFlow.push_back(InputOrd<NUMBER_t>{PAR_CLOSE});
                with_neg = false;
                break;

            case '-':
                resolveNumber(inputOrdFlow, resolve_number);
                inputOrdFlow.push_back(InputOrd<NUMBER_t>{SUB});
                with_neg = true;
                break;

            case ' ':
                resolveNumber(inputOrdFlow, resolve_number);
                with_neg = false;
                break;

            default:
                if(std::find(NUMBERS.begin(), NUMBERS.end(), x) != NUMBERS.end()){
                    if(with_neg){
                        with_neg = false;
                        resolve_number.push_back('-');
                        inputOrdFlow.pop_back();
                    }
                    resolve_number.push_back(x);
                }else{
                    return -1;
                }
        }
    }
    resolveNumber(inputOrdFlow, resolve_number);
    return 0;
}


// this function is designed for printing 
// the Input order p with paranthesis for the 
// neg numbrs
// mainly used for infix printing printing
template<typename NUMBER_t>
void printW(InputOrd<NUMBER_t>& p, std::ostream& outStream, bool resolveNegNum){

    switch (p.tag) {
        case ADD:
            outStream<<"+ ";
            break;
        case SUB:
            outStream<<"- ";
            break;
        case MUL:
            outStream<<"* ";
            break;
        case DEV:
            outStream<<"/ ";
            break;
        case  NUMBER:
            if(p.number < 0){
                outStream<<"("<<p.number<<") ";
            }else {
                outStream << p.number << ' ';
            }
            break;
    }
}

// this function is designed for printing 
// the Input order p without any paranthesis
// mainly used for prefix and postfix printing
template<typename NUMBER_t>
void printW(InputOrd<NUMBER_t>& p, std::ostream& outStream){

    switch (p.tag) {
        case ADD:
            outStream<<"+ ";
            break;
        case SUB:
            outStream<<"- ";
            break;
        case MUL:
            outStream<<"* ";
            break;
        case DEV:
            outStream<<"/ ";
            break;
        case  NUMBER:
            outStream << p.number << ' ';
            break;
    }
}

template<typename NUMBER_t>
NUMBER_t calculateValueW(TAG tag, NUMBER_t left, NUMBER_t right){
    switch (tag) {
        case ADD:
            return left + right;

        case SUB:
            return left - right;

        case MUL:
            return left * right;

        case DEV:
            return left / right;
    }
}

bool isOperator(TAG tag);

// checks to see if the operator 1 is an operator and have higher
// precedence over the second one or not.
bool isHigherPriority(TAG tag_1, TAG tag_2);

#endif //INFIXPOSTFIX_INOUTE_HPP
