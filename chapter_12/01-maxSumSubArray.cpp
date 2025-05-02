#include <algorithm>  // For max
#include <iostream>
#include <limits>  // For numeric_limits
#include <vector>

using namespace std;

int maxSumSubArray(const vector<int>& nums, int winSize) {
  int windowSum = 0;
  int maxSum = numeric_limits<int>::min();

  for (int i = 0; i < nums.size(); ++i) {
    windowSum += nums[i];

    if (i >= winSize - 1) {
      maxSum = max(maxSum, windowSum);
      windowSum -= nums[i - (winSize - 1)];
    }
  }

  return maxSum;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int winSize = 3;

  int result = maxSumSubArray(nums, winSize);

  cout << "Maximum sum of subarray of size " << winSize << " is: " << result
       << endl;
  // Output: Maximum sum of subarray of size 3 is: 24
  // The three numbers that sum up to 24 are: 7, 8, 9
  return 0;
}
