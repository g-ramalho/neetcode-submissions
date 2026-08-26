class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());

        int longest = 0;

        for (const int &n : numset) {
            if (!numset.contains(n - 1)) {
                int length = 1;
                while (numset.contains(n + length))
                    length++;
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
