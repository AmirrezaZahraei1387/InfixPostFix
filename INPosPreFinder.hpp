//
// Created by KAVOSH on 1/20/2024.
//
#ifndef INFIXPOSTFIX_INPOSPREFINDER_HPP
#define INFIXPOSTFIX_INPOSPREFINDER_HPP
#include "inOutE.hpp"

enum StandardType{
    None,
    PostFix,
    InFix,
    PreFix,
};

template<typename NUMBER_t>
StandardType findStandard(InputOrdFlow<NUMBER_t>& flow){
    if(flow.empty()){
        return None;
    }else if(flow[flow.size() - 1].tag != NUMBER){
        return PostFix;

    }else if(flow[0].tag != NUMBER){
        return PreFix;
    }else{
        return InFix;
    }
}

#endif //INFIXPOSTFIX_INPOSPREFINDER_HPP
