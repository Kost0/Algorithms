#include <iostream>

int fib(int n);

int main() {
	int n;
	std::cin >> n;
	std::cout << fib(n);
}

int fib(int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}