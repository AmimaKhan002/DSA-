//contains 2D to 1D mapping
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Matrix{
	int *matrix;
	int rows;
	int cols;
	public:
		Matrix(int rows=3,int cols=3){
			this->rows=rows;
			this->cols=cols;
			matrix = new int [cols * rows];
			for(int i=0;i<(cols*rows);i++){
				matrix[i] = rand() %  10;
			}
		}
		
		int get(int i,int j){
			if(i<rows && j<cols){
				return matrix[i*cols+j];
			}
			else{
				cout << "WRONG INDEX PROVIDED TO GET VALUE\n";
				return -1;
			}
		}
		
		void set(int i,int j,int v){
			if(i<rows && j<cols){
				matrix[i*cols+j] = v;
			}
			else
				cout << "WRONG INDEX PROVIDED TO SET VALUE\n";
		}
		
		void print(void){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					cout << matrix[i*cols+j] << ' ';
				cout << '\n';
			}
		}
		
		void transpose(){
			for(int i=0;i<cols;i++){
				for(int j=0;j<rows;j++)
					cout << matrix[j*cols+i] << ' ';
				cout << '\n';
			}
		}
		
		void printSubMatrix(int r1,int r2,int c1,int c2){
			if(r1<=rows && r2<=rows && c1<=cols && c2<=cols){
				for(int i=r1-1;i<r2;i++){
					for(int j=c1-1;j<c2;j++)
						cout << matrix[i*cols+j] << ' ';
					cout << '\n';
				}
			}
			else
				cout << "WRONG INDEXES PROVIDED\n";
		}
		
		void makeEmpty(int n){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					set(i,j,0);
			}
		}
		
		void add(Matrix first, Matrix second){
			if(first.rows==second.rows && first.cols==second.cols){
				if(first.rows!=rows || first.cols!=cols){
					delete [] matrix;
					this->rows=first.rows;
					this->cols=first.cols;
					matrix = new int [rows*cols];
				}
				for(int i=0;i<rows;i++){
					for(int j=0;j<cols;j++)
						matrix[i*cols+j] = first.matrix[i*cols+j] + second.matrix[i*cols+j];
				}	
			}
			else
				cout << "DIMENSIONS OF BOTH MATRICES YOU PASSED AS ARGUMENT ARE NOT SAME\n";
		}
		
		~Matrix(){
			delete [] matrix;
			matrix = 0;
		}
};

int main(){
	srand(time(0));
	Matrix A(3,4);
	A.print();
	cout << "---------------------\n";
	cout <<  A.get(2,1);
	cout << "\n---------------------\n";
	A.set(2,1,10);
	A.print();
	cout << "---------------------\n";
	A.transpose();
	cout << "---------------------\n";
	A.printSubMatrix(1,2,2,3);
	cout << "---------------------\n";
	A.makeEmpty(2);
	A.print();
	cout << "---------------------\n";
	Matrix B(3,4);
	B.print();
	cout << "---------------------\n";
	Matrix C;
	C.print();
	cout << "---------------------\n";
	C.add(A,B);
	C.print();
}