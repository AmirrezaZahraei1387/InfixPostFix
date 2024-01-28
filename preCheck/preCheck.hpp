//
// Created by KAVOSH on 1/27/2024.
//
#ifndef INFIXPOSTFIX_PRECHECK_HPP
#define INFIXPOSTFIX_PRECHECK_HPP
#include "except.hpp"
#include "../expTree/expTree.hpp"

template<typename NUMBER_t>
static bool check2ElementStack(typename ExpTree<NUMBER_t>::NodeStack& stack){
    if(stack.size() < 2){
        return false;
    }
    return true;
}


template<typename NUMBER_t>
static void checkForElements(typename ExpTree<NUMBER_t>::NodeStack& stack){
    if(!check2ElementStack<NUMBER_t>(stack)){
        ExpTree<NUMBER_t>::deallocateStack(stack);
        throw MissingOperandError();
    }
}

#endif //INFIXPOSTFIX_PRECHECK_HPP
