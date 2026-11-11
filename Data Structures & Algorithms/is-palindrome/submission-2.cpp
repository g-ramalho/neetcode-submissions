class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.size()-1, left = 0;
        while (left < right) {
            while (!isalnum(s[left])) left++;
            while (!isalnum(s[right])) right--;
            if (left < right && toupper(s[left]) != toupper(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
