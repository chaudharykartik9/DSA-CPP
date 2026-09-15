class Solution {
private:
    int func(vector<int> &nums, int low, int high, int target) {
        if(low > high) return -1;
        int ind; 
        int mid = low + (high - low)/2;
        if(nums[mid] == target) ind = mid;
        else if(nums[mid] > target) ind = func(nums, low, mid-1, target);
        else ind = func(nums, mid+1, high, target);
        return ind; 
    }
    
public:
    int search(vector<int>& nums, int target) {
         int n = nums.size();
        return func(nums, 0, n-1, target);
        
    }
};