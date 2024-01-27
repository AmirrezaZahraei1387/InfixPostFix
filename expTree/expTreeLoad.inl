//
// Created by KAVOSH on 1/20/2024.
//
#include "expTree.hpp"
#include "../oper/inOutE.hpp"
#include "../preCheck/except.hpp"
#include "../preCheck/preCheck.hpp"
#include "tools.hpp"
#include <cstddef>
#include <stack>


template<typename NUMBER_t>
void ExpTree<NUMBER_t>::loadFromPostFix(InputOrdFlow<NUMBER_t>& flow) {

    NodeStack stack;
    int i = 0;
    InputOrd<NUMBER_t> flowI;

    while(i < flow.size()){

        flowI = flow[i];

        ++i;

        if(isOperator(flowI.tag)){
            checkForElements<NUMBER_t>(stack);
            rightLeftCompare(flowI, stack);

        }else if(isNumber(flowI.tag)){
            stack.push(new Node{.value = flowI});

        }else{
            deallocateStack(stack);
            throw IllegalOperatorError();
        }
    }

    if(stack.size() == 1){
        makeEmpty();
        root_p = stack.top();
    }else{
        deallocateStack(stack);
        throw MissingOperatorError();
    }
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::loadFromPreFix(InputOrdFlow<NUMBER_t>& flow) {

    NodeStack stack;
    int i = static_cast<int>(flow.size()) - 1;
    InputOrd<NUMBER_t> flowI;

    while(i >= 0){

        flowI = flow[i];

        --i;

        if(isOperator(flowI.tag)){
            checkForElements<NUMBER_t>(stack);
            leftRightCompare(flowI, stack);

        }else if(isNumber(flowI.tag)){
            stack.push(new Node{.value = flowI});

        }else{
            deallocateStack(stack);
            throw IllegalOperatorError();
        }
    }

    if(stack.size() == 1){
        makeEmpty();
        root_p = stack.top();
    }else{
        deallocateStack(stack);
        throw MissingOperatorError();
    }
}


template<typename NUMBER_t>
void ExpTree<NUMBER_t>::loadFromInFix(InputOrdFlow<NUMBER_t>& flow) {

    int par_open_count{0};
    int par_close_count{0};

    NodeStack nodes;
    std::stack<InputOrd<NUMBER_t>> operators;

    for (auto flowI: flow) {

        if (isNumber(flowI.tag)) {
            nodes.push(new Node{.value = flowI});

        } else if (isParOpen(flowI.tag)) {
            ++par_open_count;
            operators.push(flowI);

        } else if (isParClose(flowI.tag)) {
            ++par_close_count;

            if(par_close_count > par_open_count){
                deallocateStack(nodes);
                throw OrganizerError();
            }

            while (!isParOpen(operators.top().tag)) {
                checkForElements<NUMBER_t>(nodes);
                rightLeftCompare(operators.top(), nodes);
                operators.pop();
            }
            operators.pop();

        } else if (isOperator(flowI.tag)) {
            //checkOPS(nodes, operators);
            while (!operators.empty() && isHigherPriorityInfixLoad(operators.top().tag, flowI.tag)) {
                checkForElements<NUMBER_t>(nodes);
                rightLeftCompare(operators.top(), nodes);
                operators.pop();
            }
            operators.push(flowI);
        }
    }

    if(par_close_count != par_open_count){
        deallocateStack(nodes);
        throw OrganizerError();
    }

    while (true) {

        if(operators.empty()){
            break;
        }
        checkForElements<NUMBER_t>(nodes);
        rightLeftCompare(operators.top(), nodes);
        operators.pop();
    }

    if(nodes.size() == 1){
        makeEmpty();
        root_p = nodes.top();
    }else{
        deallocateStack(nodes);
        throw MissingOperatorError();
    }
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

    if(node->value.tag == OPD::opRules.number_ind){
        return node->value.number;
    }

    return OPD::calculateValueW(node->value.tag, calculate(node->left), calculate(node->right));
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
