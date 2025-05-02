#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(const string& expr) {
  stack<char> buffer;

  for (char ch : expr) {
    if (ch == '(') {
      buffer.push(ch);
    } else if (ch == ')') {
      if (buffer.empty() || buffer.top() != '(') {
        return false;
      }
      buffer.pop();
    }
  }
  return buffer.empty();
}

int main() {
  string expression = "((1+2)/(3+4))*6";

  if (isValid(expression)) {
    cout << "The expression " << expression << " is valid." << endl;
  } else {
    cout << "The expression " << expression << " is invalid." << endl;
  }
  return 0;
}
