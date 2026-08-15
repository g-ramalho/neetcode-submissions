class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int cand;
        for (const int &n : nums)
            if (count == 0) {
                cand = n;
                count = 1;
            }
            else if (n == cand)
                count++;
            else count--;

        return cand;
    }
};