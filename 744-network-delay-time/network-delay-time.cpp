class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto & i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});    // distane node pq stores always 
        dist[k]=0;

        while(!pq.empty()){
            int currDist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &i : adj[node]){
                int neighbour=i.first;
                int weight=i.second;
                if(currDist+weight <dist[neighbour]){
                    dist[neighbour]=currDist+weight;
                    pq.push({dist[neighbour] ,neighbour});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};