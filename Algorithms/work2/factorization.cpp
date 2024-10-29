#include <iostream>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int half_n = n / 2;
	int* spisok = new int[n / 2];
	int* res = new int[n / 2];
	for (int i = 2; i <= n / 2 + 2; i++) 
		spisok[i - 2] = i;
	for (int i = 0; i <= n / 2; i++)
		res[i] = 0;
	int cur_in = 0, cur_num = 0;
	while (cur_in < n) {
		if (spisok[cur_in] != 0) {
			cur_num = spisok[cur_in];
			for (int i = cur_in + 1; i < n / 2; i++) {
				if (spisok[i] % cur_num == 0) {
					spisok[i] = 0;
				}
			}
		}
		cur_in++;
	}
	int cnt = 0;
	for (int i = 0; i < half_n + 2; i++) {
		if (spisok[i] != 0 && n != 1) {
			cnt = 0;
			while (n % spisok[i] == 0 && n != 1) {
				cnt++;
				n /= spisok[i];
			}
			res[i + 2] = cnt;
		}
	}
	int count = 0;
	for (int i = 0; i < half_n + 1; i++) {
		if (res[i] != 0)
			count++;
	}
	if (count == 0) {
		cout << "Number is prime";
	}
	else {
		for (int i = 0; i < half_n + 1; i++) {
			if (res[i] != 0) {
				if (count > 1)
					cout << i << " ^ " << res[i] << " * ";
				else
					cout << i << " ^ " << res[i];
				count--;
			}
		}
	}
	return 0;
}