#include <iostream>
#include <ctime>

void haor(int* mas, int size);
void bubleSort(int* mas, int size);
void insertionSort(int* mas, int size);
void selectionSort(int* mas, int size);
void shakerSort(int* mas, int size);
void shellSort(int* mas, int size);

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int start, end;
    int mas_big_base[10000];
    int mas_small_base[100];
    int mas_big[10000];
    int mas_small[100];
    for (int i = 0; i < 100; i++)
        mas_small_base[i] = rand();
    for (int i = 0; i < 10000; i++)
        mas_big_base[i] = rand();
    for (int i = 0; i < 100; i++)
        mas_small[i] = mas_small_base[i];
    for (int i = 0; i < 10000; i++)
        mas_big[i] = mas_big_base[i];
    start = clock();
    haor(mas_small, 100);
    end = clock();
    std::cout << "Время выполнения quicksort на маленьком массиве: " << end - start << "\n";
    start = clock();
    haor(mas_big, 10000);
    end = clock();
    std::cout << "Время выполнения quicksort на большом массиве: " << end - start << "\n";
    for (int i = 0; i < 100; i++)
        mas_small[i] = mas_small_base[i];
    for (int i = 0; i < 10000; i++)
        mas_big[i] = mas_big_base[i];
    start = clock();
    bubleSort(mas_small, 100);
    end = clock();
    std::cout << "Время выполнения bubleSort на маленьком массиве: " << end - start << "\n";
    start = clock();
    bubleSort(mas_big, 10000);
    end = clock();
    std::cout << "Время выполнения bubleSort на большом массиве: " << end - start << "\n";
    for (int i = 0; i < 100; i++)
        mas_small[i] = mas_small_base[i];
    for (int i = 0; i < 10000; i++)
        mas_big[i] = mas_big_base[i];
    start = clock();
    shellSort(mas_small, 100);
    end = clock();
    std::cout << "Время выполнения shellSort на маленьком массиве: " << end - start << "\n";
    start = clock();
    shellSort(mas_big, 10000);
    end = clock();
    std::cout << "Время выполнения shellSort на большом массиве: " << end - start << "\n";
    for (int i = 0; i < 100; i++)
        mas_small[i] = mas_small_base[i];
    for (int i = 0; i < 10000; i++)
        mas_big[i] = mas_big_base[i];
    start = clock();
    insertionSort(mas_small, 100);
    end = clock();
    std::cout << "Время выполнения insertionSort на маленьком массиве: " << end - start << "\n";
    start = clock();
    insertionSort(mas_big, 10000);
    end = clock();
    std::cout << "Время выполнения insertionSort на большом массиве: " << end - start << "\n";
    for (int i = 0; i < 100; i++)
        mas_small[i] = mas_small_base[i];
    for (int i = 0; i < 10000; i++)
        mas_big[i] = mas_big_base[i];
    start = clock();
    selectionSort(mas_small, 100);
    end = clock();
    std::cout << "Время выполнения selectionSort на маленьком массиве: " << end - start << "\n";
    start = clock();
    selectionSort(mas_big, 10000);
    end = clock();
    std::cout << "Время выполнения selectionSort на большом массиве: " << end - start << "\n";
    for (int i = 0; i < 100; i++)
        mas_small[i] = mas_small_base[i];
    for (int i = 0; i < 10000; i++)
        mas_big[i] = mas_big_base[i];
    start = clock();
    shakerSort(mas_small, 100);
    end = clock();
    std::cout << "Время выполнения shakerSort на маленьком массиве: " << end - start << "\n";
    start = clock();
    shakerSort(mas_big, 10000);
    end = clock();
    std::cout << "Время выполнения shakerSort на большом массиве: " << end - start << "\n";
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

void bubleSort(int* mas, int size) {
    int unsorted_until_ind = size - 1;
    int temp = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < unsorted_until_ind; i++) {
            if (mas[i] > mas[i + 1]) {
                temp = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = temp;
                sorted = false;
            }
        }
        unsorted_until_ind--;
    }
}

void insertionSort(int* mas, int size) {
    int temp, cur_num;
    for (int i = 1; i < size; i++) {
        temp = mas[i];
        cur_num = i - 1;
        while (cur_num >= 0) {
            if (mas[cur_num] > temp) {
                mas[cur_num + 1] = mas[cur_num];
                cur_num--;
            }
            else
                break;
        }
        mas[cur_num + 1] = temp;
    }
}

void selectionSort(int* mas, int size) {
    int lowest_num, temp;
    for (int i = 0; i < size - 1; i++) {
        lowest_num = i;
        for (int j = i + 1; j < size; j++) {
            if (mas[j] < mas[lowest_num]) {
                lowest_num = j;
            }
        }
        if (lowest_num != i) {
            temp = mas[i];
            mas[i] = mas[lowest_num];
            mas[lowest_num] = temp;
        }
    }
}

void shakerSort(int* mas, int size) {
    int unsorted_until_r = size - 1;
    int unsorted_until_l = 0;
    int temp = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = unsorted_until_l; i < unsorted_until_r; i++) {
            if (mas[i] > mas[i + 1]) {
                temp = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = temp;
                sorted = false;
            }
        }
        unsorted_until_r--;
        for (int j = unsorted_until_r; j > unsorted_until_l; j--) {
            if (mas[j] < mas[j - 1]) {
                temp = mas[j];
                mas[j] = mas[j - 1];
                mas[j - 1] = temp;
                sorted = false;
            }
        }
        unsorted_until_l++;
    }
}

void shellSort(int* mas, int size) {
    int temp, cur_num, d = size / 2;
    while (d != 0) {
        for (int i = d; i < size; i++) {
            temp = mas[i];
            cur_num = i - d;
            while (cur_num >= 0) {
                if (mas[cur_num] > temp) {
                    mas[cur_num + d] = mas[cur_num];
                    cur_num--;
                }
                else
                    break;
            }
            mas[cur_num + 1] = temp;
        }
        d /= 2;
    }
}