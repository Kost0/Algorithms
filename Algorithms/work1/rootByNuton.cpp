#include <iostream>

using std::cout;

float func(double a);

int main() {
	double L, R, B, C;
	int cnt = 0;
	L = 0;
	R = 1;
	B = 0;
	C = 10;
	while (abs(C - L) > 0.0001) {
		B = R - ((func(R) * (L - R)) / (func(L) - func(R)));
		C = L;
		L = B;
		cnt++;
		cout << cnt << " " << B << "\n";
	}
	cout << B << "\n";
	cout << func(B);
}

float func(double a) {
	return (a - (1 / (3 + sin(3.6 * a))));
}