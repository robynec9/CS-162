/***************************************************
* Program Filename: determinant.cpp
* Author: Robyn Schroeder
* Date: 1/10/2016
* Description: Determinant function used to calculate
	determinant of matrix
* Input: Matrix size, integers
* Output: Determinant
***************************************************/

#include <iostream>
#include <string>
#include "readMatrix.hpp"
#include "determinant.hpp"

using namespace std;

int determinant(int** matrix, int size){

	int detm_calc;	//Determinant calculation variable

	//Determine which formula to use - 2x2 or 3x3 matrix.
	if (size == 2){				//2x2 case
		int a = matrix[0][0];
		int b = matrix[0][1];
		int	c = matrix[1][0];
		int d = matrix[1][1];

	detm_calc = (a*d) - (b*c);

	}

	else{						//3x3 case
		int a = matrix[0][0];
		int b = matrix[0][1];
		int	c = matrix[0][2];
		int d = matrix[1][0]; 
		int e = matrix[1][1];
		int f = matrix[1][2];
		int	g = matrix[2][0];
		int h = matrix[2][1];	
		int i = matrix[2][2];

		detm_calc = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
	}
	return detm_calc;
}