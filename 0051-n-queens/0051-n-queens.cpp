
class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int r = row, c = col;

        // Check upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Check same column
        r = row;
        c = col;

        while (r >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
        }

        // Check upper-right diagonal
        r = row;
        c = col;

        while (r >= 0 && c < board[0].size()) {
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        return true;
    }

    void func(int row, vector<vector<string>>& ans,
              vector<string>& board) {

        // Base case
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < board[0].size(); col++) {

            if (isSafe(board, row, col)) {

                board[row][col] = 'Q';

                func(row + 1, ans, board);

                // Backtracking
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        func(0, ans, board);

        return ans;
    }
};
