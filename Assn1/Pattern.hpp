/***************************************************
* Program Filename: Pattern.hpp
* Author: Robyn Schroeder
* Date: 1/16/2016
* Description: Pattern header file
* Input:
* Output:
***************************************************/

#ifndef PATTERN_HPP
#define PATTERN_HPP

#include <string>
#include <iostream>
//#include "Cell.hpp"

void setPattern(int**, const int, const int, int, int, char, int);
void printInitPattern(int**, const int, const int, int);
void printPattern(int**, const int, const int, int);
void nextPattern(int**, int**, const int, const int);

#endif
