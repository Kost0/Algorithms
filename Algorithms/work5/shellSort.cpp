#include <iostream>

int main() {
	int mas[10] = { 7,1,4,2,7,3,9,23,4,5 };
	int temp, cur_num,d = 10 / 2;
	while (d != 0) {
		for (int i = d; i < 10 ; i++) {
			temp = mas[i];
			cur_num = i - d;
			while (cur_num >= 0) {
				if (mas[cur_num] > temp) {
					mas[cur_num + d] = mas[cur_num];
					cur_num--;
				}
				else
					break;
			}
			mas[cur_num + 1] = temp;
		}
		d /= 2;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << " ";
	}
	return 0;
}