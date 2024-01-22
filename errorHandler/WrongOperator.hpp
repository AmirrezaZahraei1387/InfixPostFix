//
// Created by KAVOSH on 1/22/2024.
//
#ifndef INFIXPOSTFIX_WRONGOPERATOR_HPP
#define INFIXPOSTFIX_WRONGOPERATOR_HPP
#include "../oper/inOutE.hpp"
#include <exception>
#include <string>


template<typename NUMBER_t>
class WrongOperatorError: std::exception{
public:
    explicit WrongOperatorError()
    {
        error_p = "WrongOperatorError: the operator is used in a wrong way.";
    }

    const char* what() const noexcept override{
        return error_p.c_str();
    }

private:
    std::string error_p;
};
#endif //INFIXPOSTFIX_WRONGOPERATOR_HPP
