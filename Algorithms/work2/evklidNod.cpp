#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, razn;
	cin >> a >> b >> c >> d;
	if (a < 0)
		a = abs(a);
	if (b < 0)
		b = abs(b);
	if (c < 0)
		c = abs(c);
	if (d < 0)
		d = abs(d);
	if (a == 0) {
		if (b != 0) 
			a = b;
		if (c != 0)
			a = c;
		if (d != 0)
			a = d;
	}
	if (b == 0) {
		if (a != 0)
			b = a;
		if (c != 0)
			b = c;
		if (d != 0)
			b = d;
	}
	if (c == 0) {
		if (a != 0)
			c = a;
		if (b != 0)
			c = b;
		if (d != 0)
			c = d;
	}
	if (d == 0) {
		if (a != 0)
			d = a;
		if (b != 0)
			d = b;
		if (c != 0)
			d = c;
	}
	while (a != b) {
		if (a > b) {
			razn = a - b;
			a = razn;
		}
		if (b > a) {
			razn = b - a;
			b = razn;
		}
	}
	while (c != d) {
		if (c > d) {
			razn = c - d;
			c = razn;
		}
		if (d > c) {
			razn = d - c;
			d = razn;
		}
	}
	while (a != c) {
		if (a > c) {
			razn = a - c;
			a = razn;
		}
		if (c > a) {
			razn = c - a;
			c = razn;
		}
	}
	cout << a;
	return 0;
}