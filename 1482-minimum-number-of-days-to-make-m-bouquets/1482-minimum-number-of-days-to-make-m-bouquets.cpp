class Solution {
private:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;

        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long required = 1LL * m * k;

        if (required > bloomDay.size()) {
            return -1;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int left = mini;
        int right = maxi;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};