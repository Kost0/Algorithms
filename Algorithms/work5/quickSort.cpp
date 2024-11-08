#include <iostream>

void haor(int* mas, int size);

int main() {
    int mas[10] = { 7,1,4,2,7,3,9,23,4,5 };
    haor(mas, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << mas[i] << " ";
    }
    return 0;
}

void haor(int* mas, int size) {
    int i = 0;
    int j = size - 1;
    int opor = mas[size / 2], tmp = 0;
    while (i <= j) {
        while (mas[i] < opor) {
            i++;
        }
        while (mas[j] > opor) {
            j--;
        }
        if (i <= j) {
            tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    }
    if (j > 0) {
        haor(mas, j + 1);
    }
    if (i < size) {
        haor(&mas[i], size - i);
    }
}