#include <iostream>
#include <vector>

using namespace std;

bool findPairSum(const vector<int>& numbers, int targetSum) {
  int left = 0;
  int right = numbers.size() - 1;

  while (left < right) {
    int currentSum = numbers[left] + numbers[right];

    if (currentSum == targetSum) {
      return true;
    } else if (currentSum < targetSum) {
      left++;
    } else {
      right--;
    }
  }

  return false;
}

int main() {
  vector<int> numbers = {1, 2, 3, 4, 5};
  int targetSum = 6;

  if (findPairSum(numbers, targetSum)) {
    std::cout << "Pair found!" << std::endl;
  } else {
    std::cout << "No pair found." << std::endl;
  }

  return 0;
}
