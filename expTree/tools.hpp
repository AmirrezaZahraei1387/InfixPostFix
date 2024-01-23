//
// Created by KAVOSH on 1/22/2024.
//
#ifndef INFIXPOSTFIX_TOOLS_HPP
#define INFIXPOSTFIX_TOOLS_HPP
#include "expTree.hpp"
#include "../errorHandler/MissingOperand.hpp"
#include "../errorHandler/WrongOperator.hpp"

template<typename NUMBER_t>
void rightLeftCompare(InputOrd<NUMBER_t>& flowI, typename ExpTree<NUMBER_t>::NodeStack& stack){
    if(stack.empty()){
        throw MissingOperatorError<NUMBER_t>{};
    }
    auto* right{stack.top()};
    stack.pop();

    if(stack.empty()){
        throw MissingOperatorError<NUMBER_t>{};
    }

    auto* left{stack.top()};
    stack.pop();

    isOperator<NUMBER_t>(flowI.tag, stack);

    auto* newNode = new typename ExpTree<NUMBER_t>::Node{.value = flowI, .left=left, .right= right};
    stack.push(newNode);
}

template<typename NUMBER_t>
void leftRightCompare(InputOrd<NUMBER_t>& flowI, typename ExpTree<NUMBER_t>::NodeStack& stack){
    if(stack.empty()){throw MissingOperatorError<NUMBER_t>{};}

    auto* left{stack.top()};
    stack.pop();

    if(stack.empty()){throw MissingOperatorError<NUMBER_t>{};}

    auto* right{stack.top()};
    stack.pop();

    isOperator<NUMBER_t>(flowI.tag, stack);

    auto* newNode = new typename ExpTree<NUMBER_t>::Node{.value = flowI, .left=left, .right= right};
    stack.push(newNode);
}

#endif //INFIXPOSTFIX_TOOLS_HPP
