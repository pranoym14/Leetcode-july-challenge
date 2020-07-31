class Solution {
public:
    int cnt=0;
    void dfs(vector<vector<int>>& grid,vector <vector<bool>>& visited,int i,int j ,int m,int n)
     {
         if(i<0 || j<0 || i>=m || j>=n)
             return;
         if(grid[i][j]==0 || visited[i][j])
             return;
        // cnt++;
        int x=0;
        if(i+1>=m || j<0 || j>=n || grid[i+1][j]==0)
            x++;
        if(j+1>=n || i<0 || i>=m || grid[i][j+1]==0)
            x++;
        if(i-1<0 || j<0 || j>=n || grid[i-1][j]==0)
            x++;
        if(j-1<0 || i<0 || i>=m || grid[i][j-1]==0)
            x++;
        cnt+=x;
        // cout<<x;
        visited[i][j]=true;
         dfs(grid,visited,i+1,j,m,n);
        dfs(grid,visited,i,j+1,m,n);
        dfs(grid,visited,i-1,j,m,n);
        dfs(grid,visited,i,j-1,m,n);

     }
    int numIslands(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector <bool>> visited(m,vector<bool>(n,false));        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    cnt=0;
                     dfs(grid,visited,i,j,m,n);
                        res=max(res,cnt);
                }
               
            }
        }
        return res;
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        return numIslands(grid);
    }
};