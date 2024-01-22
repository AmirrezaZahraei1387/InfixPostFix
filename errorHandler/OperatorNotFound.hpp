//
// Created by KAVOSH on 1/22/2024.
//
#ifndef INFIXPOSTFIX_OPERATORNOTFOUND_HPP
#define INFIXPOSTFIX_OPERATORNOTFOUND_HPP
#include <string>
#include <exception>

class OperatorNotFoundError:public std::exception{
public:
    explicit OperatorNotFoundError(char ops){
        error_p = "OperatorNotFoundError: operator ";
        error_p.push_back(ops);
        error_p += " is not recognized.";
    }

    const char* what() const noexcept override{

        return error_p.c_str();
    }

private:
    std::string error_p;
};

#endif //INFIXPOSTFIX_OPERATORNOTFOUND_HPP
