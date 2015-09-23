#include <iostream>
#include <time.h>

using namespace std;

//Function to add the two arrays
void addition(double array_one[][5], double array_two[][5]){
	if (sizeof(array_one) != sizeof(array_two) || sizeof(array_one[0]) != sizeof(array_two[0])){
		cout << "The two matrices don't match in size." << endl;
		system("exit");
	}
	double total_array[5][5];
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			total_array[i][j] = array_one[i][j] + array_two[i][j];
			cout << "(" << i << ", " << j << ") = " << total_array[i][j] << endl;
		}
	}
}

//Function to subtract the two arrays
void subtraction(double array_one[][5], double array_two[][5]){
	if (sizeof(array_one) != sizeof(array_two) || sizeof(array_one[0]) != sizeof(array_two[0])){
		cout << "The two matrices don't match in size." << endl;
		system("exit");
	}
	double total_array[5][5];
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			total_array[i][j] = array_one[i][j] - array_two[i][j];
			cout << "(" << i << ", " << j << ") = " << total_array[i][j] << endl;
		}
	}
}

//Function to multiply the two 
void multiplication(double array_one[][5], double array_two[][5]){
	if (sizeof(array_two) != sizeof(array_one[0])){
		cout << "The two matrices don't match in size." << endl;
		system("exit");
	}

	double total_array[5][5];
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			double total = 0.0;
			for (int k = 0; k < 5; k++){
				total = total + array_one[i][k] * array_two[k][j];
			}
			total_array[i][j] = total;
			cout << "(" << i << ", " << j << ") = " << total_array[i][j] << endl;
		}
	}

}

int main(){
	clock_t start, finish;
	
	start = clock();	

	const int MAX = 5;
	double array_one[MAX][MAX] = { 1.0, 2.0, 3.0, 4.0, 5.0, 2.0, 2.0, 2.0, 2.0, 2.0, 3.0, 1.0, 1.0, 1.0, 3.0,
		0.0, 0.0, 2.0, 3.0, -2.0, 4.0, 4.0, -4.0, 0.0, 0.0 };
	double array_two[MAX][MAX] = { 1.0, 0.0, 0.0, 0.0, 0.0,
		1.0, 2.0, 1.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, -2.0, 2.0, 2.0 };

	//addition(array_one, array_two);
	//subtraction(array_one, array_two);
	multiplication(array_one, array_two);
	finish = clock();

	cout << "The time is: " << ((finish - start)) << endl;
	system("pause");

}