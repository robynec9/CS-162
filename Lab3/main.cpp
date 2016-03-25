/***************************************************
* Program Filename: main.cpp
* Author: Robyn Schroeder
* Date: 1/24/2016
* Description: This is the main file for the Game of War
*	with dice for Lab 3.
* Input: 
* Output: 
***************************************************/

#include <iostream>
#include <string>
#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"

using namespace std;

Die* chooseDie(int, int);

int main(){
	
	//Game Setup - Player 1, Player 2, Rounds, Dice
	int dieType1;
	int dieType2;
	int sides1;
	int sides2;
	int rounds;

	//Player 1
	cout << "Welcome to the Game of War!\n" << endl;
	cout << "\nPLAYER 1 SETUP: \n";
	cout << "Will player 1 be using a standard die or loaded die? ";
	cout << "\n\t(1) STANDARD" << endl;
	cout << "\t(2) LOADED" << endl;
	cin >> dieType1;
	cout << "\nHow many SIDES will player 1's die have? ";
	cin >> sides1; 

	//Player 2
	cout << "\n\nPLAYER 2 SETUP: \n";
	cout << "Will player 2 be using a standard die or loaded die? ";
	cout << "\n\t(1) STANDARD" << endl;
	cout << "\t(2) LOADED" << endl;
	cin >> dieType2;
	cout << "How many SIDES will player 2's die have? ";
	cin >> sides2;

	//Rounds
	cout << "\nGAME SETUP: " << endl;
	cout << "How many ROUNDS would you like to play? ";
	cin >> rounds;
	cout << "\n";
	

	Game newGame;
	
	//Dice
	Die* die1 = chooseDie(dieType1, sides1);
	Die* die2 = chooseDie(dieType2, sides2);
	
	int rollValue1;
	int rollValue2;

	//Run game here
	for (int i = 1; i <= rounds; i++){
		rollValue1 = die1->roll();
		rollValue2 = die2->roll();

		newGame.TallyRoundWinner(rollValue1, rollValue2);

		//Winner of the round is printed.
		cout << "P1 rolled " << rollValue1 << ", P2 rolled " << rollValue2 << endl;
		cout << "ROUND " << i << ", " << newGame.GetRoundWinner(rollValue1, rollValue2) << "\n"; 
	}

	//Display results
	cout << "GAME RESULTS:";
	cout << "\nPlayer 1" << endl;
	cout << "Die Type: " << dieType1 << endl;
	cout << "Size of Die: " << sides1 << endl;
	cout << "\nPlayer 2 " << endl;
	cout << "Die Type: " << dieType2 << endl;
	cout << "Size of Die: " << sides2 << endl;
	cout << newGame.GetWinner() << endl;

	system("pause");
	return 0;
}

Die* chooseDie(int type, int sides){
	if (type == 1){
		return new Die(sides);
	}
	else{
		return new LoadedDie(sides);
	}
}