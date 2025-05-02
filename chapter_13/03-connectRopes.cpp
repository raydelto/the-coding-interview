#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minimumCost(const vector<int>& lengths) {
  priority_queue<int, vector<int>, greater<int>> ropes;
  for (int len : lengths) {
    ropes.push(len);
  }

  int totalCost = 0;

  // Keep combining the two shortest ropes
  while (ropes.size() > 1) {
    int first = ropes.top();
    ropes.pop();
    int second = ropes.top();
    ropes.pop();

    int cost = first + second;
    totalCost += cost;

    ropes.push(cost);
  }

  return totalCost;
}

int main() {
  vector<int> lengths = {4, 3, 2, 6};
  int result = minimumCost(lengths);

  cout << "Minimum cost to connect ropes: " << result << endl;
  // Output: Minimum cost to connect ropes: 29
  return 0;
}
