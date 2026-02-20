class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        int n = nums.size();
        for(auto it:nums){
            mpp[it]++;
        }
       for(auto its:mpp){
        if(its.second > (int)(n/2)){
            return its.first;
        }
       }
       return -1;
    }
};