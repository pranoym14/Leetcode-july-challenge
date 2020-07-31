class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> res;
        vector <int> l;
        sort(nums.begin(),nums.end());
        backtrack(res,l,nums,0);
        return res;
    }
    void backtrack(vector<vector<int>>& res,vector <int> ans,vector <int> arr,int i)
    {
        res.push_back(ans);
        for(int j=i;j<arr.size();j++)
        {
            ans.push_back(arr[j]);
            backtrack(res,ans,arr,j+1);
            ans.pop_back();
        }
        
    }
};