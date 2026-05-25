class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=accumulate(gas.begin(),gas.end(),0);
        int totalCost=accumulate(cost.begin(),cost.end(),0);
        
        int n=gas.size();
        int start=0;
        int diff=0;
        if(totalGas<totalCost) return -1;
        for(int i=0;i<n;i++){
            diff+=gas[i]-cost[i];
            if(diff<0){
                start=i+1;
                diff=0;
            }
        }
        return start;
    }
};