class Solution {
public:
    bool eq(char c1, char c2) {
        return (c1 & 0b11011111) == (c2 & 0b11011111);
    }
    bool isAlphanumeric(char &c) {
        if ((c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int right = s.size()-1, left = 0;
        while (left < right) {
            while (left < s.size() && !isAlphanumeric(s[left])) left++;
            while (right >= 0 && !isAlphanumeric(s[right])) right--;
            if (!eq(s[left], s[right]))
                return false;
            left++;
            right--;
        }
        while (left < s.size() && !isAlphanumeric(s[left])) left++;
        while (right >= 0 && !isAlphanumeric(s[right])) right--;
        return eq(s[left], s[right]);
    }
};
