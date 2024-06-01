#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isPermutation(string s) {
  int n = (int)s.size();
  map<char, int> alphabetCounter;
  for (int i = 0; i < n; i++) {
    alphabetCounter[s[i]]++;
  }
  int oddCounter = 0;
  for (auto &p : alphabetCounter) {
    oddCounter += (p.second % 2 == 1);
  }
  return oddCounter == 0 || oddCounter == 1;
}

string trim(string s) {
  int n = (int)s.size();
  string ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      continue;
    }
    ans += s[i];
  }
  return ans;
}

string toLower(string s) {
  int n = (int)s.size();
  string ans;
  for (int i = 0; i < n; i++) {
    if ('A' <= s[i] and s[i] <= 'Z') {
      ans += (s[i] + 32);
    } else {
      ans += s[i];
    }
  }
  return ans;
}

int main(void) {
  string s;
  getline(cin, s);
  s = trim(s);
  s = toLower(s);
  cout << (isPermutation(s) ? "Yes" : "No") << endl;
}
