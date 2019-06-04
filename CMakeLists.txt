cmake_minimum_required(VERSION 3.12)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure main.cpp Graph/Graph.cpp Graph/Graph.h Sorter.cpp Sorter.h Graph/ALGraph.cpp Graph/ALGraph.h tmp.cpp tmp.h Graph/OLGraph.cpp Graph/OLGraph.h Graph/utility.h Graph/AMLGraph.cpp Graph/AMLGraph.h Graph/MGraph.cpp Graph/MGraph.h Queue/Queue.cpp Queue/Queue.h Tree/CSTree.cpp Tree/CSTree.h Tree/Tree.cpp Tree/Tree.h Tree/BinaryTree.cpp Tree/BinaryTree.h Tree/utility.h Stack/Stack.cpp Stack/Stack.h)