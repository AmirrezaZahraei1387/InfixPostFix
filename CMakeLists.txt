cmake_minimum_required(VERSION 3.16.3)
project(InfixPostFix)

set(CMAKE_CXX_STANDARD 17)

add_executable(InfixPostFix
        main.cpp
        oper/inOutE.hpp
        expTree/expTree.hpp
        expTree/expTreePrint.inl
        expTree/expTreeLoad.inl
        INPosPreFinder.hpp oper/inOutE.cpp)
