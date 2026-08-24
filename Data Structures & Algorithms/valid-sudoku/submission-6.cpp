class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] == '.') continue;

                int mask = 1 << (board[i][j] - '1');

                if ((rows[i] & mask) == mask
                    || (cols[j] & mask) == mask
                    || (squares[(i / 3) * 3 + (j / 3)] & mask) == mask)
                    return false;

                rows[i] |= mask;
                cols[j] |= mask;
                squares[(i / 3) * 3 + (j / 3)] |= mask;
            }
        }

        return true;
    }
};
