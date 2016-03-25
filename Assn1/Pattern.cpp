/***************************************************
* Program Filename: Pattern.hpp
* Author: Robyn Schroeder
* Date: 1/16/2016
* Description: Pattern functions
* Input: User input
* Output: Conway's Game of Life
***************************************************/

#include <iostream>
#include <string>
#include "Pattern.hpp"

using namespace std;

/***************************************************
* Function: setPattern();
* Description: Initializes the board with the starting pattern
* Parameters: pointer int 2d array, const int # of rows, const int # of cols,
*		int starting x-postion, int starting y-position, char user selection, 
*		int buffer to visible world.
* Pre-Conditions: None
* Post-Conditions: None
***************************************************/

void setPattern(int** newMatrix, const int ROW, const int COL, int x_pos, int y_pos, char selection, int buffer){

	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			newMatrix[i][j] = 0;
		}
	}

	if (selection == 'A'){				//Simple Oscillator (3-cells)
		newMatrix[y_pos + 1][x_pos] = 1;
		newMatrix[y_pos + 1][x_pos + 1] = 1;
		newMatrix[y_pos + 1][x_pos + 2] = 1;
	}
	else if (selection == 'B'){			//Glider
		newMatrix[y_pos + 1][x_pos] = 1;
		newMatrix[y_pos + 1][x_pos + 1] = 1;
		newMatrix[y_pos + 1][x_pos + 2] = 1;
		newMatrix[y_pos + 2][x_pos + 2] = 1;			
		newMatrix[y_pos + 3][x_pos + 1] = 1;
	}
	//Glider Gun - Coordinates for pattern found online at:
	//https://code.google.com/p/conway/source/browse/trunk/Conway/Patterns.java
	else {
		newMatrix[y_pos + 1][x_pos + 22] = 1;
		newMatrix[y_pos + 1][x_pos + 24] = 1;
		newMatrix[y_pos + 2][x_pos + 12] = 1;
		newMatrix[y_pos + 2][x_pos + 13] = 1;
		newMatrix[y_pos + 2][x_pos + 20] = 1;
		newMatrix[y_pos + 2][x_pos + 21] = 1;
		newMatrix[y_pos + 2][x_pos + 34] = 1;
		newMatrix[y_pos + 2][x_pos + 35] = 1;
		newMatrix[y_pos + 3][x_pos + 11] = 1;
		newMatrix[y_pos + 3][x_pos + 15] = 1;
		newMatrix[y_pos + 3][x_pos + 20] = 1;
		newMatrix[y_pos + 3][x_pos + 21] = 1;
		newMatrix[y_pos + 3][x_pos + 34] = 1;
		newMatrix[y_pos + 3][x_pos + 35] = 1;
		newMatrix[y_pos + 4][x_pos + 0] = 1;
		newMatrix[y_pos + 4][x_pos + 1] = 1;
		newMatrix[y_pos + 4][x_pos + 10] = 1;
		newMatrix[y_pos + 4][x_pos + 16] = 1;
		newMatrix[y_pos + 4][x_pos + 21] = 1;
		newMatrix[y_pos + 5][x_pos + 0] = 1;
		newMatrix[y_pos + 5][x_pos + 1] = 1;
		newMatrix[y_pos + 5][x_pos + 10] = 1;
		newMatrix[y_pos + 5][x_pos + 14] = 1;
		newMatrix[y_pos + 5][x_pos + 16] = 1;
		newMatrix[y_pos + 5][x_pos + 17] = 1;
		newMatrix[y_pos + 5][x_pos + 22] = 1;
		newMatrix[y_pos + 5][x_pos + 24] = 1;
		newMatrix[y_pos + 6][x_pos + 10] = 1;
		newMatrix[y_pos + 6][x_pos + 16] = 1;
		newMatrix[y_pos + 6][x_pos + 24] = 1;
		newMatrix[y_pos + 7][x_pos + 11] = 1;
		newMatrix[y_pos + 7][x_pos + 24] = 1;
		newMatrix[y_pos + 7][x_pos + 15] = 1;
		newMatrix[y_pos + 8][x_pos + 12] = 1;
		newMatrix[y_pos + 8][x_pos + 13] = 1;
	}
}

/***************************************************
* Function: printPattern();
* Description: Displays the 2d array on the screen
* Parameters: 2d array as an int, int for # of rows, int for # of cols, 
*		int for buffer to visible world.
* Pre-Conditions: Matrix with pattern
* Post-Conditions: Printed matrix with pattern
***************************************************/

void printInitPattern(int** newMatrix, const int ROW, const int COL, int buffer){

	for (int i = buffer; i < ROW - buffer; i++){
		for (int j = buffer; j < COL - buffer; j++){
			if (newMatrix[i][j] == 0){
				cout << ".";
			}
			else{
				cout << "8";
			}
		}
		cout << "\n";
	}
}

/***************************************************
* Function: printPattern();
* Description: Prints the updated matrix on the screen
* Parameters: 2d array as an int, const int number of rows
*		const int number of cols, int buffer to visible world.
* Pre-Conditions: Matrix with pattern
* Post-Conditions: Printed matrix with pattern
***************************************************/

void printPattern(int** matrix, const int ROW, const int COL, int buffer){
	
	for (int i = buffer; i < ROW - buffer; i++){
		for (int j = buffer; j < COL - buffer; j++){
			if (matrix[i][j] == 0){
				cout << ".";
			}
			else{
				cout << "8";
			}
		}
		cout << "\n";
	}
}

/***************************************************
* Function: nextPattern();
* Description: Updates the old matrix with the most recent
*		pattern. Determines the new pattern and stores it in
*		the new matrix.
* Parameters: 2d array as an int, 2d array as an int,
*		const int # of rows, const int # of cols
* Pre-Conditions: None
* Post-Conditions: User input matrix
***************************************************/
void nextPattern(int** matrix, int** newMatrix, const int ROW, const int COL){
	
	//Update matrix with most recent pattern so that newMatrix can take on new pattern
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			matrix[i][j] = newMatrix[i][j];
		}
	}
	int neighbors = 0;
	//Loop to update cells
	for (int i = 1; i < (ROW - 1); i++){
		for (int j = 1; j < (COL - 1); j++){
		
			//Determine # of neighbors around cell
			neighbors = (matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] + matrix[i][j - 1] +
				matrix[i][j + 1] + matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1]);
			
			//Update matrix with new cell pattern. Determines new cells.
			if (neighbors == 3){
				newMatrix[i][j] = 1;
			}
			else if (neighbors == 2){
				newMatrix[i][j] = matrix[i][j];
			}
			else{
				newMatrix[i][j] = 0;
			}
			neighbors = 0;
		}
	}
}
