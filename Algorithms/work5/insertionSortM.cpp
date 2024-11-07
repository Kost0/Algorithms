#include <iostream>

int main() {
	int mas[10] = { 7,1,4,2,7,3,9,23,4,5 };
	int temp, cur_num;
	for (int i = 1; i < 10; i++) {
		temp = mas[i];
		cur_num = i / 2;
		while (temp < mas[cur_num] || temp > mas[cur_num + 1]) {
			if (temp > mas[cur_num + 1]) {
				cur_num += cur_num / 2;
			}
			else if (temp < mas[cur_num]) {
				cur_num /= 2;
			}
			if (cur_num == 0) {
				if (temp >= mas[cur_num]) {
					break;
				}
				else {
					cur_num--;
					break;
				}
			}
		}
		for (int j = i; j > cur_num + 1; j--) {
			mas[j] = mas[j - 1];
		}
		mas[cur_num + 1] = temp;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << " ";
	}
	return 0;
}