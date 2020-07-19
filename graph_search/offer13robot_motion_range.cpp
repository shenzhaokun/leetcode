class Solution {
public:
    int movingCount(int m, int n, int k) {
        bool **visit=new bool*[m];
        for(int i=0;i<m;++i){
            visit[i]=new bool[n];
            for(int j=0;j<n;++j)
                visit[i][j]=false;
        }               
        int count=dfs(m,n,0,0,k,visit); 
        delete[] visit;
        return count;
    }
    int dfs(int m,int n,int x,int y,int k,bool **visit)
    {
        int count=0;
        if(check(m,n,x,y,k,visit)){
            visit[x][y]=true;
            count=1+dfs(m,n,x+1,y,k,visit)+dfs(m,n,x-1,y,k,visit)+dfs(m,n,x,y+1,k,visit)+dfs(m,n,x,y-1,k,visit);
        }
        return count;
    }
    bool check(int m,int n,int x,int y,int k,bool **visit)
    {
        if(x>=0&&x<m&&y>=0&&y<n&&!visit[x][y]&&getNum(x)+getNum(y)<=k)
            return true;
        else return false;
    }
    int getNum(int num)
    {
        int res=0;
        while(num!=0){
            res+=num%10;
            num=num/10;
        }
        return res;
    }
};
