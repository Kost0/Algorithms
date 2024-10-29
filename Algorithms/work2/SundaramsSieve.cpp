#include <iostream>

using namespace std;

int main() {
	int numbers[100];
	for (int i = 1; i < 101; i++) {
		numbers[i - 1] = i;
	}
	int cnt = 1,j = 1;
	while (cnt + j + (2 * cnt * j) < 100) {
		while (cnt + j + (2 * cnt * j) < 100) {
			numbers[cnt + j + (2 * cnt * j) - 1] = 0;
			j++;
		}
		j = 1;
		cnt++;
	}
	for (int i = 1; i < 101; i++) {
		if (numbers[i - 1] != 0) {
			cout << numbers[i - 1] * 2 + 1 << endl;
		}
	}
	return 0;
}