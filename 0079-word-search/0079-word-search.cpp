class Solution {
private:
    bool func(int i, int j, vector<vector<char>>& board,
              string& word, int idx) {


        if (i < 0 || j < 0 || i >= board.size() ||
            j >= board[0].size() || board[i][j] != word[idx])
            return false;
        if (idx == word.size() - 1)
            return true;


        char k = board[i][j];
        board[i][j] = '#';

        bool ans = false;

        if (i > 0)
            ans = ans || func(i - 1, j, board, word, idx + 1); // TOP


        if (j > 0)
            ans = ans || func(i, j - 1, board, word, idx + 1); // LEFT

        if (j < board[0].size() - 1)
            ans = ans || func(i, j + 1, board, word, idx + 1); // RIGHT

        if (i < board.size() - 1)
            ans = ans || func(i + 1, j, board, word, idx + 1); // DOWN

        // Restore original character (Backtracking)
        board[i][j] = k;

        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {
                    if (func(i, j, board, word, 0))
                        return true;
                }
            }
        }

        return false;
    }
};