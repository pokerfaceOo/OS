#include <iostream>
#include <cmath>
using namespace std;

extern "C" {
	void asinb (double, int);
	void printNumber(double a) {
	          cout << a;
	}
}

int main() {
	asinb(M_PI / 2, 3); // 3 * sin (PI / 2)
   	return 0;
}
