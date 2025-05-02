#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
  // Map to store value -> index
  unordered_map<int, int> mappedValues;

  for (int i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];

    // Check if the complement exists
    if (mappedValues.find(complement) != mappedValues.end()) {
      return {mappedValues[complement], i};
    }

    // Store current index
    mappedValues[nums[i]] = i;
  }

  // No solution found
  return {};
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  vector<int> result = twoSum(nums, target);

  if (!result.empty()) {
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
  } else {
    cout << "No two sum solution found." << endl;
  }

  // Output: Indices: 0, 1
  return 0;
}
