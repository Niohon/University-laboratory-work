#include <iostream>
using namespace std;

const int N = 3;

void setMatrix(int matrix[][N]) {
    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][N]) {
    cout << "Matrix: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void swapMaxDiagonal(int matrix[][N]) {
    int maxDiag = matrix[0][0];
    int maxI = 0, maxJ = 0, center = matrix[N / 2][N / 2];
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] > maxDiag) {
            maxDiag = matrix[i][i];
            maxI = maxJ = i;
        }
        if (matrix[i][N - i - 1] > maxDiag) {
            maxDiag = matrix[i][N - i - 1];
            maxI = i;
            maxJ = N - i - 1;
        }
    }
    matrix[N / 2][N / 2] = matrix[maxI][maxJ];
    matrix[maxI][maxJ] = center;
}


int main() {
    int matrix[N][N];
    setMatrix(matrix);
    printMatrix(matrix);

    swapMaxDiagonal(matrix);
    printMatrix(matrix);

    return 0;
}
