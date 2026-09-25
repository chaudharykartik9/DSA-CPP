class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = accumulate(candies.begin(), candies.end(), 0LL);

        if (total < k) return 0;

        int low = 1;
        int high = *max_element(candies.begin(), candies.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long children = 0;

            for (int pile : candies) {
                children += pile / mid;
            }

            if (children >= k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};