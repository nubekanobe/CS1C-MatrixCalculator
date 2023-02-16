#pragma once

#include <iostream> 

using namespace std; 

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private: 

	double** matrixPointer; 

	int rows; 

	int cols; 

	static const int DEFAULT_ROWS = 2; 
	
	static const int DEFAULT_COLS = 2; 


public: 


	Matrix(); 

	Matrix(int rows, int cols);

	Matrix(const Matrix& matrixToCopy); 

	~Matrix(); 


	void setElement(int row, int col, double value); 

	double getElement(int row, int col); 

	friend ostream& operator<<(ostream& out, const Matrix& matrix); 

	friend istream& operator>>(istream& in, Matrix& matrix);

	Matrix operator+(const Matrix& matrix); 

	Matrix operator-(const Matrix& matrix);


};



#endif MATRIX_H

