/***************************************************
* Program Filename: game.cpp
* Author: Robyn Schroeder
* Date: 1/24/2016
* Description:
* Input: User input
* Output:
***************************************************/

#include <iostream>
#include <string>
#include "game.hpp"
using namespace std;

void Game::TallyRoundWinner(int player1Roll, int player2Roll){

	if (player1Roll > player2Roll){
		player1Wins++;
	}
	else if (player1Roll < player2Roll){
		player2Wins++;
	}
	else{	//do nothing if the rolls are tied
	}
}
string Game::GetWinner(){

	if (player1Wins > player2Wins){
		return "\nTHE WINNER OF THE GAME OF WAR IS PLAYER 1!";
	}
	else if (player1Wins < player2Wins){
		return "\nTHE WINNER OF THE GAME OF WAR IS PLAYER 2!";
	}
	else{
		return "\nPlayer 1 and Player 2 tied!";
	}
}

string Game::GetRoundWinner(int player1Roll, int player2Roll){
	if (player1Roll > player2Roll){
		return "player 1 won this round!\n";
	}
	else if (player1Roll < player2Roll){
		return "player 2 won round!\n";
	}
	else{
		return "player 1 and player 2 tied this round!\n";
	}
}