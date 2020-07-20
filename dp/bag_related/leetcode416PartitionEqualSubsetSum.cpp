class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        if (sum%2!=0)return false;
        bool** dp = new bool*[nums.size()];
        for (int i=0;i<nums.size();++i)
        {
            dp[i]=new bool [sum/2+1];
        }
        for (int i=0;i<nums.size();++i){
            for (int j=0;j<sum/2+1;++j){
                if(i==0){
                    dp[i][j]=nums[i]==j?true:false;
                    continue;
                }
                dp[i][j]=dp[i-1][j];
                if(j-nums[i]>=0){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]];
                }
            }

        }
        return dp[nums.size()-1][sum/2];
    }
};
