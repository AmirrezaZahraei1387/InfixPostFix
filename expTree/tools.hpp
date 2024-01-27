//
// Created by KAVOSH on 1/22/2024.
//
#ifndef INFIXPOSTFIX_TOOLS_HPP
#define INFIXPOSTFIX_TOOLS_HPP
#include "expTree.hpp"

template<typename NUMBER>
void rightLeftCompare(InputOrd<NUMBER>& flowI, typename ExpTree<NUMBER>::NodeStack& stack){
    auto* right{stack.top()};
    stack.pop();

    auto* left{stack.top()};
    stack.pop();

    auto* newNode = new typename ExpTree<NUMBER>::Node{.value = flowI, .left=left, .right= right};
    stack.push(newNode);
}

template<typename NUMBER>
void leftRightCompare(InputOrd<NUMBER>& flowI, typename ExpTree<NUMBER>::NodeStack& stack){
    auto* left{stack.top()};
    stack.pop();

    auto* right{stack.top()};
    stack.pop();

    auto* newNode = new typename ExpTree<NUMBER>::Node{.value = flowI, .left=left, .right= right};
    stack.push(newNode);
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::deallocateStack(NodeStack& stack) {
    while (!stack.empty()) {
        makeEmpty(stack.top());
        stack.pop();
    }
}
#endif //INFIXPOSTFIX_TOOLS_HPP
