class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int max_seq = 0;
        int seq = 1;
        for (int i=1;i<nums.size();i++) {
            if (nums[i-1] == nums[i] - 1)
                seq++;
            else if (nums[i-1] != nums[i]) {
                max_seq = max(max_seq, seq);
                seq = 1;
            }
        }
        max_seq = max(max_seq, seq);

        return max_seq;
    }
};
