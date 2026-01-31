class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char letter = letters[0];//c
        for(int i=0;i < letters.size();i++){
            if(letters[i] > target ){
               return letters[i];
            }
        }
        
        return letter;
    }
};