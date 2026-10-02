
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> rowAndMaximumOnes(std::vector<std::vector<int>>& mat) {
        int maxOnesRowIndex = 0;
        int maxOnesCount = 0;
        
        for (int i = 0; i < mat.size(); i++) {
            int currentOnesCount = 0;
            
            // Count the number of 1s in the current row
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    currentOnesCount++;
                }
            }
            
            // Update if we find a row with strictly more 1s
            // (Using '>' preserves the smallest row index for ties)
            if (currentOnesCount > maxOnesCount) {
                maxOnesCount = currentOnesCount;
                maxOnesRowIndex = i;
            }
        }
        
        return {maxOnesRowIndex, maxOnesCount};
    }
};
