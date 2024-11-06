#include <iostream>

class HashTable {
	int lenght;
	std::string* mas = new std::string[lenght]{ "" };
	HashTable(int u_lenght) {
		lenght = u_lenght;
	}
	void appendHash(int key, std::string value) {
		int ind = key / lenght;
		if (mas[ind] == "") {
			mas[ind] = value;
		}
		else {
			if () {

			}
			std::string* sv_mas = new std::string;
			sv_mas[0] = mas[ind];
			mas[ind] = *sv_mas;
			sv_mas[1] = value;
		}
	}
	void appendHash(std::string key, std::string value) {
		int h = 0;
		char* p, * s = &key[0];
		for (p = s; *p != '\0'; p++) {
			h = h * 31 + (int)*p;
		}
		mas[h % lenght] = value;
	}
	std::string search(int key) {
		int ind = key / lenght;
		return mas[ind];
	}
	std::string search(std::string key) {
		int h = 0;
		char* p, * s = &key[0];
		for (p = s; *p != '\0'; p++) {
			h = h * 31 + (int)*p;
		}
		return mas[h % lenght];
	}
	void delet() {

	}
};

int main() {

	return 0;
}