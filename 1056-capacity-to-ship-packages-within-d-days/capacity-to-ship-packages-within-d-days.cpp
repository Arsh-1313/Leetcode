class Solution {
public:
    bool solve(int totalCapacity,vector<int>weights,int days){
        int Cdays=1;
        int capacity=0;
        for(int i:weights){
            if(i+capacity>totalCapacity){
                Cdays++;
                capacity=i;
            }else{
                capacity+=i;
            }
        }
        if(Cdays > days) return false; 
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(solve(mid,weights,days)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};