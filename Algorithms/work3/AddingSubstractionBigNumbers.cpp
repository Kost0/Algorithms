#include <iostream>

using namespace std;

int main() {
	setlocale (LC_ALL,"ru");
	int len,num,sym, new_raz = 0;
	cout << "Введите длину чисел: ";
	cin >> len;
	int* first = new int[len];
	int* second = new int[len];
	char sign;
	char c = getchar();
	cout << "Первое число: ";
	for (int i = 0; i < len; i++) {
		sym = getchar();
		num = sym - '0';
		first[i] = num;
	}
	char d = getchar();
	cout << "Действие('+' или '-'): ";
	cin >> sign;
	char e = getchar();
	cout << "Второе чилсо: ";
	for (int i = 0; i < len; i++) {
		sym = getchar();
		num = sym - '0';
		second[i] = num;
	}

	if (sign == '-'){
		bool biger = true;
		for (int i = 0; i < len; i++) {
			if (first[i] < second[i])
				break;
			else if (first[i] > second[i]) {
				biger = false;
				break;
			}
			if (i == len - 1) {
				cout << 0;
			}
		}
		if (biger == true) {
			for (int i = len - 1; i >= 0; i--) {
				second[i] -= first[i];
				if (second[i] < 0) {
					second[i - 1] -= 1;
					second[i] += 10;
				}
			}
			for (int i = 0; i < len; i++) {
				cout << second[i];
			}
		}
		else {
			for (int i = len - 1; i >= 0; i--) {
				first[i] = first[i] -  second[i];
				if (first[i] < 0) {
					first[i - 1] -= 1;
					first[i] += 10;
				}
			}
			for (int i = 0; i < len; i++) {
				cout << first[i];
			}
		}
	}
	if (sign == '+') {
		for (int i = len - 1; i >= 0; i--) {
			first[i] += second[i];			
			if (first[i] > 9) {
				first[i] = first[i] % 10;
				if (i == 0) {
					new_raz = 1;
				}
				else {
					second[i - 1]++;
				}
			}
		}
		if (new_raz) {
			cout << new_raz;
			for (int i = 0; i < len; i++) {
				cout << first[i];
			}
		}
		else {
			for (int i = 0; i < len; i++) {
				cout << first[i];
			}
		}
	}
	return 0;
}