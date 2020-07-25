class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> win;
        int left=0,right=0;
        int res=0;
        while(right<s.size()){
            char ch1=s[right];
            win[ch1]++;
            ++right;
            while(win[ch1]>1){
                char ch2=s[left];
                win[ch2]--;
                ++left;
            }
            res=max(res,right-left);
        }
        return res;
    }
};
