#include <iostream>
using namespace std;

class Matrix {
private:
    int** matrix;
    int row;
    int colm;

    void allocate(int row, int colm) {
        matrix = new int*[row];
        for (int i = 0; i < row; i++) {
            matrix[i] = new int[colm];
        }
    }

    void deAllocate() {
        for (int i = 0; i < row; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

public:
    Matrix(int row, int colm, int initVal = 0) {
        this->row = row;
        this->colm = colm;
        
        allocate(row, colm);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colm; j++) {
                matrix[i][j] = initVal;
            }
        }
    }

    ~Matrix() {
        deAllocate();
    }

    void resize(int newRow, int newColm, int initVal = 0) {
        int** newMatrix = new int*[newRow];
        for (int i = 0; i < newRow; i++) {
            newMatrix[i] = new int[newColm];
        }

        for (int i = 0; i < newRow; i++) {
            for (int j = 0; j < newColm; j++) {
                if (i < row && j < colm) {
                    newMatrix[i][j] = matrix[i][j];
                } else {
                    newMatrix[i][j] = initVal;
                }
            }
        }

        deAllocate();

        matrix = newMatrix;
        row = newRow;
        colm = newColm;
    }

    void transpose() {
        int** transposeMatrix = new int*[colm];
        for (int i = 0; i < colm; i++) {
            transposeMatrix[i] = new int[row];
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colm; j++) {
                transposeMatrix[j][i] = matrix[i][j];
            }
        }

        deAllocate();

        matrix = transposeMatrix;
        swap(row, colm);
    }

    void printMatrix() {
        cout << "\nMatrix:" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colm; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void assignValues() {
        for (int i = 0; i < row; i++) {
            cout << endl;
            for (int j = 0; j < colm; j++) {
                cout << "Enter element at row " << i+1 << " and colums " << j+1 << ": ";
                cin >> matrix[i][j];
            }
        }
    }
};

int main() {
    Matrix m(3, 3);
    m.printMatrix();

    m.assignValues();
    m.printMatrix();

    m.resize(4, 4);
    m.assignValues();
    m.printMatrix();
    return 0;
}