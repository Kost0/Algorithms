#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int len1,len2, max_len;
	string first, second;
	cout << "Первое число: ";
	cin >> first;
	cout << "Второе число: ";
	cin >> second;
	len1 = first.length();
	len2 = second.length();
	max_len = max(len1, len2) + 1;
	int* f_num = new int[max_len] {0};
	int* s_num = new int[max_len] {0};
	for (int i = 0; i < max_len; i++)
		f_num[i + 1 + (max_len - len1 - 1)] = first[i] - '0';
	for (int i = 0; i < len2; i++)
		s_num[i + 1 + (max_len - len2 - 1)] = second[i] - '0';
	bool all_r = false;
	int* third = new int[max_len] {0};
	while (!all_r) {
		for (int i = max_len - 1; i >= 0; i--) {
			if (f_num[i] + s_num[i] >= 10) {
				third[i - 1] = 1;
			}
			f_num[i] = (f_num[i] + s_num[i]) % 10;
		}
		for (int i = 0; i < max_len; i++) {
			s_num[i] = third[i];
			third[i] = 0;
		}
		all_r = true;
		for (int i = 0; i < max_len; i++) {
			if (s_num[i] > 0) {
				all_r = false;
				break;
			}
		}
	}
	for (int i = 0; i < max_len; i++) {
		cout << f_num[i];
	}
	return 0;
}