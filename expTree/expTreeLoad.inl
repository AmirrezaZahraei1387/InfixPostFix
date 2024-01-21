//
// Created by KAVOSH on 1/20/2024.
//
#include "expTree.hpp"
#include "../inOutE.hpp"
#include <stack>


bool isOperator(TAG tag) {
    switch(tag){
        case ADD:
        case MUL:
        case DEV:
        case SUB:
            return true;
        default:
            return false;
    }
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::loadFromPostFix(InputOrdFlow<NUMBER_t>& flow) {

    std::stack<Node*> stack;

    for(int i{0}; i<flow.size(); ++i){

        if(isOperator(flow[i].tag)){

            Node* right{stack.top()};
            stack.pop();
            Node* left{stack.top()};
            stack.pop();

            Node* newNode = new Node{.value = flow[i], .left = left, .right= right};
            stack.push(newNode);

        }else {
            stack.push(new Node{.value = flow[i]});
        }
    }

    root_p = stack.top();
}