#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>



#include <iostream> // for cin cout
using namespace std;

// Protoype of function to print '*' 45 times
void repchar();

// Prototype of function to print character argument 45 times
void repchar(char);

// Prototype of function to print character argument n times
void repchar(char, int);





template <typename T>
void printArray(std::vector<T>& arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void insertionSort(std::vector<T>& arr, int& comp, int& move) {
    for (int i = 1; i < arr.size(); ++i) {
        int j = i;
        T key = arr[i];
        comp++;
        move++;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            comp++;
            move++;
            j--;
        }
        arr[j] = key;
    }
}

template <typename T>
void selectionSort(std::vector<T>& arr, int& comp, int& move) {
    int minIdx;
    for (int i = 0; i < arr.size() - 1; ++i) {
        minIdx = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            comp++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(arr[minIdx], arr[i]);
            move++;
        }
    }
}

template <typename T>
void fillAscending(std::vector<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i;
    }
}

template <typename T>
void fillDescending(std::vector<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = arr.size() - i - 1;
    }
}

template <typename T>
void fillRandom(std::vector<T>& arr) {
    srand(time(0));
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = rand() % arr.size();
    }
}

int main() {
    std::vector<int> arr(10);
    int comp = 0, move = 0;




    // Call function to print '*' 45 times
    repchar();

    // Call function to print '=' 45 times
    repchar('=');

    // Call function to print '+' 30 times
    repchar('+', 30);





    fillAscending(arr);
    printArray(arr, arr.size());
    insertionSort(arr, comp, move);
    std::cout << "Ascending, Insertion Sort: comp = " << comp << ", move = " << move << std::endl;
    printArray(arr, arr.size());
    std::cout << std::endl;

    comp = 0, move = 0;
    fillAscending(arr);
    printArray(arr, arr.size());
    selectionSort(arr, comp, move);
    std::cout << "Ascending, Selection Sort: comp = " << comp << ", move = " << move << std::endl;
    printArray(arr, arr.size());
    std::cout << std::endl;

    comp = 0, move = 0;
    fillDescending(arr);
    printArray(arr, arr.size());
    insertionSort(arr, comp, move);
    std::cout << "Descending, Insertion Sort: comp = " << comp << ", move = " << move << std::endl;
    printArray(arr, arr.size());
    std::cout << std::endl;

    comp = 0, move = 0;
    fillDescending(arr);
    printArray(arr, arr.size());
    selectionSort(arr, comp, move);
    std::cout << "Descending, Selection Sort: comp = " << comp << ", move = " << move << std::endl;
    printArray(arr, arr.size());
    std::cout << std::endl;

    comp = 0, move = 0;
    fillRandom(arr);
    printArray(arr, arr.size());
    insertionSort(arr, comp, move);
    std::cout << "Random, Insertion Sort: comp = " << comp << ", move = " << move << std::endl;
    printArray(arr, arr.size());
    std::cout << std::endl;

    comp = 0, move = 0;
    fillRandom(arr);
    printArray(arr, arr.size());
    selectionSort(arr, comp, move);
    std::cout << "Random, Selection Sort: comp = " << comp << ", move = " << move << std::endl;
    printArray(arr, arr.size());
    std::cout << std::endl;


    return(0);
}
// Definition of function to print '*' 45 times
void repchar()
{
    for (int j = 0; j < 45; j++)
        cout << '*';
    cout << endl;
}

// Definition of function to print character argument 45 times
void repchar(char ch)
{
    for (int j = 0; j < 45; j++)
        cout << ch;
    cout << endl;
}

// Definition of function to print character argument n times
void repchar(char ch, int n)
{
    for (int j = 0; j < n; j++)
        cout << ch;
    cout << endl;
}
