class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n1 = matrix.size();
        int n2 = matrix[0].size();
        int high = (n1 * n2 - 1), low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / n2;
            int col = mid % n2;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target)
                low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};