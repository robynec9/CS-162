/***************************************************
* Program Filename: loadedDie.hpp
* Author: Robyn Schroeder
* Date: 1/24/2016
* Description: Pattern header file
* Input:
* Output:
***************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "die.hpp"

class LoadedDie : public Die
{
public:
	LoadedDie();
	LoadedDie(int);
	int roll();

private:
	unsigned seed;
	int rollVal;
};
#endif