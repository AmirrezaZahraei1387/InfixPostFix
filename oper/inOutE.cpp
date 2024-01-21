//
// Created by KAVOSH on 1/21/2024.
//
#include "inOutE.hpp"

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

bool isHigherPriority(TAG tag_1, TAG tag_2){

    if(tag_1 == PAR_OPEN || tag_2 == PAR_CLOSE || tag_1 == NUMBER){
        return false;
    }

    return (tag_1 == MUL || tag_1 == DEV)|| (tag_2 == ADD || tag_2 == SUB);
}