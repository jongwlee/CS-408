#include <iostream>
#include <time.h>

using namespace std;

class MatrixADT
{
	double **array;
	int row, column;

public:
	MatrixADT(){}
	MatrixADT(int row, int column);
	void setValue(void);
	void print(void);
	MatrixADT operator + (MatrixADT matrix_two);
	MatrixADT operator - (MatrixADT matrix_two);
	MatrixADT operator * (MatrixADT matrix_two);
};

//Constructor
MatrixADT::MatrixADT(int r, int c){
	row = r;
	column = c;
	array = new double *[row];
	
	for (int i = 0; i < row; i++){
		array[i] = new double[column];
	}
}

//Set the values of the matrix
void MatrixADT::setValue(void){
	cout << "Enter the elements: ";
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			cin >> array[i][j];
		}
	}
}

//Adding the two matrices together
MatrixADT MatrixADT :: operator + (MatrixADT matrix_two){
	if (row != matrix_two.row || column != matrix_two.column){
		cout << "The two matrices don't match in size.";
		system("pause");
		exit(0);
	}

	MatrixADT temp(row, column);
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			temp.array[i][j] = array[i][j] + matrix_two.array[i][j];
		}
	}
	return temp;
}

//Subtract the two matrices together
MatrixADT MatrixADT :: operator - (MatrixADT matrix_two){
	if (row != matrix_two.row || column != matrix_two.column){
		cout << "The two matrices don't match in size.";
		system("pause");
		exit(0);
	}

	MatrixADT temp(row, column);
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			temp.array[i][j] = array[i][j] - matrix_two.array[i][j];
		}
	}
	return temp;
}

//Multiply the two matrices together
MatrixADT MatrixADT :: operator * (MatrixADT matrix_two){
	if (matrix_two.row != column){
		cout << "These two matrices are not compatible" << endl;
		system("pause");
		exit(0);
	}

	MatrixADT temp(row, column);
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			double total = 0.0;
			for (int k = 0; k < column; k++){
				total = total + array[i][k] * matrix_two.array[k][j];
			}
			temp.array[i][j] = total;
			//cout << "(" << i << ", " << j << ") = " << temp.array[i][j];
		}
	}
	return temp;
}

//Prints the result of the matrix
void MatrixADT::print(void){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void main(){
	MatrixADT total;
	int row_input, column_input;
	clock_t start, finish;
	start = clock();	

	cout << "Please enter the size of rows for matrix one: ";
	cin >> row_input;
	cout << "Please enter the size of columns for matrix one: ";
	cin >> column_input;

	MatrixADT matrix_one(row_input, column_input);
	matrix_one.setValue();

	cout << "Please enter the size of rows for matrix two: ";
	cin >> row_input;
	cout << "Please enter the size of columns for matrix two: ";
	cin >> column_input;

	MatrixADT matrix_two(row_input, column_input);
	matrix_two.setValue();

	//total = matrix_one + matrix_two;
	//total = matrix_one - matrix_two;
	total = matrix_one * matrix_two;
	total.print();
	
	finish = clock();

	cout << "The time is: " << ((finish - start)) << endl;
	
	system("pause");

}