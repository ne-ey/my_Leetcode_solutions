class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result; 
        int p = nums.size(); 
        
        for (int i = 0; i < p; i++) { 
            int m = 0; 
            
            if (nums[i] < 0) {
                
                m = ((i - abs(nums[i])) % p + p) % p; 
                result.push_back(nums[m]);
            } 
            
            if (nums[i] > 0) {
                
                m = (i + nums[i]) % p; 
                result.push_back(nums[m]); 
            }
            
            if (nums[i] == 0) {
            
                result.push_back(nums[i]);
            }
        }
        
        
        for (int j = 0; j < p; j++) {
            cout << result[j] << endl;
        }
        
        return result;
    }
};
