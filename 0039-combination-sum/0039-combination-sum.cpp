class Solution {
private:
    void func(vector<int>& candi, int idx, int sum,
              vector<int>& temp, vector<vector<int>>& ans) {

        if (sum == 0) {
            ans.push_back(temp);
            return;
        }

        if (sum < 0 || idx == candi.size()) {
            return;
        }


        temp.push_back(candi[idx]);
        func(candi, idx, sum - candi[idx], temp, ans);

        temp.pop_back();

        func(candi, idx + 1, sum, temp, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        func(candidates, 0, target, temp, ans);

        return ans;
    }
};