class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int startingrow=0;
        int startingcol=0;
        int endingrow=n-1;
        int endingcol=m-1;

        vector<int>ans;
        int total=0;
        while(total<n*m){
            // first row
            for(int col= startingcol;total<n*m && col<=endingcol;col++){
                ans.push_back(matrix[startingrow][col]);
                total++;
            }
            startingrow++;
            // last column
            for(int row=startingrow;total<n*m && row<=endingrow;row++){
                ans.push_back(matrix[row][endingcol]);
                total++;
            }
            endingcol--;
            // last row 
            for(int col=endingcol;total<n*m && startingcol<=col;col--){
                ans.push_back(matrix[endingrow][col]);
                total++;
            }
            endingrow--;
            // first column
            for(int row=endingrow;total<n*m && startingrow<=row;row--){
                ans.push_back(matrix[row][startingcol]);
                total++;
            }
            startingcol++;
        }
        return ans;
    }
};