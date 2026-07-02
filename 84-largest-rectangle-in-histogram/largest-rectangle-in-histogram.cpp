class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxArea=-1;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int elementTop=st.top();
                st.pop();

                int nse=i;
                int pse= st.empty() ? -1 : st.top();
                //elementTop   st.top()
                int width= nse-pse-1;
                int area= width* heights[elementTop];
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int elementTop=st.top();
            st.pop();

            int nse=n;
            int pse= st.empty() ? -1 : st.top();

            int width= nse-pse-1;
            int area= width* heights[elementTop];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};