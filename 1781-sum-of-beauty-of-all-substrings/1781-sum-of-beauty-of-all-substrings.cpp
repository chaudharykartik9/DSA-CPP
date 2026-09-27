class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;

                int maxFreq = 0, minFreq = INT_MAX;

                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }

                totalBeauty += maxFreq - minFreq;
            }
        }

        return totalBeauty;
    }
};