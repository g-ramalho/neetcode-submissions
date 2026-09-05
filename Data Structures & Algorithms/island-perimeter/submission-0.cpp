class Solution {
    const vector<pair<int, int>> adj = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int dfs(pair<int, int> curr, vector<vector<int>>& grid, vector<vector<bool>>& seen) {
        seen[curr.first][curr.second] = true;
        int borders = 0;

        for (const pair<int, int> &p : adj) {
            const pair<int, int> other = {curr.first + p.first, curr.second + p.second};
            if (other.first >= 0 && other.first < grid.size()
                && other.second >= 0 && other.second < grid[curr.first].size()
                && grid[other.first][other.second] == 1) {
                    if (!seen[other.first][other.second])
                        borders += dfs(other, grid, seen);
                } else borders++;
        }

        return borders;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++)
                if (grid[i][j] == 1)
                    return dfs({i, j}, grid, seen);
        }

        return 0;
    }
};