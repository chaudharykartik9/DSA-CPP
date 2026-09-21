class Solution {

private:
    long long sumByD(vector<int>& piles, int limit) {
        long long sum = 0;

        for (int i = 0; i < piles.size(); i++) {
            sum += (piles[i] + limit - 1) / limit;
        }

        return sum;
    }

public:
    int minEatingSpeed(vector<int> piles, int h) {

        if (piles.size() > h)
            return -1;

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = sumByD(piles, mid);

            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};