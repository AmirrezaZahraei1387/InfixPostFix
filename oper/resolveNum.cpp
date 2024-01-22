#include "inOutE.hpp"


template<>
void resolveNumber<int>(InputOrdFlow<int>& inputOrdFlow, std::string& strSeq){
    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<int>{.tag = NUMBER,
                .number = std::stoi(strSeq)});
        strSeq.clear();
    }
}

template<>
void resolveNumber<double>(InputOrdFlow<double>& inputOrdFlow, std::string& strSeq){
    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<double>{.tag = NUMBER,
                .number = std::stod(strSeq)});
        strSeq.clear();
    }
}

template<>
void resolveNumber<float>(InputOrdFlow<float>& inputOrdFlow, std::string& strSeq){
    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<float>{.tag = NUMBER,
                .number = std::stof(strSeq)});
        strSeq.clear();
    }
}


template<>
void resolveNumber<long long>(InputOrdFlow<long long>& inputOrdFlow, std::string& strSeq){
    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<long long>{.tag = NUMBER,
                .number = std::stoll(strSeq)});
        strSeq.clear();
    }
}

template<>
void resolveNumber<long double>(InputOrdFlow<long double>& inputOrdFlow, std::string& strSeq){
    if(!strSeq.empty()) {
        inputOrdFlow.push_back(InputOrd<long double>{.tag = NUMBER,
                .number = std::stold(strSeq)});
        strSeq.clear();
    }
}