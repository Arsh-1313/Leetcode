class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>s;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(!s.empty() && temperatures[s.top()]<temperatures[i]){
                int top=s.top();
                s.pop();
                ans[top]=i-top;            
            }
            s.push(i);
        }
        return ans;
    }
};