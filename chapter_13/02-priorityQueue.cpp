#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>> ascending;
  priority_queue<int> descending;
  vector<int> values = {10, 20, 5, 30};

  // Add values to each priority queue
  for (const int& value : values) {
    ascending.push(value);
    descending.push(value);
  }

  cout << "Ascending order: ";
  while (!ascending.empty()) {
    cout << ascending.top() << " ";
    ascending.pop();
  }
  cout << endl;

  cout << "Descending order: ";
  while (!descending.empty()) {
    cout << descending.top() << " ";
    descending.pop();
  }
  cout << endl;
}
