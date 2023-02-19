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
    int maxI = 0, maxJ = 0, crossI = 0, crossJ = N - 1;
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] > maxDiag) {
            maxDiag = matrix[i][i];
            maxI = maxJ = i;
        }
        if (matrix[i][N - i - 1] > maxDiag) {
            maxDiag = matrix[i][N - i - 1];
            crossI = i;
            crossJ = N - i - 1;
        }
    }
    //Swap elements matrix[maxI][maxJ] and matrix[crossI][crossJ]
    matrix[maxI][maxJ] = matrix[maxJ][maxJ] ^ matrix[crossI][crossJ];
    matrix[crossI][crossJ] = matrix[maxI][maxJ] ^ matrix[crossI][crossJ];
    matrix[maxI][maxJ] = matrix[maxI][maxJ] ^ matrix[crossI][crossJ];
}

int main() {
    int matrix[N][N];
    setMatrix(matrix);
    printMatrix(matrix);

    swapMaxDiagonal(matrix);
    printMatrix(matrix);

    return 0;
}
