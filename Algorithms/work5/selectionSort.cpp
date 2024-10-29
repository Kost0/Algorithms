#include <iostream>

int main() {
	int mas[10] = { 4,1,6,2,8,1,8,12,87,12 };
	int lowest_num, temp;
	for (int i = 0; i < 9; i++) {
		lowest_num = i;
		for (int j = i + 1; j < 10; j++) {
			if (mas[j] < mas[lowest_num]) {
				lowest_num = j;
			}
		}
		if (lowest_num != i) {
			temp = mas[i];
			mas[i] = mas[lowest_num];
			mas[lowest_num] = temp;
		}
	}
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << " ";
	}
}
