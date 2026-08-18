class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const int& n : nums)
            counts[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (const pair<int, int>& p: counts)
            pq.push({p.second, p.first});

        vector<int> r;

        for (int i=0;i<k;i++) {
            r.push_back(pq.top().second);
            pq.pop();
        }

        return r;    
    }
};
