class Solution {
public:
    void dfs(vector<vector<int>>& res,vector<vector<int>>& graph,vector <int> ans,int i,int d,int n)
    {
        if(i==d)
        {
            ans.push_back(d);
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        ans.push_back(i);
        for(auto u:graph[i])
        {
            dfs(res,graph,ans,u,d,n);
        }
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int src=0,des=n-1;
        vector<vector<int>> res;vector <int> l;
        dfs(res,graph,l,src,des,n);
        return res;
    }
};