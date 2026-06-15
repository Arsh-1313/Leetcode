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
    vector<int> right(TreeNode* root,int levels,vector<int>& ans){
        if(root==NULL) return ans;

        if(ans.size()==levels) ans.push_back(root->val);
        right(root->right,levels+1,ans);
        right(root->left,levels+1,ans);

        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        return right(root,0,ans);
    }
};