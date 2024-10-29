#include <iostream>

using namespace std;

int main() {
	int n, mercen_num;
	cin >> n;
	mercen_num = pow(2, n) - 1;
	int s = 4, k = 1;
	while (k != (n - 1)) {
		s = ((s * s) - 2) % mercen_num;
		k += 1;
	}
	if (s == 0)
		cout << "Number is prime";
	else
		cout << "Number isn't prime";
	return 0;
}
