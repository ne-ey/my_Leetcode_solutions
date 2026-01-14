class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        string new_s;
        for(char ch:s){
          if(isalnum(ch)){
            new_s +=tolower(ch);
          }
        }
        return palin(new_s,new_s.size(),i);
    }
    bool palin(const string& new_s,int length,int i){
        if(i>=length/2) return true;
        if(new_s[i]!=new_s[length-i-1]) return false;
        return palin(new_s,length,i+1);
    }
    };