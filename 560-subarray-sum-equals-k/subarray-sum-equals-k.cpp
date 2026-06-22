class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;
        map[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            count+=map[sum-k];
            map[sum]++;
        }
        return count;
    }
};