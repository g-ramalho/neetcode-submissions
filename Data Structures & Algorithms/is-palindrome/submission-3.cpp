class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.size()-1, left = 0;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right &&!isalnum(s[right])) right--;
            if (toupper(s[left]) != toupper(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
