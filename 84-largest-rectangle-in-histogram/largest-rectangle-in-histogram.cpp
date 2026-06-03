class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        long long  maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int element= st.top();
                st.pop();

                int nse=i;
                int pse=st.empty() ? -1 : st.top();

                long long  width=nse-pse-1;
                long long  area=width* heights[element];
                maxArea=max(area,maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element =st.top();
            st.pop();

            int nse=n;
            int pse=st.empty() ? -1 : st.top();

            long long  width=nse-pse-1;
            long long  area=width*heights[element];

            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};