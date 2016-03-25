/***************************************************
* Program Filename: main.cpp 
* Author: Robyn Schroeder
* Date: 1/10/2016
* Description: This is the main file for the matrix/determinant lab.
*	The purpose of this program is to prompt a user for the size of
*	matrix to be calculated. The program will ask the user for each 
*	integer in the matrix, then display the matrix and determinant.
* Input: Matrix size, integers
* Output: Determinant
***************************************************/

#include <iostream>
#include <string>
#include "readMatrix.hpp"

using namespace std;

int main(){

	//Prompt the user for the size of matrix to be calculated.
	cout << "Welcome to the matrix determinant calculator!\n" << endl;
	cout << "Please select the matrix size you would like to input: " << endl;
	cout << "\t (A): 2x2 matrix" << endl;
	cout << "\t (B): 3x3 matrix\n" << endl;

	char selection;		//Stores matrix size selection
	cin >> selection;

	int size;	//Size of matrix

	//Uses selection from user to determine value to assign to 'size'
	if (selection == 'A' || selection == 'a'){
		size = 2;
	}
	else if (selection == 'B' || selection == 'b'){
		size = 3;
	}
	else{
		cout << "Your selection is invalid. Please start over." << endl;
		return 0;
	}

	cout << "\nYou have selected a " << size << "x" << size << " matrix.\n" << endl;

	//Initialize pointer array
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++){
		matrix[i] = new int[size];
	}
	
	readMatrix(matrix, size);	//Sets up matrix by taking input from user
	int calc = determinant(matrix, size);	//Calculates determinant

	cout << "The " << size << "x" << size << " matrix is: " << endl;

	//Displays the matrix on the console
	for (int row = 0; row < size; row++){
		for (int col = 0; col < size; col++){
			cout << matrix[row][col] << "\t";
		}
		cout << "\n";
	} 
	
	//Deletes stored data 
	for (int i = 0; i < size; i++){
		delete[] matrix[i];
	}
		delete[] matrix;
	
	cout << "\nThe determinant of the matrix is: " << calc << endl;
	
	return 0;
}