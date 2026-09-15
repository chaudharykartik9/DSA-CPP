class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = n ;
        int low = 0;
        int high = n - 1;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
                ans = mid ;
            } else {
                low = mid + 1;
            }
        }
        return ans ;
    }
        
    
};