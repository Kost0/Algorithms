#include <iostream>
#include <string>

using namespace std;

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
	return 0;
}