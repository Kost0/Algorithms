void hanoi(int n, int start, int buf, int end) {
	if (n != 0) {
		hanoi(n - 1, start, end, buf);
		std::cout << "������� " << n << " �� " << start << " � " << end << "\n";
		hanoi(n - 1, buf, start, end);
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int a;
	std::cout << "������� ���������� ���������: ";
	std::cin >> a;
	hanoi(a, 1, 2, 3);
	return 0;
}