#include <iostream>
#include <string>

using namespace std;

string runlength(string s) {
  int n = (int)s.size();
  int itr = 0;
  string ans;
  while (itr < n) {
    char c = s[itr];
    int count = 0;
    while (c == s[itr]) {
      itr++;
      count++;
    }
    ans += c;
    ans += (char)('0' + count);
  }
  return ans;
}

int main(void) {
  string s;
  cin >> s;
  cout << runlength(s) << endl;
}
