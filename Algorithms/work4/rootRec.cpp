#include <iostream>

float func(float l,float r);

int main() {
	float f = func(0, 1);
	std::cout << f << "\n";
	std::cout << (f - (1 / (3 + sin(3.6 * f))));
	return 0;
}

float func(float l, float r) {
	float f = (r + l) / 2;
	if (r - l < 0.0001)
		return f;
	else {
		if ((f - (1 / (3 + sin(3.6 * f)))) > 0) {
			return func(l,f);
		}
		else {
			return func(f, r);
		}
	}
}