class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0;i<board.size();++i)
            for(int j=0;j<board[0].size();++j)
            {
                if (board[i][j]==word[0])
                    if(dfs(board,word,i,j,0))
                        return true;

            }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word,int x,int y,int i)
    {   if(i==word.size())
            return true;
        if(!inArea(board,x,y))return false;
        if (board[x][y]==word[i])
            board[x][y]=' ';
        else return false;
        bool res=dfs(board,word,x+1,y,i+1)||dfs(board,word,x,y+1,i+1)||dfs(board,word,x-1,y,i+1)||dfs(board,word,x,y-1,i+1);
        board[x][y]=word[i];
        return res;
    }
    bool inArea(vector<vector<char>>& board,int x, int y)
    {
        if(x>=0&&x<=board.size()-1&&y>=0&&y<=board[0].size()-1&&board[x][y]!=' ') return true;
        return false;
    }
};
