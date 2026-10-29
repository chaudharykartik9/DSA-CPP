
class Solution {
private:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> solve(int start, string& s) {
        if (start == s.size()) {
            return {""};
        }

        if (memo.count(start)) {
            return memo[start];
        }

        vector<string> ans;
        string word;

        for (int i = start; i < s.size(); i++) {
            word += s[i];

            if (dict.count(word)) {
                vector<string> suffixes = solve(i + 1, s);

                for (string suffix : suffixes) {
                    if (suffix.empty()) {
                        ans.push_back(word);
                    } else {
                        ans.push_back(word + " " + suffix);
                    }
                }
            }
        }

        return memo[start] = ans;
    }

public:
    vector<string> wordBreak(string s,
                             vector<string>& wordDict) {
        dict.clear();
        memo.clear();

        for (string word : wordDict) {
            dict.insert(word);
        }

        return solve(0, s);
    }
};
