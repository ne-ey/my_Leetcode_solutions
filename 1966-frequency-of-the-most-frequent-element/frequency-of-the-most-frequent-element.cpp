class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int left_ptr = 0;
        long long sum = 0;
        int maxfreq = 1;

        for(int right_ptr = 0;right_ptr < nums.size();right_ptr++){
            sum +=nums[right_ptr];

            while((long long)(right_ptr - left_ptr + 1) * nums[right_ptr] - sum > k){
                sum -=nums[left_ptr];
                left_ptr++;
            }
            maxfreq = max(maxfreq,right_ptr - left_ptr + 1);
        }
       return maxfreq;
    } 
};