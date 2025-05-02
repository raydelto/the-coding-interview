# This Makefile compiles the C++ programs in this directory.

# Chapter 19 [Graphs] (The Coding Interview Prep Handbook, by Raydelto Hernandez)

# The -Wall flag enables all compiler's warning messages.
# The -std=c++17 flag specifies the C++ standard to use.
# The -o flag specifies the name of the output file.

FLAGS = -Wall -std=c++17
CXX = g++  # C++ compiler, you can choose among g++, clang++, etc.

breadthFirstGraphTraversal: 01-breadthFirstGraphTraversal.cpp
	$(CXX) 01-breadthFirstGraphTraversal.cpp $(FLAGS) -o breadthFirstGraphTraversal

depthFirstGraphTraversal: 02-depthFirstGraphTraversal.cpp
	$(CXX) 02-depthFirstGraphTraversal.cpp $(FLAGS) -o depthFirstGraphTraversal

dfs: 03-dfs.cpp
	$(CXX) 03-dfs.cpp $(FLAGS) -o dfs

shortestPath: 04-shortestPath.cpp
	$(CXX) 04-shortestPath.cpp $(FLAGS) -o shortestPath

dijkstra: 05-dijkstra.cpp
	$(CXX) 05-dijkstra.cpp $(FLAGS) -o dijkstra
	
