#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;

int fibonacci(int n) {
  // Base case
  if (n <= 1)
    return n;

  if (memo.find(n) != memo.end())
    return memo[n];

  // Store the result
  memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
  return memo[n];
}

int main() {
  int number = 6;  // Example input
  std::cout << "Element number " << number + 1
            << " of the Fibonacci sequence is " << fibonacci(number)
            << std::endl;
  return 0;
}
