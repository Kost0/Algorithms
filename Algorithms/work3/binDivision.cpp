#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	int a, b, hod;
	std::cout << "������� �������:";
	std::cin >> a;
	std::cout << "������� ��������:";
	std::cin >> b;
	while (b == 0) {
		std::cout << "�� ���� ������ ������, ������� ������ �����: ";
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
	std::cout << "�������: " << p << "\n";
	std::cout << "�������: " << a - b * p;
	return 0;
}