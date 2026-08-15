class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_idx_map;

        for (size_t i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (val_idx_map.count(complement) && val_idx_map[complement] != i)
                return {val_idx_map[complement], (int)i};

            val_idx_map[nums[i]] = i;
        }

        return {};
    }
};
