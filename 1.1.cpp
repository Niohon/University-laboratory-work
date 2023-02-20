#include <iostream>
#include <cmath>

using namespace std;

// через механизм return
int returnMaxPower(long int x) {
    int n = 0;
    while (pow(x, n) <= LONG_MAX) {
        n++;
    }
    return n - 1;
}

// через параметр-указатель
void pointerMaxPower(long int x, int *n) {
    *n = 0;
    while (pow(x, *n) <= LONG_MAX) {
        (*n)++;
    }
    (*n)--;
}

// через ссылочный параметр
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

    // через механизм return
    cout << "Return method: " << returnMaxPower(x) << endl;

    // через параметр-указатель
    pointerMaxPower(x, &n);
    cout << "Pointer method: " << n << endl;

    // через ссылочный параметр
    referenceMaxPower(x, n);
    cout << "Reference method: " << n << endl;
    cout << LONG_MAX << endl;


    return 0;
}
