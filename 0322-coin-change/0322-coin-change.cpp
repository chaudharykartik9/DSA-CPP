class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, amount + 1);

        // Base case
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};