/***************************************************
* Program Filename: die.hpp
* Author: Robyn Schroeder
* Date: 1/24/2016
* Description: Die header file
* Input:
* Output:
***************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die{

protected:
	int numSides;

public:
	Die();
	Die(int numSides);
	virtual int roll();

private:
	unsigned seed;
};
#endif