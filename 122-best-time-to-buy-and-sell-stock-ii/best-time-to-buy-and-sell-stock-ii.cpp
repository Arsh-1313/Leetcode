class Solution {
public:
    int solve(vector<int>& prices,vector<vector<int>>&dp,int i,int buy){
        int n=prices.size();
        if(i== n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy){
            int take=(-prices[i]+solve(prices,dp,i+1,0));
            int skip=0+solve(prices,dp,i+1,1);
             
             profit=max(take,skip);
        }
        else{
            int sell=prices[i]+solve(prices,dp,i+1,1);
            int skip=0+solve(prices,dp,i+1,0);
            profit=max(sell,skip);
        }
        

        dp[i][buy]=profit;
        return dp[i][buy];

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,dp,0,1);
    }
};