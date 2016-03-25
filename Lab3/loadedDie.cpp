/***************************************************
* Program Filename: loadedDie.cpp
* Author: Robyn Schroeder
* Date: 1/24/2016
* Description:
* Input: User input
* Output:
***************************************************/

#include <cstdlib>
#include <ctime>
#include "die.hpp"
#include "loadedDie.hpp"
#include <iostream>

using namespace std;

//Default constructor - # of sides will default to 6
LoadedDie::LoadedDie(){
	numSides = 6;		
	seed = time(NULL);
	srand(seed);
}

LoadedDie::LoadedDie(int x){
	numSides = x;
	seed = time(NULL);
	srand(seed);
}

int LoadedDie::roll() {
	rollVal = rand() % numSides + 1;	//See pg. 135 in Gaddis. 
	if (rollVal >= (numSides / 2)){
		return rollVal;
	}
	else{
		return (rollVal * 2); 
	}
}