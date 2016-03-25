/***************************************************
* Program Filename: die.cpp
* Author: Robyn Schroeder
* Date: 1/24/2016
* Description: 
* Input: User input
* Output: 
***************************************************/
//#include <stddef.h>
#include <cstdlib>
#include <ctime>
#include "loadedDie.hpp"
#include "die.hpp"
#include <iostream>

using namespace std;

//Default constructor - # of sides will default to 6
Die::Die(){		
	numSides = 6;
	seed = time(NULL);
	srand(seed); //need srand in order to produce rand in roll func
}

Die::Die(int x){
	numSides = x;
	seed = time(NULL);
	srand(seed); //need srand in order to produce rand in roll func
}

int Die::roll(){
	return ((rand() % numSides) + 1); //See pg. 135 in Gaddis. Used to get die range.
}
