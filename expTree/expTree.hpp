//
// Created by KAVOSH on 1/20/2024.
//
#ifndef INFIXPOSTFIX_EXPTREE_HPP
#define INFIXPOSTFIX_EXPTREE_HPP
#include "../inOutE.hpp"
#include <ostream>


template<typename NUMBER_t>
class ExpTree{
public:
    void printInfix(std::ostream& outStream);
    void printPreFix(std::ostream& outStream);
    void printPostFix(std::ostream& outStream);

    void loadFromPostFix(InputOrdFlow<NUMBER_t>& flow);

private:
    struct Node{
        InputOrd<NUMBER_t> value;

        Node* left{nullptr};
        Node* right{nullptr};
    };

    Node* root_p;

    void printInfix(Node*& node,  std::ostream& outStream);
    void printPreFix(Node*& node,  std::ostream& outStream);
    void printPostFix(Node*& node,  std::ostream& outStream);
};


bool isOperator(TAG tag);

#include "expTreeLoad.inl"
#include "expTreePrint.inl"
#endif //INFIXPOSTFIX_EXPTREE_HPP
