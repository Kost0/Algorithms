#include <iostream>

using namespace std;

int main() {
	int rand = 31728;
	for (int i = 0; i < 10; i++) {
		rand = abs(rand * rand / 100 % 100000);
		cout << rand << endl;
	}
	return 0;
}