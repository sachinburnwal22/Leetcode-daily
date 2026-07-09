class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int recur(int i, int j, vector<vector<int>>& grid) {

        // Out of bounds
        if (i >= n || j >= m)
            return INT_MAX;

        // Destination reached
        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = recur(i + 1, j, grid);
        int right = recur(i, j + 1, grid);

        if (down == INT_MAX)
            return dp[i][j] = grid[i][j] + right;

        if (right == INT_MAX)
            return dp[i][j] = grid[i][j] + down;

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<int>(m, -1));

        return recur(0, 0, grid);
    }
};