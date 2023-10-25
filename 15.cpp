#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a sparse matrix element
struct MatrixElement {
    int row, col, value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int rows, cols;
    vector<MatrixElement> elements;
};

// Function to create a sparse matrix
SparseMatrix createSparseMatrix(int rows, int cols, vector<vector<int>>& data) {
    SparseMatrix sparseMatrix;
    sparseMatrix.rows = rows;
    sparseMatrix.cols = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] != 0) {
                MatrixElement element;
                element.row = i;
                element.col = j;
                element.value = data[i][j];
                sparseMatrix.elements.push_back(element);
            }
        }
    }

    return sparseMatrix;
}

// Function to display a sparse matrix
void displaySparseMatrix(const SparseMatrix& sparseMatrix) {
    for (int i = 0; i < sparseMatrix.elements.size(); i++) {
        cout << sparseMatrix.elements[i].row << " ";
        cout << sparseMatrix.elements[i].col << " ";
        cout << sparseMatrix.elements[i].value << endl;
    }
}

int main() {
    int rows = 4;
    int cols = 5;

    // Example data for a sparse matrix
    vector<vector<int>> data = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0},
        {0, 2, 0, 0, 0},
        {0, 0, 0, 0, 4}
    };

    SparseMatrix sparseMatrix = createSparseMatrix(rows, cols, data);

    cout << "Sparse Matrix:" << endl;
    displaySparseMatrix(sparseMatrix);

    return 0;
}
