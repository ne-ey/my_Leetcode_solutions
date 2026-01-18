class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        int ans = 0;
        map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        for(auto its:mpp){
            maxi = max(its.second,maxi);
        }
        for(auto iss:mpp){
            if(maxi == iss.second){
                count ++;
            }
        }
       ans = maxi * count;

     return ans;
    }
};