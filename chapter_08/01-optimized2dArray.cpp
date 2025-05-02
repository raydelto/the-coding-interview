#include <iostream>
#include <vector>

using namespace std;

int getElement(const vector<int>& matrix, int row, int col, int numCols) {
  return matrix[row * numCols + col];
}

int main() {

  vector<int> matrix = {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9
  };

  int numCols = 3;  // Number of columns in the matrix

  cout << "Value at (0, 0): " << getElement(matrix, 0, 0, numCols) << endl; // Output: 1
  cout << "Value at (1, 2): " << getElement(matrix, 1, 2, numCols) << endl; // Output: 6
  cout << "Value at (2, 1): " << getElement(matrix, 2, 1, numCols) << endl; // Output: 8
  return 0;  // Return 0 to indicate successful execution.
}
