class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] == '.') continue;

                if ((rows[i] & 1 << (board[i][j] - '1')) == 1 << (board[i][j] - '1')
                    || (cols[j] & 1 << (board[i][j] - '1')) == 1 << (board[i][j] - '1')
                    || (squares[(i / 3) * 3 + (j / 3)] & 1 << (board[i][j] - '1')) == 1 << (board[i][j] - '1'))
                    return false;

                rows[i] |= 1 << (board[i][j] - '1');
                cols[j] |= 1 << (board[i][j] - '1');
                squares[(i / 3) * 3 + (j / 3)] |= 1 << (board[i][j] - '1');
            }
        }

        return true;
    }
};
