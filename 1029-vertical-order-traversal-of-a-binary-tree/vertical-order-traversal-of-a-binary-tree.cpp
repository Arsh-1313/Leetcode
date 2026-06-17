class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL ) return ans;

        map<int,vector<pair<int,int>>>dist;
        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,0});

        while(!q.empty()){
            auto [element,height,depth]=q.front();

            q.pop();

            dist[height].push_back({depth,element->val});

            if(element->left){
                q.push({element->left,height-1,depth+1});
            }
            if(element->right){
                q.push({element->right,height+1,depth+1});
            }
        }
        for(auto& p: dist){
            sort(p.second.begin(),p.second.end());
            vector<int>col;
            for(auto& [u,v]: p.second){
                col.push_back(v);
            }
            ans.push_back(col);
        }
        return ans;
    }
};