/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> v;
        for(int i=0;i<size;i++)
        {
            TreeNode * curr=q.front();
            q.pop();
            v.push_back(curr->val);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        res.push_back(v);
    }
        vector<vector<int>> res1;
    for(int i=res.size()-1;i>=0;i--)
    {
        vector<int> m;
        for(int j=0;j<res[i].size();j++)
        {
            m.push_back(res[i][j]);
        }
        res1.push_back(m);
    }
    
        return res1;
    }
};