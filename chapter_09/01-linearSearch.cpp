#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const vector<int>& arr, int target) {
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == target)
      return i;
  }
  return -1;  // not found
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int target = 3;
  int index = linearSearch(arr, target);

  if (index != -1) {
    cout << "Element found at index: " << index << endl;  // Output: Element found at index: 2
  } else {
    cout << "Element not found" << endl;
  }

  return 0;  // Return 0 to indicate successful execution.
}
