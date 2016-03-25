/***************************************************
* Program Filename: readMatrix.cpp
* Author: Robyn Schroeder
* Date: 1/10/2016
* Description: readMatrix function. Used to build
	matrix.
* Input: Matrix size, integers
* Output: None
***************************************************/

#include <iostream>
#include <string>
#include "readMatrix.hpp"
#include "determinant.hpp"

using namespace std;


/***************************************************
* Function: readMatrix();
* Description: Prompts user for integers in matrix
* Parameters: 2d array as an int, size of matrix as an int
* Pre-Conditions: None
* Post-Conditions: User input matrix
***************************************************/

void readMatrix(int** matrix, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << "Please enter the integer for row " << i+1 << " column " << j+1 << ":\t";
			cin >> matrix[i][j];
		}
		cout << "\n";
	}
}
	