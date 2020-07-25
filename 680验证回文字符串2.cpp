class Solution {
public:
    bool validPalindrome(string s) {
        int left=0,right=s.size()-1;
        if (right<=1)return true;
        while(left<=right){
            if(s[left]==s[right]){
                ++left;
                --right;                
            }
            else if(s[left!=s[right]]){
                    string s1(s.begin()+left,s.begin()+right);
                    string s2(s.begin()+left+1,s.begin()+right+1);
                    return validPalindrome1(s1)||validPalindrome1(s2);
            }
        }
        return true;
    }
    bool validPalindrome1(string s){
        int left=0,right=s.size()-1;
        if (right<=0)return true;
        while(left<=right){
            if(s[left]==s[right]){
                ++left;
                --right;                
            }
            else return false;
        }
        return true;
    }
};
