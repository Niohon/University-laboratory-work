#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int *arr = new int[n]; // Dynamic allocation of memory for the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number of positions to shift the elements to the right: ";
    cin >> k;
    int *temp = new int[k]; // Temporary array for storing the last k elements of the original array
    for (int i = n - k, j = 0; i < n; i++, j++) {
        temp[j] = arr[i];
    }
    for (int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
    cout << "The shifted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr; // Deallocating the memory
    delete[] temp;
    return 0;
}
