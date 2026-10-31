class Solution {
private:
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void func(int idx, string &s, vector<string> &temp,
              vector<vector<string>> &ans) {

        // Base case: entire string is partitioned
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible substring
        for (int i = idx; i < s.size(); i++) {

            if (isPalindrome(s, idx, i)) {

                // Choose
                temp.push_back(s.substr(idx, i - idx + 1));

                // Explore
                func(i + 1, s, temp, ans);

                // Backtrack
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        func(0, s, temp, ans);

        return ans;
    }
};