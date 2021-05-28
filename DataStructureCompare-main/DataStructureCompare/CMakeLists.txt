cmake_minimum_required(VERSION 3.19)
project(DataStructureCompare C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructureCompare main.c LinkedList.c LinkedList.h main.h Array.c Array.h ArrayWithBinarySearch.c ArrayWithBinarySearch.h BinarySearchTree.c BinarySearchTree.h Hash.c Hash.h Data.h)