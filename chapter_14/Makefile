# This Makefile compiles the C++ programs in this directory.

# Chapter 14 [Stacks] (The Coding Interview Prep Handbook, by Raydelto Hernandez)

# The -Wall flag enables all compiler's warning messages.
# The -std=c++17 flag specifies the C++ standard to use.
# The -o flag specifies the name of the output file.

FLAGS = -Wall -std=c++17
CXX = g++  # C++ compiler, you can choose among g++, clang++, etc.

stdStack: 01-stdStack.cpp
	$(CXX) 01-stdStack.cpp $(FLAGS) -o stdStack

expressionChecker: 02-expressionChecker.cpp
	$(CXX) 02-expressionChecker.cpp $(FLAGS) -o expressionChecker
	