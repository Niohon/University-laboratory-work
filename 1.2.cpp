#include <iostream>
#include <cmath>

using namespace std;

// функция для вычисления значения многочлена для определенного значения x и степени n
double polyValue(const int& start,const int& stop,const double& step, int& c) {
    double result = 1;

    for (double x = start; x <= stop; x += step) {
        result = 1;
        for (int n = 1; n <= c; n++) {
            result += 2 * n * pow(x, n);
            cout << " result=" << result << " n=" << n << " x=" << x << endl;
        }
    }


    return result;
}

int main(){
    int c;
    cin  >> c;
    double y;
    int start = 1;
    int stop = 5;
    double step = 0.5;

    y = polyValue(start, stop, step, c);
    cout << ", y = " << y << endl;
    return 0;
}
