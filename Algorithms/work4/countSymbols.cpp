#include <iostream>
#include <unordered_map>
#include <string>

void count_symbols(std::string str);

int main() {
	count_symbols("sswweer");
	return 0;
}

void count_symbols(std::string str) {
	std::unordered_map<char, int> mymap;
	for (int i = 0; i < str.size(); i++) {
		mymap[str[i]]++;
	}
	for (const auto& el : mymap) {
		std::cout << el.first << " - " << el.second << "\n";
	}
}