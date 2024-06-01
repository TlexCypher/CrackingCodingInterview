#include <iostream>
#include <string>

using namespace std;

void shift(string &s, int itr) {
  int n = (int)s.size();
  for (int i = n - 1; i >= itr + 1; i--) {
    int j = i - 2;
    s[i] = s[j];
  }
}

void fill(string &s, int itr) {
  s[itr] = '%';
  s[itr + 1] = '2';
  s[itr + 2] = '0';
}

void urlify(string &s, int m) {
  int n = (int)s.size();
  int itr = 0;
  while (itr < m) {
    if (s[itr] != ' ') {
      itr++;
      continue;
    }
    shift(s, itr);
    fill(s, itr);
    itr += 3;
  }
}

int main(void) {
  string s;
  int m;
  getline(cin, s);
  cin >> m;
  urlify(s, m);
  cout << s << endl;
}
