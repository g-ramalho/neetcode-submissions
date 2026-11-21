class KthLargest {
private:
    const int K;
    vector<int> pq;
public:

    KthLargest(int k, vector<int>& nums) : K(k) {
        pq = nums;
        sort(pq.begin(), pq.end());
    }

    int add(int val) {
        auto idx = lower_bound(pq.begin(), pq.end(), val);
        pq.insert(
            idx,
            val
        );

        return pq[pq.size() - K];
    }
};
