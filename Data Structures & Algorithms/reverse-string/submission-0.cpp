class Solution {
public:
    void reverseString(vector<char>& s) {
        int right=s.size()-1;
        for (int left=0;left<right;left++) {
            swap(s[left], s[right]);
            right--;
        }
    }
};