#include <iostream>
#include <vector>
#include <algorithm>

void func(int, int*, int*);

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int n = 0;
	int del1 = 0, del2 = 0;
	cin >> n;
	if (n % 2 == 0) {
		cout << "Нельзя факторизировать чётные числа";
		return 0;
	}
	int* numbers = new int[n - 1];
	for (int i = 2; i <= n; i++) {
		numbers[i - 2] = i;
	}
	for (int i = 2; i <= n; i++) {
		int cur_i = 0, cur_n = 0;
		while (cur_i < n - 2) {
			if (numbers[cur_i] != 0) {
				cur_n = numbers[cur_i];
				for (int i = cur_i + 1; i < n; i++) {
					if (numbers[i] % cur_n == 0) {
						numbers[i] = 0;
					}
				}
			}
			cur_i++;
		}
	}
	func(n, &del1, &del2);
	vector<int> all_delit = { del1, del2 };
	bool not_all_prime = true;
	while (not_all_prime) {
		bool is_prime = false;
		int prime = 0;
		//Дальше почему то бесконечный цикл
		for (int i = 0; i < all_delit.size(); i++) {
			is_prime = false;
			for (int j = 0; j < n; j++) {
				if (all_delit[i] == numbers[j]) {
					prime++;
					is_prime = true;
					break;
				}
			}
			if (is_prime == false) {
				del1 = 0;
				del2 = 0;
				func(all_delit[i], &del1, &del2);
				all_delit.push_back(del1);
				all_delit.push_back(del2);
				all_delit.erase(all_delit.begin() + i);
			}
		}
		if (prime == all_delit.size())
			not_all_prime = false;
		prime = 0;
	}
	std::sort(begin(all_delit), end(all_delit));
	int cnt = 0;
	bool is_same = false;
	vector<int> res;
	vector<int> ste;
	for (int i = 0; i < all_delit.size() - 1; i++) {
		if (!is_same) {
			if (all_delit[i] == all_delit[i + 1]) {
				cnt = 2;
				is_same = true;
			}
			else if(i == all_delit.size() - 2){
				res.push_back(all_delit[i]);
				ste.push_back(1);
				res.push_back(all_delit[i + 1]);
				ste.push_back(1);
			}
			else {
				res.push_back(all_delit[i]);
				ste.push_back(1);
			}
		}
		else{
			if (all_delit[i] == all_delit[i + 1]) {
				cnt++;
			}
			else if (i == all_delit.size() - 2) {
				res.push_back(all_delit[i]);
				ste.push_back(cnt);
				res.push_back(all_delit[i + 1]);
				ste.push_back(1);
			}
			else {
				res.push_back(all_delit[i]);
				ste.push_back(cnt);
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "^" << ste[i] << " ";
	}
	return 0;
}

void func(int n, int* del1, int* del2) {
	int m = sqrt(n), x = 0, q = 0, root_q = 0;
	while (true) {
		q = (m + x) * (m + x) - n;
		root_q = sqrt(q);
		if (root_q * root_q == q) {
			break;
		}
		else {
			x++;
		}
	}
	*del1 = (m + x) - root_q;
	*del2 = (m + x) + root_q;
}
