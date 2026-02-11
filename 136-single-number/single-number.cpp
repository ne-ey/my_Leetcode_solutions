class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<long long,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto its:mpp){
            if(its.second==1) return its.first;
        }
        return 0;
    }
};