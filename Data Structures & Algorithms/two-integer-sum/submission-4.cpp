class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_idx_map;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (val_idx_map.contains(complement))
                return {val_idx_map[complement], i};

            val_idx_map[nums[i]] = i;
        }

        return {};
    }
};
