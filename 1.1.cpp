#include <iostream>
#include <cmath>

using namespace std;

// ����� �������� return
int returnMaxPower(long int x) {
    int n = 0;
    while (pow(x, n) <= LONG_MAX) {
        n++;
    }
    return n - 1;
}

// ����� ��������-���������
void pointerMaxPower(long int x, int *n) {
    *n = 0;
    while (pow(x, *n) <= LONG_MAX) {
        (*n)++;
    }
    (*n)--;
}

// ����� ��������� ��������
void referenceMaxPower(long int x, int &n) {
    n = 0;
    while (pow(x, n) <= LONG_MAX) {
        n++;
    }
    n--;
}

int main() {
    long int x = 10;
    int n;

    // ����� �������� return
    cout << "Return method: " << returnMaxPower(x) << endl;

    // ����� ��������-���������
    pointerMaxPower(x, &n);
    cout << "Pointer method: " << n << endl;

    // ����� ��������� ��������
    referenceMaxPower(x, n);
    cout << "Reference method: " << n << endl;
    cout << LONG_MAX << endl;


    return 0;
}
