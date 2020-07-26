class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        stack<int>monoStack;
        for(int i=0;i<height.size();++i){
            while(!monoStack.empty()&&height[monoStack.top()]<height[i]){
                int cur=monoStack.top();
                monoStack.pop();
                if (monoStack.empty()) break;
                int l=monoStack.top();
                ans+=(i-l-1)*(min(height[i],height[l])-height[cur]);
            }
            monoStack.push(i);
        }
        return ans;
    }
};
