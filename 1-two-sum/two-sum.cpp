class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //better solution
        int n = nums.size();
        map<int,int> mpp;
        for(int i = 0;i < n;i++){
            int ele_needed = target - nums[i];
            if(mpp.find(ele_needed)== mpp.end()){
                mpp[nums[i]] = i;
            }
            else if(mpp.find(ele_needed) != mpp.end()){
                return {i,mpp[ele_needed]};
            }
        }
        return {};
    }
};