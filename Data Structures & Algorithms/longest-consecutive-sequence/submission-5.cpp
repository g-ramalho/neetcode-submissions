class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> boundaries;

        int longest = 0;

        for (const int &n : nums)
            if (!boundaries[n]) {
                boundaries[n] = boundaries[n - 1] + boundaries[n + 1] + 1;

                boundaries[n - boundaries[n - 1]] = boundaries[n];
                boundaries[n + boundaries[n + 1]] = boundaries[n];

                longest = max(longest, boundaries[n]);
            }

        return longest;
    }
};
