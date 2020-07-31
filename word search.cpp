class Solution {
public:
     bool dfs(vector<vector<char>>& board, int row, int col, const string &word, int index, int M, int N, int sLen)
    {
        char curC;
        bool res = false;
         if(board[row][col]=='*')
             return false;
        if( (curC = board[row][col]) != word[index]) return false;
        if(index==sLen-1) return true;
        board[row][col] = '#';
        if(row>0) res = dfs(board, row-1, col, word, index+1, M, N, sLen);
        if(!res && row < M-1) res = dfs(board, row+1, col, word, index+1, M, N, sLen);
        if(!res && col > 0)   res = dfs(board, row, col-1, word, index+1, M, N, sLen);
        if(!res && col < N-1) res = dfs(board,  row, col+1, word, index+1, M, N, sLen);
        board[row][col] = curC;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int M,N,i,j,sLen = word.size();
        if( (M=board.size()) && (N=board[0].size()) && sLen)
        {
            for(i=0; i<M; ++i)
                for(j=0; j<N; ++j)
                    if(dfs(board, i, j, word, 0, M, N, sLen)) return true;
        }
        return false;
    }

};