#include <bits/stdc++.h>
using namespace std;

long long dfs(int i, int j, int n, int m,
              vector<vector<int>>& grid,
              vector<vector<int>>& vis) {
    vis[i][j] = 1;

    long long sum = grid[i][j];

    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {-1, 0, 1, 0};

    for (int k = 0; k < 4; k++) {
        int r = i + dr[k];
        int c = j + dc[k];

        if (r < 0 || r >= n || c < 0 || c >= m)
            continue;

        if (!vis[r][c] && grid[r][c] != 0) {
            sum += dfs(r, c, n, m, grid, vis);
        }
    }

    return sum;
}

int countIslands(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0 && !vis[i][j]) {
                long long sum = dfs(i, j, n, m, grid, vis);

                if (sum % k == 0)
                    ans++;
            }
        }
    }

    return ans;
}

int main() {
    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> k;

    cout << countIslands(grid, k) << endl;

    return 0;
}