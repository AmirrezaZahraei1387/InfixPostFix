//
// Created by KAVOSH on 1/21/2024.
//
#include "inOutE.hpp"
#include "loader/loader.hpp"

bool isOperator(char tag) {
    for(auto op : OPD::opRules.operators){
        if(tag == op.first){
            return true;
        }
    }
    return false;
}

static OPD::Priority getPriority(char c){
    for(auto op : OPD::opRules.operators){
        if(c == op.first)
            return op.second;
    }
    return 0;
}

bool isHigherPriorityInfixLoad(char tag_1, char tag_2){

    for(auto par: OPD::opRules.organizers){
        if(tag_1 == par.opening || tag_2 == par.closing || tag_1 == OPD::opRules.number_ind){
            return false;
        }
    }

//    return (tag_1 == MUL || tag_1 == DEV)|| (tag_2 == ADD || tag_2 == SUB);
    return getPriority(tag_1) >= getPriority(tag_2);
}

bool isParOpen(char tag){
    for(auto par: OPD::opRules.organizers){
        if(tag == par.opening){
            return true;
        }
    }
    return false;
}

bool isParClose(char tag){
    for(auto par: OPD::opRules.organizers){
        if(tag == par.closing){
            return true;
        }
    }
    return false;
}

bool isNumber(char tag) {
    return tag == OPD::opRules.number_ind;
}
