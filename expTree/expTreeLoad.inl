//
// Created by KAVOSH on 1/20/2024.
//
#include "expTree.hpp"
#include "../oper/inOutE.hpp"
#include "../oper/op.hpp"
#include "tools.hpp"
#include <cstddef>
#include <stack>


template<typename NUMBER_t>
void ExpTree<NUMBER_t>::loadFromPostFix(InputOrdFlow<NUMBER_t>& flow) {

    NodeStack stack;
    int i = 0;
    InputOrd<NUMBER_t> flowI;

    while(stack.size()!= 1 || i < flow.size()){

        if(i < flow.size()) {
            flowI = flow[i];
        }else{
            flowI = InputOrd<NUMBER_t>{.tag = ADD};
        }

        ++i;

        if(isOperator<NUMBER_t>(flowI.tag, stack)){
            rightLeftCompare(flowI, stack);

        }else {
            stack.push(new Node{.value = flowI});
        }
    }

    makeEmpty();
    root_p = stack.top();
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::loadFromPreFix(InputOrdFlow<NUMBER_t>& flow) {

    NodeStack stack;
    int i = static_cast<int>(flow.size()) - 1;
    InputOrd<NUMBER_t> flowI;

    while(stack.size()!= 1 || i >= 0){

        if(i >= 0) {
            flowI = flow[i];
        }else{
            flowI = InputOrd<NUMBER_t>{.tag = ADD};
        }

        --i;

        if(isOperator<NUMBER_t>(flowI.tag, stack)){
            leftRightCompare(flowI, stack);
        }else {
            stack.push(new Node{.value = flowI});
        }
    }

    makeEmpty();
    root_p = stack.top();
}


template<typename NUMBER_t>
void ExpTree<NUMBER_t>::loadFromInFix(InputOrdFlow<NUMBER_t>& flow) {
    NodeStack nodes;
    std::stack<InputOrd<NUMBER_t>> operators;

    for (auto flowI: flow) {

        if (flowI.tag == NUMBER) {

            nodes.push(new Node{.value = flowI});

        } else if (isParOpen(flowI.tag)) {
            operators.push(flowI);

        } else if (isParClose(flowI.tag)) {

            while (!isParOpen(operators.top().tag)) {
                rightLeftCompare(operators.top(), nodes);
                operators.pop();
            }
            operators.pop();

        } else if (isOperator(flowI.tag)) {
            while (!operators.empty() && isHigherPriorityInfixLoad(operators.top().tag, flowI.tag)) {
                rightLeftCompare(operators.top(), nodes);
                operators.pop();
            }
            operators.push(flowI);
        }
    }

    while (true) {
        if(operators.empty()) {
            if(nodes.size() > 1) {
                operators.push(InputOrd<NUMBER_t>{.tag = ADD});
            }else{
                break;
            }
        }
        rightLeftCompare(operators.top(), nodes);
        operators.pop();
    }


    makeEmpty();
    root_p = nodes.top();
}


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

    return calculateValueW(node->value.tag, calculate(node->left), calculate(node->right));
}

template<typename NUMBER_t>
NUMBER_t ExpTree<NUMBER_t>::calculate() {
    return calculate(root_p);
}

template<typename NUMBER_t>
ExpTree<NUMBER_t>::~ExpTree() noexcept {
    makeEmpty();
    root_p = nullptr;
}


template<typename NUMBER_t>
void ExpTree<NUMBER_t>::deallocateStack(NodeStack& stack){

    while(! stack.empty()){
        makeEmpty(stack.top());
        stack.pop();
    }
}