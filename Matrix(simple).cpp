#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

const int N = 2048;
volatile int A[N][N];
volatile int B[N][N];
volatile int C[N][N];

int main() {
 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			A[i][j] = B[i][j] = 1;
			C[i][j] = 0;
		}
	}
		
	cout << "Matrix size: " << N << "x" << N << endl;

	clock_t start, finish;
	start = clock();

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];

	finish = clock();
	cout << "Multiplication (simple): " << (double)(finish - start) / CLOCKS_PER_SEC << "sec \n";
	return 0;
}
