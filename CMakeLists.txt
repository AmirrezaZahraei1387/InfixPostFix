cmake_minimum_required(VERSION 3.10)

project(InfixPostFix VERSION 1.0)
configure_file(InfixPostFixConfig.h.in config/InfixPostFixConfig.h)

set(CMAKE_CXX_STANDARD 17)

add_executable(InfixPostFix
        main.cpp
        oper/inOutE.hpp
        expTree/expTree.hpp
        expTree/expTreePrint.inl
        expTree/expTreeLoad.inl
        preCheck/INPosPreFinder.hpp
        oper/inOutE.cpp
        oper/resolveNum.cpp
        expTree/tools.hpp
        oper/loader/loader.hpp
        preCheck/except.hpp
        preCheck/preCheck.hpp)
