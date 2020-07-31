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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
         queue<TreeNode *> q;
        unordered_map<TreeNode*,double> m;
    q.push(root);m[root]=pow(2,-30);int res=1;
    while(!q.empty())
    {
        int size=q.size();
        TreeNode* first,*last;
        for(int i=0;i<size;i++)
        {
            TreeNode * curr=q.front();
            q.pop();
            if(i==0)
                first=curr;
            if(i==size-1)
                last=curr;
            if(curr->left){
                q.push(curr->left);
                m[curr->left]=2*m[curr];
                
            }
            if(curr->right){
                q.push(curr->right);
                m[curr->right]=2*m[curr]+pow(2,-30);
            }
                
        }
        if(last==first)
        {
        }
       else if(res<((m[last]-m[first])*pow(2,30)+1))
           res=(m[last]-m[first])*pow(2,30)+1;
    }
    return res;
        
    }
};