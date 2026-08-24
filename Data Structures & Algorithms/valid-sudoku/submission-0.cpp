class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, vector<pair<int, int>>> positions;

        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] == '.') continue;

                if (positions.contains(board[i][j])) {
                    for (const pair<int, int>& p : positions[board[i][j]]) {
                        if (p.first == i
                        || p.second == j
                        || (p.first / 3 == i / 3 && p.second / 3 == j / 3))
                            return false;
                    }
                }
                positions[board[i][j]].push_back({ i, j });
            }
        }

        return true;
    }
};
