#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool hasDuplicates(const vector<int>& nums) {
  unordered_set<int> seen;

  for (int num : nums) {
    if (seen.count(num) > 0) {
      return true;
    }
    seen.insert(num);
  }

  // No duplicates found
  return false;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 1};  // Example input with duplicates
  if (hasDuplicates(nums)) {
    cout << "The array has duplicates." << endl;
  } else {
    cout << "The array does not have duplicates." << endl;
  }

  // Output: The array has duplicates.
  return 0;
}
