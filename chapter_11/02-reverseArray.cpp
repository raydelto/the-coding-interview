#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int>& arr) {
  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
  }
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  reverseArray(arr);

  for (int num : arr) {
    cout << num << " "; // Output: 5 4 3 2 1
  }

  cout << endl;
  return 0;
}
