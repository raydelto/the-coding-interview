#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
  int size = arr.size();
  bool swapped;

  // Perform n-1 passes
  for (int i = 0; i < size - 1; ++i) {
    swapped = false;

    // Compare adjacent elements
    for (int j = 0; j < size - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    // If no swaps, the array is sorted
    if (!swapped)
      break;
  }
}

int main() {
  vector<int> numbers = {1983, 64, 34, 25, 12, 22, 11, 90, 19};
  cout << "Unsorted array: ";
  for (int num : numbers) {
    cout << num << " ";
  }

  bubbleSort(numbers);
  cout << "\nSorted array: ";
  for (int num : numbers) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
