class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;

        long long pairs=0;
        long long ans=0;

        int left=0;
        for(int right=0;right<n;right++){
            pairs+=map[nums[right]];
            map[nums[right]]++;

            while(pairs>=k){
                ans+=n-right;
                map[nums[left]]--;
                pairs-=map[nums[left]];
                left++;
            }
        }
        return ans;
    }
};