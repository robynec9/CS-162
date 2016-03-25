/***************************************************
* Program Filename: GOLmain.cpp
* Author: Robyn Schroeder
* Date: 1/15/2016
* Description: This is the main file for Conway's Game
*	of Life. 
* Input: Desired pattern, pattern placement in x and y coords.
* Output: Conway's Game of Life
***************************************************/

#include <iostream>
#include <string>
#include "Pattern.hpp"

using namespace std;

int main(){

	//Prompt the user for the desired pattern
	cout << "Welcome to Conway's Game of Life!" << endl;
	cout << "What pattern would you like to start with?:" << endl;
	cout << "\t(A) Simple Oscillator" << endl;
	cout << "\t(B) Glider" << endl;
	cout << "\t(C) Cannon" << endl;

	char selection;
	cin >> selection;

	//Prompt user for the desired placement of the pattern
	cout << "Where would you like to place the cell pattern in the x-direction?" << endl;
	cout << "Choose a number between 0 to 30." << endl;

	int buffer = 20; //used to "zoom" the whole world to the visible world

	int input; //used to determine the starting position of pattern
	cin >> input;
	int x_pos = input + buffer;

	cout << "Where would you like to place the cell pattern in the y-direction?" << endl;
	cout << "Please enter a number between 0 and 10: " << endl;

	cin >> input;
	int y_pos = input + buffer;

	string pattern;  //string used to display selection to user

	//Used to display selection to user
	if (selection == 'A'){
		pattern = "simple ocillator";
	}
	else if (selection == 'B'){
		pattern = "glider";
	}
	else if (selection == 'C'){
		pattern = "cannon";
	}
	else {
		cout << "Selection is invalid. Please start over." << endl;
	}

	//Print user selections 
	cout << "The pattern you have chosen to start with is the "
		<< pattern << "." << endl;
	cout << "The " << pattern << " will start at " << x_pos - buffer
		<< " and " << y_pos - buffer << ".\n" << endl;

	const int ROW = 60; //size of entire world (not just visible world) - X
	const int COL = 80; //size of entire world (not just visible world) - Y

	//Initialize pointer matrix
	int** matrix = new int*[ROW];
	for (int i = 0; i < ROW; i++){
		matrix[i] = new int[COL];
	}

	//Intialize pointer matrix for next generation
	int** newMatrix = new int*[ROW];
	for (int i = 0; i < ROW; i++){
		newMatrix[i] = new int[COL];
	}

	setPattern(newMatrix, ROW, COL, x_pos, y_pos, selection, buffer);
	printInitPattern(newMatrix, ROW, COL, buffer);
	nextPattern(matrix, newMatrix, ROW, COL);

	int genCounter = 1;
	char contPrgm;
	contPrgm = 'Y';

	//Game loop that will continue until user inputs 'N'
	while (contPrgm == 'Y'){
		cout << "\nGeneration " << genCounter << endl;
		cout << "\nWould you like to view the next generation? (Y/N)" << endl;
		cin >> contPrgm;
		nextPattern(matrix, newMatrix, ROW, COL);
		printPattern(matrix, ROW, COL, buffer);
		genCounter++;
	}
	
	return 0;
}