class Solution {
public:
    int bitwiseComplement(int n) {
    int last_digit;
    int ans = 0;
    int mul = 1; 
    if(n==0) return 1;
    while (n != 0) {
        last_digit = n % 2;      
        last_digit = last_digit ^ 1; 
        ans = ans + last_digit * mul; 
        mul = mul * 2;           
        n = n / 2;                
    }
    return ans;
    }
};