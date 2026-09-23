class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = static_cast<int>(arr.size());

        while (left < right) {
            int middle = left + (right - left) / 2;
            int missing = arr[middle] - (middle + 1);

            if (missing < k) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        return left + k;
    }
};