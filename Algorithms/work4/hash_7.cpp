#include <iostream>

using namespace std;

int main() {
	int mas[7] = { 86, 90, 27, 29, 38, 30, 40 };
	int hash[7]{ 0 };
	int ind;
	for (int i = 0; i < 7; i++) {
		ind = mas[i] % 7;
		if (hash[ind] == 0) {
			hash[ind] = mas[i];
		}
		else {
			while (hash[ind] != 0) {
				if (ind == 6) {
					ind = 0;
				}
				else {
					ind++;
				}
			}
			hash[ind] = mas[i];
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << hash[i] << " ";
	}
}