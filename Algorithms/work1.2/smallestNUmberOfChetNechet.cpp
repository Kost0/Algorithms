#include <iostream>
#include <vector>

using namespace std;

int func(vector<int>& vect, int);

int main() {
	vector<int> spis = {-3,-2,-1,-1,-1,-1,0,0,1,1,1,1,1,2,3,4,5};
	cout << func(spis, 0);
	return 0;
}

int func(vector<int>& spis, int key) {
	int low = 0;
	int high = spis.size();
	int mid;
	int midVal;

	while (low <= high) {
		mid = (low + high) / 2;
		midVal = spis[mid];
		if (midVal == key) {
			break;
		}
		else if (midVal > key){
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	int left = mid - 1, right = mid + 1;
	while (spis[left] == 0) {
		if (left != 0){
			left -= 1;
		}
		else {
			break;
		}
	}
	while (spis[right] == 0) {
		if (right != spis.size() - 1) {
			right += 1;
		}
		else {
			break;
		}
	}
	if ((left + 1) >= (spis.size() - right))
		return (left + 1);
	else
		return (spis.size() - right);
}