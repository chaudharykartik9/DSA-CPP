class Solution {
    private: 
    // function to check gap is possible 
    bool isPossible(vector<int> &nums, int cows , int maxGap){
          int n = nums.size(); 
        
        // Number of cows placed
        int cntCows = 1; 
        
        // Position of last placed cow
        int last = nums[0]; 
            for (int i = 1; i < n; i++) {
            if (nums[i] - last >= maxGap) {
                
                // Place next cow
                cntCows++; 
                
                // Update the last location
                last = nums[i]; 
            }
            if (cntCows >= cows) return true;
        }
        return false;

    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin() , position.end());
        // range of BS
        int low = 1 , high = position[position.size()-1 ] - position[0];
        while(low <= high ){
            int mid = low + (high - low ) /2 ;
            if(isPossible(position, m , mid )){
                low = mid+1 ;
            }else{
                high = mid -1 ;
            }
        }
        return high ;
        
    }
};