#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> numbers;

  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_front(3);

  cout << "List elements: ";
  for (int num : numbers) {
    cout << num << " ";
  }
  cout << endl;

  // Removing elements
  numbers.remove(1);

  cout << "After removal: ";
  for (int num : numbers) {
    cout << num << " ";
  }
  cout << endl;

  // Reversing the list
  numbers.reverse();
  cout << "After reverse: ";
  for (int num : numbers) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
