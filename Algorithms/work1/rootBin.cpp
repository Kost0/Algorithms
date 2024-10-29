#include <iostream>

using namespace std;

int main() {
	long float A, L, R, B;
	int cnt = 0;
	A = 1;
	L = 0;
	R = A;
	B = 0;
	while (R - L > 0.0001) {
		B = (R + L) / 2;
		if ((B - (1 / (3 + sin(3.6 * B)))) > 0) {
			R = B;
		}
		else {
			L = B;
		}
		cnt++;
		cout << cnt << " " << B << "\n";
	}
	cout << B << endl;
	cout << (B - (1 / (3 + sin(3.6 * B))));
}