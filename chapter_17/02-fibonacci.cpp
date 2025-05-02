#include <iostream>

using namespace std;

int fibonacci(int n) {
  // Base case
  if (n <= 1)
    return n;

  // Recursive case
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int number = 6;  // Example input
  cout << "Element number "<< number + 1 << " of the Fibonacci sequence is " << fibonacci(number) << endl;
  return 0;
}
