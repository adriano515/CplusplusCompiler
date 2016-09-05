cmake_minimum_required(VERSION 3.6)
project(C__Compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp postfix.cpp postfix.h TreeNode.cpp TreeNode.h AutomataNode.cpp AutomataNode.h NFAgenerator.cpp NFAgenerator.h Transition.h)
add_executable(C__Compiler ${SOURCE_FILES})
