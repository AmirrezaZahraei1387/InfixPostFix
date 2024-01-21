//
// Created by KAVOSH on 1/20/2024.
//
#include "expTree.hpp"

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::printPostFix(ExpTree::Node*& node, std::ostream& outStream) {
    if(node  == nullptr)
        return;
    else{
        printPostFix(node->left, outStream);
        printPostFix(node->right, outStream);

        printW(node->value, outStream);
    }
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::printPreFix(ExpTree::Node *&node, std::ostream &outStream) {
    if(node  == nullptr)
        return;
    else{
        printW(node->value, outStream);

        printPreFix(node->left, outStream);
        printPreFix(node->right, outStream);
    }
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::printInfix(ExpTree::Node *&node, std::ostream &outStream) {
    if(node  == nullptr)
        return;
    else{
        outStream<<'(';
        printInfix(node->left, outStream);
        printW(node->value, outStream);
        printInfix(node->right, outStream);
        outStream<<')';
    }
}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::printInfix(std::ostream &outStream)
{printInfix(root_p, outStream);}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::printPreFix(std::ostream &outStream)
{printPreFix(root_p, outStream);}

template<typename NUMBER_t>
void ExpTree<NUMBER_t>::printPostFix(std::ostream& outStream)
{printPostFix(root_p, outStream);}


