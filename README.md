# InfixPostFix


## General Info
___
|       LABEL       |     Value      |
|:-----------------:|:--------------:|
|       Name        | Mohsen Zahraei |
|     USERNAME      |      301       |
|    Student ID     |      301       |
|      Course       |      301       |
| Assignment Number |      301       |
____

## What is our Goal
The goal was creation of a simple program to be able to
ind independently take in different sort of operators with exactly
two operands, organizers and various other details to handle infix, postfix
 and prefix expressions and then evaluate them and print them in different
forms. The program is also able to hande various errors and notify the user
of that certain type of error.

## Giving Input
After building, you can run the executable in your
shell and, then you can give an input expression in
postfix, infix or prefix. The expression will be printed in
the postfix, prefix and infix and the evaluation of it
will be printed too.

Here is an example of input for infix expression "2 * ((4 - 3)^ 2 - 4) + 6*5"


``` cmd
make run
./InfixPostFixConvertor
2 * ((4 - 3)^ 2 - 4) + 6*5
detected the exp as Infix
infix = ( ( ( 2 ) * ( ( ( ( 4 ) - ( 3 ) ) ^ ( 2 ) ) - ( 4 ) ) ) + ( ( 6 ) * ( 5 ) ) ) 
prefix = + * 2 - ^ - 4 3 2 4 * 6 5 
postfix = 2 4 3 - 2 ^ 4 - * 6 5 * + 
evaluates to 24
```

## Files Libraries and Headers

|          File Name          |                                                                         
|:---------------------------:|
|     expTree/expTree.hpp     |                                            
|   expTree/expTreeLoad.inl   | 
|  expTree/expTreePrint.inl   |        
|      expTree/tools.hpp      |
|   oper/loader/loader.hpp    | 
|       oper/inOutE.cpp       |
|       oper/inOutE.hpp       |
|     oper/resolveNum.cpp     |
|     preCheck/except.hpp     |
| preCheck/INPosPreFinder.hpp |
|    preCheck/preCheck.hpp    |
|          main.cpp           |

| Libraries |                                                                         
|:---------:|
|  ostream  |                                            
|   stack   | 
|  cstddef  |        
|    map    |
|  string   | 
|  vector   |
|   cmath   |
|  istream  |
|   array   |
| algorithm |
| exception |
| iostream  |

## Building and Run

For building, you can need g++ and make build system.
then you can type in your shell:

``` cmd
make all
```

and then
``` cmd
make run
```
to run the project.

Cmake also can be used. Configure the project's CMakeLists.txt
with cmake and then build the project.

## Adding new Operators and features

It is possible to add your own defined operators and 
details to program to meet your own expectations.

To do so you must modify the file in path
```
oper/loader/loader.hpp
```
It contains an important type called "OPRules" which
define the following features:

|       Feature       |                                              Explanation                                              |
|:-------------------:|:-----------------------------------------------------------------------------------------------------:|
|      operators      |            define operators as one single character and their precedence with an integer.             |
|     organizers      |                  defines the exp organizers such as parenthesis, brackets and so on.                  |
|         sep         |               defines the seperator used for putting between each element when printing               |
|  numNeg and numPos  | defines what character may follow a negative or positive number. (They must be one of the operators.) |
|     number_ind      |             defines what character will notify the case of a number. It have to be unique             |
| default_neg_num_org |                       defines the organizer used for printing negative numbers                        |

You can change these values in the variable opRules (which is an instance of OPRules)
to the values that meet your needs. You also need to implement the following function

``` c++
    template<typename NUMBER_t>
    NUMBER_t calculateValueW(char op, NUMBER_t left, NUMBER_t right);
```

this functions defines how each of the operators will actually work.
you may use a "switch - case" statement to implement this function.

the default calculateValueW is as follows:
```c++
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

            case '^':
                return std::pow(left, right);
        }
    }
```
