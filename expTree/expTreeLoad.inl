//
// Created by KAVOSH on 1/20/2024.
//
#include "expTree.hpp"
#include "../inOutE.hpp"
#include <cstddef>
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
    int i = 0;
    InputOrd<NUMBER_t> flowI;

    while(stack.size()!= 1 || i < flow.size()){

        if(i < flow.size()) {
            flowI = flow[i];
        }else{
            flowI = InputOrd<NUMBER_t>{.tag = ADD};
        }

        ++i;

        if(isOperator(flowI.tag)){

            Node* right{stack.top()};
            stack.pop();
            // + + 4 * 5 3 5
            Node* left{stack.top()};
            stack.pop();

            Node* newNode = new Node{.value = flowI, .left=left, .right= right};

            stack.push(newNode);


        }else {
            stack.push(new Node{.value = flowI});
        }
    }

    makeEmpty();
    root_p = stack.top();
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::loadFromPreFix(InputOrdFlow<NUMBER_t>& flow) {

    std::stack<Node*> stack;
    int i = static_cast<int>(flow.size()) - 1;
    InputOrd<NUMBER_t> flowI;

    while(stack.size()!= 1 || i >= 0){

        if(i >= 0) {
            flowI = flow[i];
        }else{
            flowI = InputOrd<NUMBER_t>{.tag = ADD};
        }

        --i;

        if(isOperator(flowI.tag)){

            Node* left{stack.top()};
            stack.pop();
            // + + 4 * 5 3 5
            Node* right{stack.top()};
            stack.pop();

            Node* newNode = new Node{.value = flowI, .left=left, .right= right};

            stack.push(newNode);


        }else {
            stack.push(new Node{.value = flowI});
        }
    }

    makeEmpty();
    root_p = stack.top();
}


//template<typename NUMBER_t>
//void ExpTree<NUMBER_t>::loadFromInfix(InputOrdFlow<NUMBER_t>& flow) {
//    std::stack<Node*> stack;
//    int i = 0;
//    bool flag_par_open{false};
//    InputOrd<NUMBER_t> flowI;
//
//    while(stack.size()!= 1 || i < flow.size()){
//
//        if(i < flow.size()) {
//            flowI = flow[i];
//        }else{
//            flowI = InputOrd<NUMBER_t>{.tag = ADD};
//        }
//
//        ++i;
//
//        if(isOperator(flowI.tag)){
//
//            Node* right{stack.top()};
//
//            stack.pop();
//            // + + 4 * 5 3 5
//            Node* left{stack.top()};
//            stack.pop();
//
//            Node* newNode = new Node{.value = flowI, .left=left, .right= right};
//
//            stack.push(newNode);
//
//
//        }else if(flowI.tag == PAR_OPEN){
//            flag_par_open = true;
//        }else if(flowI.tag == PAR_CLOSE){
//            flag_par_open = false;
//        }
//        else{
//            stack.push(new Node{.value = flowI});
//        }
//    }
//
//    makeEmpty();
//    root_p = stack.top();
//}


template<typename NUMBER_t>
void ExpTree<NUMBER_t>::makeEmpty(ExpTree::Node *&node) {
    if(node == nullptr) return;

    makeEmpty(node->left);
    makeEmpty(node->right);

    delete node;
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::makeEmpty() {
    makeEmpty(root_p);
}

template<typename NUMBER_t>
NUMBER_t ExpTree<NUMBER_t>::calculate(ExpTree::Node *&node) {

    if(node->value.tag == NUMBER){
        return node->value.number;
    }

    return calculateValueW(node->value.tag, calculate(node->right), calculate(node->left));
}

template<typename NUMBER_t>
NUMBER_t ExpTree<NUMBER_t>::calculate() {
    return calculate(root_p);
}
