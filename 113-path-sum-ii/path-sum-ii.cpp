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
    vector<vector<int>> ans;
    void preOrder(TreeNode* root,int targetSum,vector<int>temp){
        if(!root) return ;

        // if(targetSum<0) return ;

        temp.push_back(root->val);

        if(!root->left && !root->right && targetSum-root->val==0){
            ans.push_back(temp);
        }

        preOrder(root->left,targetSum-root->val,temp);
        preOrder(root->right,targetSum-root->val,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int>temp;
        if(!root) return ans;
        preOrder(root,targetSum,temp);
        return ans;
    }
};