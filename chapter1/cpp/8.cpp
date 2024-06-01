#include <iostream>
#include <set>
#include <vector>

using namespace std;

pair<set<int>, set<int>> get_zrow_zcol(vector<vector<int>> &grid) {
  set<int> zrow, zcol;
  int n = (int)grid.size();
  int m = (int)grid[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        zrow.insert(i);
        zcol.insert(j);
      }
    }
  }
  return make_pair(zrow, zcol);
}

void fill_zero(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  auto [zrow, zcol] = get_zrow_zcol(grid);
  for (int row : zrow) {
    for (int j = 0; j < m; j++) {
      grid[row][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int col : zcol) {
      grid[i][col] = 0;
    }
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  fill_zero(grid);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
