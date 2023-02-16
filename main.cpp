#include "Matrix.h"


int main() {

	Matrix m1; // creates a 2x2 matrix

	cin >> m1; // user assigns values to m1

	Matrix m2(m1); // creates copy of m1 

	cout << endl; 

	cout << m1 << endl << m2 << endl; // print original and copy

	Matrix m3 = m2 + m1; // add matrices and store in a new matrix m3

	cout << m3 << endl; // print m3 result

	Matrix m4 = m2 - m1;  // substract matrices and store in a new matrix m4

	cout << m4 << endl; // print m4 result

	return 0; 
}