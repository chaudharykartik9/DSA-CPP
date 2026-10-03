class Solution{
    private : 
    bool function(vector<int> matrix , int target , int m){
        int low = 0 , high = m-1 ;
        while(low <= high){
            int mid = low + (high- low ) / 2 ;
            if(matrix[mid] == target) return true ;
            else if (matrix[mid] < target) low = mid + 1 ;
            else high = mid -1 ;
        }
        return false ;
    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        int left = 0 , right = n-1 ;
        while(left <= right ){
            int mid = left + (right - left)/2 ;
            if(matrix[mid][0] <= target && target <=matrix[mid][m-1]){
                return function(matrix[mid] , target , m );
            }else if (matrix[mid][0] < target && matrix[mid][m-1] < target)
                left = mid + 1 ;
            else right = mid - 1 ;
        }
        return false ;
    }
};