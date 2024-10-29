#include <iostream>

int main() {
	int mas[10] = { 7,1,4,2,7,3,9,23,4,5 };
	int temp, cur_num;
	for (int i = 1; i < 10; i++) {
		temp = mas[i];
		cur_num = i - 1;
		while (cur_num >= 0){
			if (mas[cur_num] > temp) {
				mas[cur_num + 1] = mas[cur_num];
				cur_num--;
			}
			else
				break;
		}
		mas[cur_num + 1] = temp;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << " ";
	}
	return 0;
}