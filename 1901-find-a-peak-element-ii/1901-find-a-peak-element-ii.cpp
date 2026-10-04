class Solution {
   private:
    int findRow(vector<vector<int>>& mat, int col) {
        int n = mat.size();
        int max_ele = INT_MIN;
        int row = -1;

        for (int i = 0; i < n; i++) {
            if (mat[i][col] > max_ele) {
                max_ele = mat[i][col];
                row = i;
            }
        }

        return row;
    }

   public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = findRow(mat, mid);

            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : INT_MIN;

            int right = (mid + 1 < m) ? mat[row][mid + 1] : INT_MIN;

            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};

            if (right > mat[row][mid])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return {-1, -1};
    }
};