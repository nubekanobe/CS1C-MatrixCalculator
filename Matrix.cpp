#include "Matrix.h"



Matrix::Matrix() :Matrix(DEFAULT_ROWS, DEFAULT_COLS) {
}


Matrix::Matrix(int rows, int cols) {

	this->rows = rows; 

	this->cols = cols; 

	matrixPointer = new double* [rows];


	for (int i = 0; i < rows; i++) {

		matrixPointer[i] = new double[cols];

	}


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
		matrixPointer[i][j] = 0; 
		}

	}

}

Matrix::Matrix(const Matrix& matrixToCopy) {

	rows = matrixToCopy.rows;

	cols = matrixToCopy.cols;

	
	matrixPointer = new double* [rows]; 

	for (int i = 0; i < rows; i++) {

		matrixPointer[i] = new double[cols];

	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrixPointer[i][j] = matrixToCopy.matrixPointer[i][j]; 
		}

	}

}



Matrix::~Matrix() {

	for (int i = 0; i < rows; i++) {

		delete [] matrixPointer[i]; 

	}

	delete[] matrixPointer; 

	cout << endl << "A matrix has been destroyed." << endl;
}



void Matrix::setElement(int row, int col, double value) {

	if (row < rows && col < cols)
	matrixPointer[row][col] = value; 
}


double Matrix::getElement(int row, int col) {

	return matrixPointer[row][col]; 
}



ostream& operator<<(ostream& out, const Matrix& matrix) {


	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.cols; j++)
		{
			out << matrix.matrixPointer[i][j] << "\t";
		}

		out << endl; 
	}

	return out; 
}



istream& operator>>(istream& in, Matrix& matrix) {


	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.cols; j++)
		{
			in >> matrix.matrixPointer[i][j];
		}

	}

	return in;
}



Matrix Matrix::operator+(const Matrix& matrix) {



	if (rows != matrix.rows || cols != matrix.cols) {
		cout << "Matrix sizes do not match."; 
		
		Matrix dummyMatrix; 

		return dummyMatrix; 

	}

	Matrix sumMatrix(rows, cols); 


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sumMatrix.matrixPointer[i][j] = matrixPointer[i][j] + matrix.matrixPointer[i][j];
		}

	}

	return sumMatrix; 

}


Matrix Matrix::operator-(const Matrix& matrix) {



	if (rows != matrix.rows || cols != matrix.cols) {
		cout << "Matrix sizes do not match.";

		Matrix dummyMatrix;

		return dummyMatrix;

	}

	Matrix diffMatrix(rows, cols);


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			diffMatrix.matrixPointer[i][j] = matrixPointer[i][j] - matrix.matrixPointer[i][j];
		}

	}

	return diffMatrix;

}