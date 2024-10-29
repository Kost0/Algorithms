#include <iostream>

int main() {
	int mas[5] = { 3,8,4,12,3 };
	int unsorted_until_ind = 5 - 1;
	int temp = 0;
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < unsorted_until_ind; i++) {
			if (mas[i] > mas[i + 1]) {
				temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = temp;
				sorted = false;
			}
		}
		unsorted_until_ind--;
	}
	for (int i = 0; i < 5; i++) {
		std::cout << mas[i] << " ";
	}
	return 0;
}