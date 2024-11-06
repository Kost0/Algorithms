#include <iostream>

int summa(int a);

int main() {
	int a;
	std::cin >> a;
	std::cout << summa(a);
	return 0;
}

int summa(int a) {
	if (a % 10 == a)
		return a;
	else
		return a % 10 + summa(a / 10);