//
// Created by KAVOSH on 1/22/2024.
//
#ifndef INFIXPOSTFIX_TOOLS_HPP
#define INFIXPOSTFIX_TOOLS_HPP
#include "expTree.hpp"
#include "../errorHandler/MissingOperand.hpp"
#include "../errorHandler/WrongOperator.hpp"

template<typename NUMBER>
void rightLeftCompare(InputOrd<NUMBER>& flowI, typename ExpTree<NUMBER>::NodeStack& stack){
    if(stack.empty()){
        throw MissingOperatorError<NUMBER>{};
    }
    auto* right{stack.top()};
    stack.pop();

    if(stack.empty()){
        ExpTree<NUMBER>::makeEmpty(right);
        throw MissingOperatorError<NUMBER>{};
    }

    auto* left{stack.top()};
    stack.pop();

    try {
        isOperator<NUMBER>(flowI.tag, stack);
    }catch (WrongOperatorError<NUMBER>& error){
        ExpTree<NUMBER>::makeEmpty(right);
        ExpTree<NUMBER>::makeEmpty(left);
        throw error;
    }

    auto* newNode = new typename ExpTree<NUMBER>::Node{.value = flowI, .left=left, .right= right};
    stack.push(newNode);
}

template<typename NUMBER>
void leftRightCompare(InputOrd<NUMBER>& flowI, typename ExpTree<NUMBER>::NodeStack& stack){
    if(stack.empty()){throw MissingOperatorError<NUMBER>{};}

    auto* left{stack.top()};
    stack.pop();

    if(stack.empty()){
        ExpTree<NUMBER>::makeEmpty(left);
        throw MissingOperatorError<NUMBER>{};}

    auto* right{stack.top()};
    stack.pop();

    try {
        isOperator<NUMBER>(flowI.tag, stack);
    }catch (WrongOperatorError<NUMBER>& error){
        ExpTree<NUMBER>::makeEmpty(right);
        ExpTree<NUMBER>::makeEmpty(left);
        throw error;
    }

    auto* newNode = new typename ExpTree<NUMBER>::Node{.value = flowI, .left=left, .right= right};
    stack.push(newNode);
}

template<typename NUMBER_t>
void checkOPS(typename ExpTree<NUMBER_t>::NodeStack& stack, std::stack<InputOrd<NUMBER_t>>& op_stack){
    if(op_stack.empty()){
        ExpTree<NUMBER_t>::deallocateStack(stack);
        throw MissingOperatorError<NUMBER_t>{};
    }
}
#endif //INFIXPOSTFIX_TOOLS_HPP
