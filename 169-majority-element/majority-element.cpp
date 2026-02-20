class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //optimal
        int cnt = 0;
        int el;
        int n = nums.size();
        for(int i=0;i < n;i++){
            if(cnt==0){
                cnt = 1;
                el = nums[i];
            }
            else if(el==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int cnt1 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==el) cnt1++;
        }
        if(cnt1 > (int)(n/2)){
            return el;
        }

      return -1;  
    }
};