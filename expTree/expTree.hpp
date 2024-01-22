//
// Created by KAVOSH on 1/20/2024.
//
#ifndef INFIXPOSTFIX_EXPTREE_HPP
#define INFIXPOSTFIX_EXPTREE_HPP
#include "../oper/inOutE.hpp"
#include <ostream>
#include <stack>


template<typename NUMBER_t>
class ExpTree{
public:
    explicit ExpTree() = default;
    ~ExpTree() noexcept;

    void printInFix(std::ostream& outStream);
    void printPreFix(std::ostream& outStream);
    void printPostFix(std::ostream& outStream);

    void loadFromPreFix(InputOrdFlow<NUMBER_t>& flow);
    void loadFromPostFix(InputOrdFlow<NUMBER_t>& flow);
    void loadFromInFix(InputOrdFlow<NUMBER_t>& flow);

    void makeEmpty();
    NUMBER_t calculate();

    struct Node{
        InputOrd<NUMBER_t> value;

        Node* left{nullptr};
        Node* right{nullptr};
    };

    using NodeStack = std::stack<Node*>;

private:
    Node* root_p;

    void printInFix(Node*& node,  std::ostream& outStream);
    void printPreFix(Node*& node,  std::ostream& outStream);
    void printPostFix(Node*& node,  std::ostream& outStream);

    NUMBER_t calculate(Node*& node);

    static void makeEmpty(Node*& node);
    static void deallocateStack(NodeStack& stack);
};


bool isOperator(TAG tag);

#include "expTreeLoad.inl"
#include "expTreePrint.inl"

#endif //INFIXPOSTFIX_EXPTREE_HPP
