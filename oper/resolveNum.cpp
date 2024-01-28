#include "inOutE.hpp"
#include "../preCheck/except.hpp"

static const std::string DOT_STR{"."};
static constexpr char DOT_CHAR{'.'};

static bool checkNumDot(std::string& resolve_number){
    if(resolve_number == DOT_STR){
        return false;
    }else if(std::count(resolve_number.begin(), resolve_number.end(), DOT_CHAR) > 1){
        return false;
    }else{
        return true;
    }
}

template<>
void resolveNumber<int>(InputOrdFlow<int>& inputOrdFlow, std::string& strSeq){

    if(!checkNumDot(strSeq)){
        throw NumberError();
    }

    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<int>{.tag = static_cast<char>(OPD::opRules.number_ind),
                .number = std::stoi(strSeq)});
        strSeq.clear();
    }
}

template<>
void resolveNumber<double>(InputOrdFlow<double>& inputOrdFlow, std::string& strSeq){

    if(!checkNumDot(strSeq)){
        throw NumberError();
    }

    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<double>{.tag = static_cast<char>(OPD::opRules.number_ind),
                .number = std::stod(strSeq)});
        strSeq.clear();
    }
}

template<>
void resolveNumber<float>(InputOrdFlow<float>& inputOrdFlow, std::string& strSeq){

    if(!checkNumDot(strSeq)){
        throw NumberError();
    }

    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<float>{.tag = static_cast<char>(OPD::opRules.number_ind),
                .number = std::stof(strSeq)});
        strSeq.clear();
    }
}


template<>
void resolveNumber<long long>(InputOrdFlow<long long>& inputOrdFlow, std::string& strSeq){

    if(!checkNumDot(strSeq)){
        throw NumberError();
    }

    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<long long>{.tag = static_cast<char>(OPD::opRules.number_ind),
                .number = std::stoll(strSeq)});
        strSeq.clear();
    }
}

template<>
void resolveNumber<long double>(InputOrdFlow<long double>& inputOrdFlow, std::string& strSeq){

    if(!checkNumDot(strSeq)){
        throw NumberError();
    }

    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<long double>{.tag = static_cast<char>(OPD::opRules.number_ind),
                .number = std::stold(strSeq)});
        strSeq.clear();
    }
}