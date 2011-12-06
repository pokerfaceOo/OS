#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

const int N = 2048;
volatile int A[N * N];
volatile int B[N * N];
volatile int C[N * N];

int main() {
    int b = 32;
    int tileSize = b * b;
    int tileCount = N / b;
     
    for(int i = 0; i < N * N; i++) {
		A[i] = B[i] = 1;
		C[i] = 0;
	}
    int tmp = tileCount * tileSize;
  
      
    cout << "Matrix size: " << N << "x" << N << endl;  
	clock_t start, finish;
	start = clock();
	
    for(int i = 0; i < N; ++i) {
            int posi = (i / b) * tmp + b * (i % b);
            for(int j = 0; j < N; ++j) {
                    int posj = (j / b) * tileSize + j % b;
                    int pos = posi + posj;
                    for(int k = 0; k < N; ++k) 
                            C[pos] +=
                                 A[posi + (k / b) * tileSize + k % b]
                                      * B[(k / b) * tmp + b * (k % b) + posj];
            }
    }
    
   	finish = clock();
	cout << "Multiplication (tiling): " << (double)(finish - start) / CLOCKS_PER_SEC << "sec \n";

    return 0;
}
