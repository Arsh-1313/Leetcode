class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        unordered_map<int, int> mp;

        for (int task : tasks) {
            mp[task]++;
        }

        // Min-heap based on frequency
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       function<bool(pair<int, int>, pair<int, int>)>>
        pq([](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });

        for (auto &it : mp) {
            pq.push({it.first, it.second});
        }

        int count = 0;

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int task = top.first;
            int freq = top.second;

            if (freq == 0)
                continue;

            else if (freq % 3 == 0) {
                freq -= 3;
            }

            else if (freq == 1) {
                return -1;
            }

            else {
                freq -= 2;
            }

            count++;

            if (freq > 0)
                pq.push({task, freq});
        }

        return count;
    }
};