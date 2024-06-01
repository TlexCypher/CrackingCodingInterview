#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
  int n = (int)s.size();
  int m = (int)t.size();
  if (n != m) {
    return false;
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      return false;
    }
  }
  return true;
}

int main(void) {
  string s, t;
  cin >> s >> t;
  cout << (isAnagram(s, t) ? "Yes" : "No") << endl;
}
