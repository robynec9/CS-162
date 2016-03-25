/***************************************************
* Program Filename: die.hpp
* Author: Robyn Schroeder
* Date: 1/24/2016
* Description: Game header file
* Input:
* Output:
***************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "die.hpp"
#include "loadedDie.hpp"

using namespace std;

class Game{

private:
	int player1Wins;
	int player2Wins;

public:
	void TallyRoundWinner(int, int);
	string GetWinner();
	string GetRoundWinner(int, int);
};
#endif
