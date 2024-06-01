#include <iostream>
#include <map>
#include <string>

using namespace std;

bool insertOk(map<char, int> &s_mp, map<char, int> &t_mp) {
  int insertCount = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    int diff = s_mp[c] - t_mp[c];
    if (diff == 1) {
      insertCount++;
    }
  }
  return insertCount == 1;
}

bool removeOk(map<char, int> &s_mp, map<char, int> &t_mp) {
  int removeCount = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    int diff = s_mp[c] - t_mp[c];
    if (diff == -1) {
      removeCount++;
    }
  }
  return removeCount == 1;
}

bool replaceOk(string s, string t) {
  int n = (int)s.size();
  int m = (int)t.size();
  int diffCount = 0;
  if (n != m) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      diffCount++;
    }
  }
  return diffCount == 1;
}

bool orderOk(string &s, string &t) {
  int n = (int)s.size();
  int m = (int)t.size();
  int itr = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[itr]) {
      itr++;
    }
  }
  return itr == m;
}

bool replaceOneTime(string s, string t) {
  if (s.size() < t.size()) {
    swap(s, t);
  }
  int n = (int)s.size();
  int m = (int)t.size();
  map<char, int> s_mp, t_mp;
  for (int i = 0; i < n; i++) {
    s_mp[s[i]]++;
  }
  for (int i = 0; i < m; i++) {
    t_mp[t[i]]++;
  }
  return (orderOk(s, t) && (insertOk(s_mp, t_mp) || removeOk(s_mp, t_mp))) ||
         replaceOk(s, t) || s == t;
}

int main(void) {
  string s, t;
  cin >> s >> t;
  cout << (replaceOneTime(s, t) ? "Yes" : "No") << endl;
}
