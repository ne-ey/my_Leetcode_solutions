class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 1;

        
        while (i < n && nums[i] > nums[i - 1]) i++;
        if (i == 1 || i == n) return false;

        
        int downStart = i;
        while (i < n && nums[i] < nums[i - 1]) i++;
        if (i == downStart || i == n) return false;

        
        int up2Start = i;
        while (i < n && nums[i] > nums[i - 1]) i++;
        if (i == up2Start) return false;

        return i == n;
    }
};
