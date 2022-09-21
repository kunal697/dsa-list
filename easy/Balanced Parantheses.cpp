#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;

    for (auto x : s) {
      if (x == '(' || x == '{' || x == '[')
        stack.push(x);
      else if (!stack.empty()) {
        char top = stack.top();
        if ((top == '(' && x == ')') || (top == '[' && x == ']') ||
            (top == '{' && x == '}')) {
          stack.pop();
        } else
          return false;
      } else
        return false;
    }
    if (!stack.empty())
      return false;
    return true;
  }
};

int main() {

  Solution *newSolution = new Solution();

  string str = "((((]))))";

  cout << newSolution->isValid(str) << endl;

  return 0;
}
