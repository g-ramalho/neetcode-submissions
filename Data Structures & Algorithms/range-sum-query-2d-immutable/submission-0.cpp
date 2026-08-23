class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i=0;i<n;i++) {
            int m = matrix[i].size();
            mat.push_back(vector<int>(m));
            for (int j=0;j<m;j++) {
                mat[i][j] = matrix[i][j];
                if (i > 0)
                    mat[i][j] += mat[i-1][j]; // row-wise prefix sum
                if (j > 0)
                    mat[i][j] += mat[i][j-1]; // col-wise prefix sum
                if (i > 0 && j > 0)
                    mat[i][j] -= mat[i-1][j-1]; // remove the last diagonal because it would be doubled
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int west_bounds = col1 > 0 ? mat[row2][col1-1] : 0;
        int north_bounds = row1 > 0 ? mat[row1-1][col2] : 0;

        int subtraction_overlap = row1 > 0 && col1 > 0 ? mat[row1-1][col1-1] : 0;

        return mat[row2][col2] + subtraction_overlap - west_bounds - north_bounds;
    }
};