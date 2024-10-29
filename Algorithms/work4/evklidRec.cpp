#include <iostream>

int evklid(int a, int b);

int main() {
	int a, b;
	std::cin >> a >> b;
	if (a == 0)
		std::cout << b;
	else if (b == 0)
		std::cout << a;
	else{
		if (a < 0)
			a *= -1;
		if (b < 0)
			b *= -1;
		std::cout << evklid(a, b);
	}
	return 0;
}

int evklid(int a, int b) {
	if (a > b) 
		return evklid(a - b, b);
	else if (b > a)
		return evklid(a, b - a);
	else 
		return a;
}