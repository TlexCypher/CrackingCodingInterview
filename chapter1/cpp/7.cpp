#include <iostream>
#include <set>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &image) {
  int n = (int)image.size();
  set<pair<int, int>> st;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (st.count(make_pair(i, j))) {
        continue;
      }
      int buf1 = image[i][j];
      int buf2 = image[j][n - 1 - i];
      int buf3 = image[n - 1 - i][n - 1 - j];
      image[i][j] = image[n - 1 - j][i];
      image[j][n - 1 - i] = buf1;
      image[n - 1 - i][n - 1 - j] = buf2;
      image[n - 1 - j][i] = buf3;
      st.insert(make_pair(i, j));
      st.insert(make_pair(j, n - 1 - i));
      st.insert(make_pair(n - 1 - i, n - 1 - j));
      st.insert(make_pair(n - 1 - j, i));
    }
  }
}

int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  rotate(grid);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
