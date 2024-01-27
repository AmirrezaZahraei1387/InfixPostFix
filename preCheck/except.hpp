//
// Created by KAVOSH on 1/26/2024.
//
#ifndef INFIXPOSTFIX_EXCEPT_HPP
#define INFIXPOSTFIX_EXCEPT_HPP
#include <exception>
#include <string>

class OperatorNotFoundError: std::exception{
public:
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return msg.c_str();
    }
private:
    const std::string msg{"the expression contain unknown characters."};
};

class MissingOperandError: std::exception{
public:
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return msg.c_str();
    }
private:
    const std::string msg{"The expression is missing one or more operands."};
};

class IllegalOperatorError: std::exception{
public:
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return msg.c_str();
    }
private:
    const std::string msg{"An illegal operator is used. Most likely parenthesis with in or post fix expression."};
};

class OrganizerError: std::exception{
public:
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return msg.c_str();
    }
private:
    const std::string msg{"The organizers are not in correct order."};
};

#endif //INFIXPOSTFIX_EXCEPT_HPP
