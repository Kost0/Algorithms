int main() {
	int mas[8] = { 3,8,4,12,3,15,3,6 };
	int unsorted_until_r = 8 - 1;
	int unsorted_until_l = 0;
	int temp = 0;
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = unsorted_until_l; i < unsorted_until_r; i++) {
			if (mas[i] > mas[i + 1]) {
				temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = temp;
				sorted = false;
			}
		}
		unsorted_until_r--;
		for (int j = unsorted_until_r; j > unsorted_until_l; j--) {
			if (mas[j] < mas[j - 1]) {
				temp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = temp;
				sorted = false;
			}
		}
		unsorted_until_l++;
	}
	for (int i = 0; i < 8; i++) {
		std::cout << mas[i] << " ";
	}
	return 0;
}