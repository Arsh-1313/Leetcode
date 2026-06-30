class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int,vector<int>>pq;
        int n=piles.size();
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        while(k--){
            int element=pq.top();
            pq.pop();
            int updatedVal=element-floor(element/2);
            pq.push(updatedVal);
        }
        int count=0;
        while(!pq.empty()){
            count += pq.top();
            pq.pop();
        }
        return count;
    }
};