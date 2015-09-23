#include <iostream>
#include <time.h>

using namespace std;

//Function to set the values for the matrices
void setValue(double **array, int row, int column){
	int temp;
	cout << "Enter the elements: ";
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			cin >> array[i][j];
		}
	}
}

//Function to add the two matrices and return the total
double** addition(double **array_one, double **array_two, int row, int column, int row2, int column2){
	if (row != row2 || column != column2){
		cout << "The two matrices don't match in size.";
		system("pause");
		exit(0);
	}
	double **total;

	total = new double *[row];

	for (int i = 0; i < row; i++){
		total[i] = new double[column];
	}

	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			total[i][j] = array_one[i][j] + array_two[i][j];
			cout << total[i][j] << " ";
		}
	}
	return total;
}

//Function to subtract the two matrices and return the total
double** subtraction(double **array_one, double **array_two, int row, int column, int row2, int column2){
	if (row != row2 || column != column2){
		cout << "The two matrices don't match in size.";
		system("pause");
		exit(0);
	}
	double **total;

	total = new double *[row];

	for (int i = 0; i < row; i++){
		total[i] = new double[column];
	}

	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			total[i][j] = array_one[i][j] - array_two[i][j];
			cout << total[i][j] << " ";
		}
	}
	return total;
}

//Function to multiply the two matrices and return the total
double** multiplication(double **array_one, double **array_two, int row, int column, int row2, int column2){
	if (row2 != column){
		cout << "The two matrices don't match in size.";
		system("pause");
		exit(0);
	}
	double **total;

	total = new double *[row];

	for (int i = 0; i < row; i++){
		total[i] = new double[column];
	}

	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			double result = 0.0;
			for (int k = 0; k < column; k++){
				result = result + array_one[i][k] * array_two[k][j];
			}
			total[i][j] = result;
			cout << total[i][j] << " ";
		}
	}
	return total;
}



int main(){
	double **array_one, **array_two, **total;
	int row, column, row2, column2;
	clock_t start, finish;
	
	start = clock();
	cout << "Please enter the size of rows for matrix one: ";
	cin >> row;
	cout << "Please enter the size of columns for matrix one: ";
	cin >> column;

	array_one = new double *[row];

	for (int i = 0; i < row; i++){
		array_one[i] = new double[column];
	}

	setValue(array_one, row, column);



	cout << "Please enter the size of rows for matrix two: ";
	cin >> row2;
	cout << "Please enter the size of columns for matrix two: ";
	cin >> column2;

	array_two = new double *[row2];

	for (int i = 0; i < row; i++){
		array_two[i] = new double[column2];
	}

	setValue(array_two, row2, column2);
	//addition(array_one, array_two, row, column, row2, column2);
	//multiplication(array_one, array_two, row, column, row2, column2);
	subtraction(array_one, array_two, row, column, row2, column2);
	finish = clock();

	cout << "The time is: " << ((finish - start)) << endl;

	system("pause");
}