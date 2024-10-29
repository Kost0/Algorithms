#include <iostream>

using namespace std;

int main() {
	int spisok[6] = {6,7,1,2,4,3};
	int nums[6] = { 0 }; 
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (spisok[i] > spisok[j])
				nums[i]++;
		}
	}
	for (int i = 0; i < 6; i++) {
		cout << nums[i];
	}
	return 0;
}
