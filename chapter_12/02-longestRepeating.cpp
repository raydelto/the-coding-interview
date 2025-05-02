#include <string>
#include <iostream>
#include <algorithm>  // For max

using namespace std;

int longestRepeating(const string& s) {
  if (s.empty())
    return 0;

  int maxLen = 1;
  int start = 0;

  for (int end = 1; end < s.length(); ++end) {
    if (s[end] != s[start]) {
      start = end;
    }
    maxLen = max(maxLen, end - start + 1);
  }

  return maxLen;
}

int main() {
  string s = "abbcccddddeeeee";
  int result = longestRepeating(s);

  cout << "Length of the longest repeating substring is: " << result << endl;
  // Output: Length of the longest repeating substring is: 5 (eeeee)
  return 0;
}
