cmake_minimum_required(VERSION 4.1.0)
project(SortAlgorithm VERSION 0.1.0 LANGUAGES C)

add_executable(SortAlgorithm main.c
    MergeSort/mergeSort.c
    MergeSort/mergeSort.h
)