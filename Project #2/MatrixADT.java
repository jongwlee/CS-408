import java.util.Scanner;


public class MatrixADT {
	private double[][] array;
	private int rows;
	private int columns;
	
	//Constructor takes in rows and columns
	public MatrixADT(int rows, int columns){
		this.rows = rows;
		this.columns = columns;
		
		if (rows <= 0 && columns <= 0){
			System.out.println("This is a not a valid length");
		}
		else{
			array = new double[rows][columns];
		}
	}
	
	//Set the elements of the array
	public MatrixADT setValue(int rows, int columns, double value){
		rows = rowIndex(rows);
		columns = columnIndex(columns);
		array[rows][columns] = value;
	    return this;
	}
	
	//Getter for rows
	public int getRows() {
		return rows;
	}

	//Getter for columns
	public int getColumns() {
		return columns;
	}

	//Gets the element of the array at the specified row and column
	public double getValue(int rows, int columns){
		rows = rowIndex(rows);
		columns = columnIndex(columns);
		return array[rows][columns];
	}
	
	//Finds the index of the row
	private int rowIndex(int rows){
		if (rows < 1 || rows > this.rows){
			System.out.println("Cannot do this because the rows out of range");
		}
		return rows - 1;
	}
	
	//Find the index of the column
	private int columnIndex(int columns){
		if (columns < 1 || columns > this.columns){
			System.out.println("Cannot do this because the columns is out of range");
		}
		
		return columns - 1;
	}
	
	// Addition between two matrices. If the size does not match, prompts a message to tell user
	public MatrixADT addition(MatrixADT matrix){
		if (rows != matrix.getRows() || columns != matrix.getColumns()){
			System.out.println("The two matrices don't match in size.");
			System.exit(0);
		}
		
		MatrixADT total = new MatrixADT(rows, columns);
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < columns; j++){
				total.array[i][j] = array[i][j] + matrix.array[i][j];
				System.out.println("(" + i + ", " + j + ") = " + total.array[i][j]);
			}
		}
		return total;
	}
	
	// Subtraction between the two matrices
	public MatrixADT subtraction(MatrixADT matrix){
		if (rows != matrix.getRows() || columns != matrix.getColumns()){
			System.out.println("The two matrices don't match in size.");
			System.exit(0);
		}
		
		MatrixADT total = new MatrixADT(rows, columns);
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < columns; j++){
				total.array[i][j] = array[i][j] - matrix.array[i][j];
				System.out.println("(" + i + ", " + j + ") = " + total.array[i][j]);
			}
		}
		return total;
	}
	
	/* Multiplication of the two matrices. Checks to see if the row of the second matrix
	   and column of the first matrix are equal to each other. If they are, we create a new
	   matrix of size [row] for first matrix and size [column] of the second matrix. Do our
	   calculations then we store the result into that position.
	*/
	public MatrixADT multiplication(MatrixADT matrix){
		
		if (matrix.getRows() != columns){
			System.out.println("These two matrices are not compatible");
			System.exit(0);
		}
		
		MatrixADT result = new MatrixADT(rows, matrix.getColumns());
		for (int i = 0; i < result.getRows(); i++){
			for (int j = 0; j < result.getColumns(); j++){
				double total = 0.0;
				for (int k = 0; k < getColumns(); k++){
					total = total + array[i][k] * matrix.array[k][j];
				}
				result.array[i][j] = total;
				System.out.println("(" + i + ", " + j + ") = " + result.array[i][j]);
			}
		}
		return result;
	}
	
	
	
	public static void main(String[] args){
		int matrix_one_rows, matrix_one_columns, matrix_one_values, matrix_two_rows, matrix_two_columns,
		matrix_two_values = 0;
		long start, stop, end;
		Scanner scanner = new Scanner(System.in);
		
		/*
		System.out.println("Please enter the row size of matrix 1: ");
		matrix_one_rows = scanner.nextInt();
		System.out.println("Please enter the column size of matrix 1: ");
		matrix_one_columns = scanner.nextInt();
		
		MatrixADT matrix_one = new MatrixADT(matrix_one_rows, matrix_one_columns);
		
		System.out.println("Please enter the row size of matrix 2: ");
		matrix_two_rows = scanner.nextInt();
		System.out.println("Please enter the column size of matrix 2: ");
		matrix_two_columns = scanner.nextInt();
		
		MatrixADT matrix_two = new MatrixADT(matrix_two_rows, matrix_two_columns);
		
		start = System.currentTimeMillis();
		for (int i = 1; i <= matrix_one_rows; i++){
			for (int j = 1; j <= matrix_one_columns; j++){
				System.out.println("Please enter the values to be put into the matrix one");
				matrix_one_values = scanner.nextInt();
				matrix_one.setValue(i, j, matrix_one_values);
			}
		}
		
		for (int i = 1; i <= matrix_two_rows; i++){
			for (int j = 1; j <= matrix_two_columns; j++){
				System.out.println("Please enter the values to be put into the matrix two");
				matrix_two_values = scanner.nextInt();
				matrix_two.setValue(i, j, matrix_two_values);
			}
		}
		*/
		start = System.currentTimeMillis();
		System.out.println("Please enter the row size of matrix 1: ");
		matrix_one_rows = scanner.nextInt();
		System.out.println("Please enter the column size of matrix 1: ");
		matrix_one_columns = scanner.nextInt();
		
		MatrixADT matrix_one = new MatrixADT(matrix_one_rows, matrix_one_columns);
		
		for (int i = 1; i <= matrix_one_rows; i++){
			for (int j = 1; j <= matrix_one_columns; j++){
				matrix_one.setValue(i, j, i+j);
			}
		}
		
		System.out.println("Please enter the row size of matrix 2: ");
		matrix_two_rows = scanner.nextInt();
		System.out.println("Please enter the column size of matrix 2: ");
		matrix_two_columns = scanner.nextInt();
		
		MatrixADT matrix_two = new MatrixADT(matrix_two_rows, matrix_two_columns);
		
		for (int i = 1; i <= matrix_two_rows; i++){
			for (int j = 1; j <= matrix_two_columns; j++){
				matrix_two.setValue(i, j, i-j);
			}
		}
		
		
		
		matrix_one.multiplication(matrix_two);
		stop = System.currentTimeMillis();
		
		end = stop - start;
		System.out.println("The time is: " + end);
		//matrix_one.addition(matrix_two);
		

	}
}


