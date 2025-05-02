#include <queue>
#include <iostream>

using namespace std;

int main() {
  queue<int> q;

  q.push(10);  // enqueue
  q.push(20);
  q.push(30);

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();  // dequeue
  }

  return 0;
}
