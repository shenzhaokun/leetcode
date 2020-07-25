class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()||matrix[0].empty())return res ;
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=0,di=0,dj=1;
        vector<int> visited(m*n);
        for (int k=0;k<m*n;++k){
            res.push_back(matrix[i][j]);
            visited[i*n+j]=1;
            if(visited[((i+di)%m)*n+(j+dj)%n]==1){
                int temp=di;
                di=dj;
                dj=-temp;
            }
            i+=di;
            j+=dj;
        }
        return res;
    }
};
