#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isUnique(string s) {
  int n = (int)s.size();
  if (n > 26) {
    return false;
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < n - 1; i++) {
    int j = i + 1;
    if (s[i] == s[j]) {
      return false;
    }
  }
  return true;
}

int main(void) {
  string s;
  cin >> s;
  cout << (isUnique(s) ? "Yes" : "No") << endl;
}
