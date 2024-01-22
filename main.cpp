// C++ program to convert infix to prefix
#include <iostream>
#include "errorHandler/OperatorNotFound.hpp"
#include "errorHandler/MissingOperand.hpp"
#include "oper/inOutE.hpp"
#include "expTree/expTree.hpp"
#include "INPosPreFinder.hpp"

int main()
{
    InputOrdFlow<int> inputOrdFlow;
    StandardType standardType;
    ExpTree<int> Expr{};

    try {
        getUserInput(inputOrdFlow, std::cin);

    }catch (OperatorNotFoundError& error){
        std::cerr<<error.what()<<std::endl;
        return -1;
    }

    standardType = findStandard(inputOrdFlow);

    try {
        switch (standardType) {
            case None:
                std::cerr << "no input provided" << std::endl;
                return -1;

            case PostFix:
                std::cout << "detected the exp as PostFix" << std::endl;
                Expr.loadFromPostFix(inputOrdFlow);
                break;

            case PreFix:
                std::cout << "detected the exp as PreFix" << std::endl;
                Expr.loadFromPreFix(inputOrdFlow);
                break;

            case InFix:
                std::cout << "detected the exp as Infix" << std::endl;
                Expr.loadFromInFix(inputOrdFlow);
                break;
        }
    }catch(MissingOperatorError<int>& error){
        std::cerr<<error.what()<<std::endl;
        return -1;

    }catch (WrongOperatorError<int>& error){
        std::cerr<<error.what()<<std::endl;
        return -1;
    }

    std::cout<<"infix = ";Expr.printInFix(std::cout);std::cout<<std::endl;
    std::cout<<"prefix = ";Expr.printPreFix(std::cout);std::cout<<std::endl;
    std::cout<<"postfix = ";Expr.printPostFix(std::cout);std::cout<<std::endl;

    std::cout<<"evaluates to "<<Expr.calculate()<<std::endl;
    return 0;
}