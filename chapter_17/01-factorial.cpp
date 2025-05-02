#include <iostream>

using namespace std;

int factorial(int n) {
  // Base case
  if (n <= 1)
    return 1;
  // Recursive case
  return n * factorial(n - 1);
}

int main() {
  // Bear in mind that the factorial of a negative number is undefined
  int number = 5;
  cout << "Factorial of " << number << " = " << factorial(number) << endl;
  // Output: Factorial of 5 = 120
  return 0;
}
