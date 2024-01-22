//
// Created by KAVOSH on 1/22/2024.
//

#ifndef INFIXPOSTFIX_OP_HPP
#define INFIXPOSTFIX_OP_HPP
#include "inOutE.hpp"
#include "../errorHandler/WrongOperator.hpp"
#include "../expTree/expTree.hpp"

template<typename NUMBER_t>
bool isOperator(TAG tag, typename ExpTree<NUMBER_t>::NodeStack& stack){
    switch(tag){
        case ADD:
        case MUL:
        case DEV:
        case SUB:
            return true;
        case PAR_CLOSE:
            ExpTree<NUMBER_t>::deallocateStack(stack);
            throw WrongOperatorError<NUMBER_t>{};

        case PAR_OPEN:
            ExpTree<NUMBER_t>::deallocateStack(stack);
            throw WrongOperatorError<NUMBER_t>{};
        default:
            return false;
    }
}

#endif //INFIXPOSTFIX_OP_HPP
