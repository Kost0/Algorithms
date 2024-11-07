#include <iostream>
#include <string>
#include <ctime>

std::string add(std::string a, std::string b);
std::string subtraction(std::string a, std::string b);
std::string karatsuba(std::string x, std::string y);

int main() {
    setlocale(LC_ALL, "ru");
    int len1, len2;
    std::string first, second;
    std::cout << "Первое число: ";
    std::cin >> first;
    std::cout << "Второе число: ";
    std::cin >> second;
    bool minus1 = false, minus2 = false;
    if (first[0] == '-') {
        first.erase(0, 1);
        minus1 = true;
    }
    if (second[0] == '-') {
        minus2 = true;
        second.erase(0, 1);
    }
    minus1 ^= minus2;
    if (minus1) {
        std::cout << "-";
    }
    int start = clock();
    std::string result = karatsuba(first, second);
    int end = clock();
    int i = 0;
    while (result[i] == '0') {
        i++;
    }
    while (i < result.size()) {
        std::cout << result[i];
        i++;
    }
    std::cout << "\n" << "Время выполнения алгоритма Карацубы: " << end - start << "\n";
    start = clock();
    len1 = first.length();
    len2 = second.length();
    int* f_num = new int[len1] {0};
    int* s_num = new int[len2] {0};
    for (int i = 0; i < len1; i++) {
        f_num[i] = first[i] - '0';
    }
    for (int i = 0; i < len2; i++)
        s_num[i] = second[i] - '0';
    int* pro = new int[len1 + len2] {0};
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            pro[i + j + 1] += (f_num[i] * s_num[j]) % 10;
            if (pro[i + j + 1] >= 10) {
                pro[i + j] += pro[i + j + 1] / 10;
                pro[i + j + 1] %= 10;
            }
            pro[i + j] += (f_num[i] * s_num[j]) / 10;
            if (pro[i + j] >= 10) {
                pro[i + j - 1] += pro[i + j] / 10;
                pro[i + j] %= 10;
            }
        }
    }
    if (minus1)
        std::cout << '-';
    bool was_norm = false;
    for (int i = 0; i < len1 + len2; i++) {
        if (was_norm)
            std::cout << pro[i];
        else {
            if (pro[i] != 0) {
                std::cout << pro[i];
                was_norm = true;
            }
        }
    }
    end = clock();
    std::cout << "\n" << "Время выполнения умножения столбиком: " << end - start;
    return 0;
}

std::string add(std::string a, std::string b) {
    std::string result = "";
    int num = 0;
    while (a.size() < b.size()) {
        a = "0" + a;
    }
    while (b.size() < a.size()) {
        b = "0" + b;
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + num;
        num = sum / 10;
        result += (sum % 10) + '0';
    }
    if (num) {
        result += num + '0';
    }
    reverse(result.begin(), result.end());
    return result;
}

std::string subtraction(std::string a, std::string b) {
    std::string result = "";
    int per = 0;
    while (a.size() < b.size()) {
        a = "0" + a;
    }
    while (b.size() < a.size()) {
        b = "0" + b;
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        int sub = (a[i] - '0') - (b[i] - '0') - per;
        if (sub < 0) {
            sub += 10;
            per = 1;
        }
        else {
            per = 0;
        }
        result += sub + '0';
    }
    reverse(result.begin(), result.end());
    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    return result;
}

std::string karatsuba(std::string x, std::string y) {
    while (x.size() > 1 && x[0] == '0') {
        x.erase(0, 1);
    }
    while (y.size() > 1 && y[0] == '0') {
        y.erase(0, 1);
    }
    if (x.size() == 0 || y.size() == 0) {
        return "0";
    }
    if (x.size() == 1 && y.size() == 1) {
        return std::to_string((x[0] - '0') * (y[0] - '0'));
    }
    int n = std::max(x.size(), y.size());
    int half = (n + 1) / 2;
    while (x.size() < n) {
        x = "0" + x;
    }
    while (y.size() < n) {
        y = "0" + y;
    }
    std::string x1 = x.substr(0, x.size() - half);
    std::string x0 = x.substr(x.size() - half);
    std::string y1 = y.substr(0, y.size() - half);
    std::string y0 = y.substr(y.size() - half);
    std::string z2 = karatsuba(x1, y1);
    std::string z0 = karatsuba(x0, y0);
    std::string z1 = karatsuba(add(x1, x0), add(y1, y0));
    z1 = subtraction(z1, add(z2, z0));
    std::string result = add(add(z2 + std::string(2 * half, '0'), z1 + std::string(half, '0')), z0);
    return result;
}