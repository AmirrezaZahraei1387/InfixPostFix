//
// Created by mzahr on 1/26/2024.
//

#ifndef INFIXPOSTFIX_LOADER_HPP
#define INFIXPOSTFIX_LOADER_HPP

#include <map>
#include <string>
#include <vector>
#include <cmath>

namespace OPD {
    struct OrganizerEXP;
    using Priority = int;
    using Operator = char;
    using Seperator = char;
    using NumPos = char;
    using NumNeg = char;
    using NUMBER = int;

    using OperatorsT = std::map<Operator, Priority>;
    using OrganizerEXPT = std::vector<OrganizerEXP>;

    struct OrganizerEXP {
        char opening;
        char closing;
    };

    struct OPRules {
        OperatorsT operators;
        OrganizerEXPT organizers;
        Seperator sep;

        NumNeg numNeg;
        NumPos numPos;

        bool isNumNegOp;
        bool isNumPosOp;

        NUMBER number_ind;
        OrganizerEXP default_neg_num_org;
    };

    inline const OPRules opRules{
            .operators{{'+', 1},
                       {'-', 1},
                       {'*', 2},
                       {'/', 2}},

            .organizers{{'(', ')'},
                        {'{', '}'},
                        {'[', ']'}},

            .sep = ' ',

            .numNeg = '-',
            .numPos = '+',

            .number_ind = '0',
            .default_neg_num_org = {'(', ')'},

    };

    template<typename NUMBER_t>
    NUMBER_t calculateValueW(char op, NUMBER_t left, NUMBER_t right) {
        switch (op) {
            case '+':
                return left + right;

            case '-':
                return left - right;

            case '*':
                return left * right;

            case '/':
                return left / right;
        }
    }
}// OPD
#endif //INFIXPOSTFIX_LOADER_HPP
