#include <iostream>
#include <vector>

using namespace std;

int func(vector<int>& spis);

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> spis {1,1,1,1,1,1};
	int a = func(spis);
	if (a > 0)
		cout << a;
	else
		cout << "Массив не горный";
	return 0;
}

int func(vector<int>&spis) {
	if (spis.size() <= 3)
		return -1;
	int low = 0;
	int high = spis.size();
	int mid = -1;
	int midVal;
	while (low != high) {
		mid = (low + high) / 2;
		midVal = spis[mid];
		if (mid == 0 || mid == (spis.size() - 1)) {
			return -1;
		}
		if (midVal > spis[mid - 1] && midVal > spis[mid + 1]) {
			return mid;
		}
		else if (midVal > spis[mid + 1]) {
			high = mid;
		}
		else {
			low = mid;
		}
	}

	if (mid == 0 || mid == (spis.size() - 1)) {
		return -1;
	}

	for (int i = 0; i < mid; i++) {
		if (spis[i] > spis[i + 1]) {
			return -1;
		}
	}

	for (int i = mid; i < (spis.size() - 1); i++) {
		if (spis[i] < spis[i + 1])
			return -1;
	}
	return mid;
}