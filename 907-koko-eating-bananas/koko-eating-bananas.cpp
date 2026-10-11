class Solution {
public:
    bool check(vector<int>&piles, int h, long long minBananas){
        long long time=0;
        for(int pile:piles){
            time+=ceil((double)pile/minBananas);
        }
        return time<=h ? true : false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        long long high=accumulate(piles.begin(),piles.end(),0LL);

        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;

            if(check(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};