#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> 
findTripletsBruteForce(vector<int>& nums) {
  vector<vector<int>> result;
  set<vector<int>> uniqueTriplets;

  int n = nums.size();
  if (n < 3) {
    return result;  // Not enough elements
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          vector<int> triplet(3);
          triplet[0] = nums[i];
          triplet[1] = nums[j];
          triplet[2] = nums[k];
          sort(triplet.begin(), triplet.end());
          uniqueTriplets.insert(triplet);
        }
      }
    }
  }
  return result;
}

int main() {
  vector<int> numbers = {1983, 64, 34, 25, 12, 22, 11, 90, 19};
  vector<vector<int>> triplets = findTripletsBruteForce(numbers);
  cout << "Triplets that sum to zero:" << endl;
  for (const vector<int>& triplet : triplets) {
    cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2]
         << "] ";
  }
  cout << endl;
  return 0;
}
