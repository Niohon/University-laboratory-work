#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream f("f.txt");
    ifstream g("g.txt");
    ofstream result("result.txt");

    string f_num, g_num;

    // чтение первых чисел из файлов f и g
    if (!getline(f, f_num) || !getline(g, g_num)) {
        return 0;
    }

    // слияние файлов
    while (true) {
        if (f_num <= g_num) {
            result << f_num << endl;
            if (!getline(f, f_num)) {
                break;
            }
        }
        else {
            result << g_num << endl;
            if (!getline(g, g_num)) {
                break;
            }
        }
    }

    // запись оставшихся чисел
    while (getline(f, f_num)) {
        result << f_num << endl;
    }
    while (getline(g, g_num)) {
        result << g_num << endl;
    }

    f.close();
    g.close();
    result.close();

    return 0;
}
