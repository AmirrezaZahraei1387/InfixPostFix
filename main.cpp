#include <iostream>
#include "oper/inOutE.hpp"
#include "expTree/expTree.hpp"
#include "INPosPreFinder.hpp"

using APP_TYPE = double;

int main()
{
    InputOrdFlow<APP_TYPE> inputOrdFlow;
    StandardType standardType;
    ExpTree<APP_TYPE> Expr{};


    getUserInput(inputOrdFlow, std::cin);


    standardType = findStandard(inputOrdFlow);

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


    std::cout<<"infix = ";Expr.printInFix(std::cout);std::cout<<std::endl;
    std::cout<<"prefix = ";Expr.printPreFix(std::cout);std::cout<<std::endl;
    std::cout<<"postfix = ";Expr.printPostFix(std::cout);std::cout<<std::endl;

    std::cout<<"evaluates to "<<Expr.calculate()<<std::endl;
    return 0;
}