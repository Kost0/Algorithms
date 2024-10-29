int deik(int a);

int main() {
	int a;
	std::cin >> a;
	std::cout << deik(a);
	return 0;
}

int deik(int a) {
	if (a == 1)
		return 1;
	else if (a % 2 == 0)
		return deik(a / 2);
	else
		return deik(a / 2) + deik(a / 2 + 1);