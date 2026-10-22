class Solution {
private:
    void func(int idx, int n, string s, vector<string>& ans) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }
        func(idx + 1, n, s + '1', ans);
        if (idx == 0 || s[idx - 1] != '0') {
            func(idx + 1, n, s + '0', ans);
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        func(0, n, "", ans);
        return ans;
    }
};