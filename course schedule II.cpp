class Solution {
public:
    stack <int> s;
    bool dfs(vector<int> adj[], int v, vector<int>& dp) {

 		if (dp[v]){
            // cout<<dp[v];
 			return dp[v] == 1;}

 		dp[v] = -1;

 		for (auto it : adj[v])
 			if (!dfs(adj, it, dp))
 				return false;

 		dp[v] = 1;

 		return true;
 	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
       vector <int> adj[numCourses]; 
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int V=numCourses;
        vector<int>dp(V, 0);
 		for (int i = 0; i < V; i++) { 
 			if (!dfs(adj, i, dp))
 			    return false;
 		}
        return true;

    }
    void dfs(int i,vector<int> adj[], vector <bool>& visited)
    {
        if(visited[i])
            return;
        visited[i]=true;
        for(auto k:adj[i])
        {
            if(!visited[k])
                dfs(k,adj,visited);
        }
        s.push(i);
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector <int> adj[n];
        vector <int> res;
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        if(!canFinish(n,prerequisites))
            return res;
        vector <bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                dfs(i,adj,visited);
        }
        
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};