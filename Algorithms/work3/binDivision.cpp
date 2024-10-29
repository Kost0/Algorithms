#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	int a, b, hod;
	std::cout << "Введите делимое:";
	std::cin >> a;
	std::cout << "Введите делитель:";
	std::cin >> b;
	while (b == 0) {
		std::cout << "На ноль делить нельзя, введите другое число: ";
		std::cin >> b;
	}
	int p = a / 2;
	while ((a - b * p) >= b || (a - b * p) < 0) {
		hod = p /2;
		if ((a - b * p) < 0) {
			p -= hod;
		}
		else {
			p += hod;
		}
	}
	std::cout << "Частное: " << p << "\n";
	std::cout << "Остаток: " << a - b * p;
	return 0;
}