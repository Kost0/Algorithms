#include <iostream>
#include <vector>

using namespace std;

int func(vector<int>& spisok , int key);

int main() {
	setlocale(LC_ALL, "Russian");

	vector<int> spisok = { 1, 3, 5, 6, 7, 8, 9, 12 };
	int key;
	cin >> key;
	int res = func(spisok, key);
	if (res >= 0) {
		cout << res;
	}
	else {
		res += 1;
		res *= -1;
		spisok.insert(spisok.begin() + res, key);

		for (int i = 0; i < spisok.size(); i++) {
			cout << spisok[i] << " ";

		}
	}
	return 0;
}

int func(vector<int>& spisok, int key) {
	int low = 0;
	int high = spisok.size();
	int mid;
	int midVal;

	while (low <= high) {
		mid = (low + high) / 2;
		midVal = spisok[mid];
		if (midVal == key) {
			return mid;
		}
		else if (midVal > key){
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return (-1 * mid) - 1;
}