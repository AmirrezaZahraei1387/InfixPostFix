//
// Created by KAVOSH on 1/22/2024.
//
#ifndef INFIXPOSTFIX_MISSINGOPERAND_HPP
#define INFIXPOSTFIX_MISSINGOPERAND_HPP
#include "../oper/inOutE.hpp"
#include <exception>
#include <ostream>

template<typename NUMBER_t>
class MissingOperatorError: std::exception{
public:
    explicit MissingOperatorError() {
        error_p = "MissingOperatorError: the operands of the operator indicated are missing";
    };

    const char* what() const noexcept override{
        return error_p.c_str();
    }

private:
    std::string error_p;
};

#endif //INFIXPOSTFIX_MISSINGOPERAND_HPP
