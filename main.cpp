// C++ program to convert infix to prefix
#include <iostream>
#include "inOutE.hpp"
#include "expTree/expTree.hpp"
#include "INPosPreFinder.hpp"

int main()
{
    InputOrdFlow<int> inputOrdFlow;
    StandardType standardType;
    ExpTree<int> Expr{};

    getUserInput(inputOrdFlow, std::cin);
    standardType = findStandard(inputOrdFlow);

    switch (standardType) {
        case None:
            std::cout<<"no input provided"<<std::endl;
            return 0;
        case PostFix:
            Expr.loadFromPostFix(inputOrdFlow);
            break;

        case PreFix:
            Expr.loadFromPreFix(inputOrdFlow);
            break;

            // the infix is not added yet
//        case InFix:
//            Expr.loadFromInFix(inputOrdFlow);
//            break;
    }

    std::cout<<"infix = ";Expr.printInFix(std::cout);std::cout<<std::endl;
    std::cout<<"prefix = ";Expr.printPreFix(std::cout);std::cout<<std::endl;
    std::cout<<"postfix = ";Expr.printPostFix(std::cout);std::cout<<std::endl;

    std::cout<<"evaluates to "<<Expr.calculate()<<std::endl;
    return 0;
}