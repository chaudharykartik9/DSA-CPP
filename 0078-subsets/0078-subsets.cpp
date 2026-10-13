#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void func(int idx, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans) {
        if (idx == n) {
            ans.push_back(arr);
            return;
        }
        
        func(idx + 1, n, nums, arr, ans);
        
        arr.push_back(nums[idx]);
        func(idx + 1, n, nums, arr, ans);
        arr.pop_back(); 
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        func(0, nums.size(), nums, arr, ans);
        return ans;
    }
};