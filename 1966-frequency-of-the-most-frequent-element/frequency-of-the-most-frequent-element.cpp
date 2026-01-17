class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        long long sum = 0;
        int ans = 1;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while ((long long)(j - i + 1) * nums[j] - sum > k) {
                sum -= nums[i];
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
