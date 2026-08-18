class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color_counts[3] = {0};

        for (const int& n : nums)
            color_counts[n]++;
        
        int k=0;
        for (int i=0;i<3;i++)
            for (int j=0;j<color_counts[i];j++) {
                nums[k] = i;
                k++;
            }
    }
};