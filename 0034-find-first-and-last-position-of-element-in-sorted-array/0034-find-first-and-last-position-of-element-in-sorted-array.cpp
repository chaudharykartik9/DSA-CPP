class Solution {
    private:
    int firstOccurrence(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0 ; 
        int high = n-1 ;
        int mid ;
        int ans  = -1 ;
        while(low <= high){
            mid = low + (high - low)/2 ;
            if(nums[mid] == target){
                ans = mid ;
                high = mid -1 ; 
            }else if(nums[mid] < target){
                low = mid + 1 ;
            }else{
                high = mid -1 ;
            }

        }
        return ans ;
     
    }
    int lastOccurrence(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0 ; 
        int high = n-1 ;
        int mid ;
        int ans=  -1 ;
        while(low <= high){
            mid = low + (high - low)/2 ;
            if(nums[mid] == target){
                ans = mid ;
                low = mid+1 ; 
            }else if(nums[mid] < target){
                low = mid + 1 ;
            }else{
                high = mid -1 ;
            }

        }
        return ans ;
     
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target); 
        
        // If the target is not present in the array
        if(first == -1) return {-1, -1};  
        int last = lastOccurrence(nums, target);  

        return {first, last};        
        
    }
};