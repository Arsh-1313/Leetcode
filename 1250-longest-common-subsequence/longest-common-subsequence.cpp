class Solution {
public:
    int solve(string &text1,string &text2 , vector<vector<int>>& dp,int i,int j){

        if(i==text1.length() || j==text2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]) return dp[i][j] =1 + solve(text1,text2,dp,i+1,j+1);

        return dp[i][j]=max(solve(text1,text2,dp,i+1,j) , solve(text1,text2,dp,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        if(n<m) return longestCommonSubsequence(text2,text1);
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(text1,text2,dp,0,0);
    }
};