
class Solution {
   private:
    void func(int idx, int sum, vector<int>& temp, vector<vector<int>>& ans,
              vector<int>& candidates) {
        if (sum == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == candidates.size() || sum < 0) {
            return;
        }

        temp.push_back(candidates[idx]);
        func(idx + 1, sum - candidates[idx], temp, ans, candidates);
        temp.pop_back();

        int next = idx + 1;

        while (next < candidates.size() &&
               candidates[next] == candidates[idx]) {
            next++;
        }

        func(next, sum, temp, ans, candidates);
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        func(0, target, temp, ans, candidates);

        return ans;
    }
};
