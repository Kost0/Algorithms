#include <iostream>
#include <string>

using namespace std;

void karatsuba(int* x, int* y, int*& result, int n);

int main() {
	setlocale(LC_ALL, "ru");
	int len1, len2;
	string first, second;
	cout << "Первое число: ";
	cin >> first;
	cout << "Второе число: ";
	cin >> second;
	bool minus1 = false, minus2 = false;
	if (first[0] == '-') {
		first.erase(0, 1);
		minus1 = true;
	}
	if (second[0] == '-') {
		minus2 = true;
		second.erase(0, 1);
	}
	minus1 ^= minus2;
	len1 = first.length();
	len2 = second.length();
	int* f_num = new int[len1] {0};
	int* s_num = new int[len2] {0};
	for (int i = 0; i < len1; i++) {
		f_num[i] = first[i] - '0';
	}
	for (int i = 0; i < len2; i++)
		s_num[i] = second[i] - '0';
	int* pro = new int[len1 + len2] {0};
	for (int i = len1 - 1; i >= 0; i--) {
		for (int j = len2 - 1; j >= 0; j--) {
			pro[i + j + 1] += (f_num[i] * s_num[j]) % 10;
			if (pro[i + j + 1] >= 10) {
				pro[i + j] += pro[i + j + 1] / 10;
				pro[i + j + 1] %= 10;
			}
			pro[i + j] += (f_num[i] * s_num[j]) / 10;
			if (pro[i + j] >= 10) {
				pro[i + j - 1] += pro[i + j] / 10;
				pro[i + j] %= 10;
			}
		}
	}
	if (minus1)
		cout << '-';
	bool was_norm = false;
	for (int i = 0; i < len1 + len2; i++) {
		if (was_norm)
			cout << pro[i];
		else {
			if (pro[i] != 0) {
				std::cout << pro[i];
				was_norm = true;
			}
		}
	}
	int* result = new int[len1 + len2] {0};
	karatsuba(f_num, s_num, result, max(len1, len2));
	cout << "\n";
	for (int i = 0; i < len1 + len2; i++) {
		cout << result[i] << " ";
	}
	return 0;
}

void karatsuba(int* x, int* y, int*& result, int n) {


	if (n == 1) {
		if (x[0] * y[0] >= 10) {
			result[0] = x[0] * y[0] / 10;
			result[1] = x[0] * y[0] % 10;
		}
		else {
			result[0] += x[0] * y[0];
		}
		return;
	}
	int half = n / 2;

	// Разделяем числа на две половины
	int* x1 = new int[half];
	int* x0 = new int[half];
	int* y1 = new int[half];
	int* y0 = new int[half];

	for (int i = 0; i < half; i++) {
		x1[i] = x[i + half];
		x0[i] = x[i];
		y1[i] = y[i + half];
		y0[i] = y[i];
	}
	// Рекурсивные вызовы
	int* z0 = new int[n] {0};
	int* z1 = new int[n] {0};
	int* z2 = new int[n] {0};

	karatsuba(x0, y0, z0, half);
	karatsuba(x1, y1, z2, half);

	// Сложение
	for (int i = 0; i < half; i++) {
		x0[i] += x1[i];
		y0[i] += y1[i];
	}

	karatsuba(x0, y0, z1, half);

	// Считаем результат
	for (int i = 0; i < 2 * n; i++) {
		result[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		result[i] += z0[i];
	}

	for (int i = 0; i < n; i++) {
		result[i + half] += z1[i] - z0[i] - z2[i];
	}

	for (int i = 0; i < n; i++) {
		result[i + half * 2] += z2[i];
	}
}