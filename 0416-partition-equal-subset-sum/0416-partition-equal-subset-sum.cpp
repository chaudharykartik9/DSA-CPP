class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (int x : nums) {
            total += x;
        }

        if (total % 2 != 0) return false;

        int k = total / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= k; sum++) {

                // Not pick
                dp[i][sum] = dp[i - 1][sum];

                // Pick
                if (sum >= nums[i - 1]) {
                    dp[i][sum] = dp[i][sum] ||
                                 dp[i - 1][sum - nums[i - 1]];
                }
            }
        }

        return dp[n][k];
    }
};