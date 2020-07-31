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
    TreeNode* fun(int start,int end,vector<int>& postorder,int& pIndex,unordered_map<int,int>& map)
    {
        if(start>end)
            return nullptr;
       TreeNode *root = new TreeNode(postorder[pIndex--]);
        int index = map[root->val];

        root->right = fun(index + 1, end, postorder, pIndex, map);
        root->left = fun(start, index - 1, postorder, pIndex, map);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        int p=inorder.size()-1;
        return fun(0,inorder.size()-1,postorder,p,m);
    }
};