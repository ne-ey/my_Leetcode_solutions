class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drop = 0;
        for(int i = 1;i< n;i++){
            if(nums[i-1]>nums[i]){
                drop++;
            }
        }
        if(nums[0] < nums[n-1]) drop++;
        if(drop==1 || drop==0){
            return true;
        }
        else{
            return false;
        }
    }
};