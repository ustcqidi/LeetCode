class Solution {
public:
    string longestPalindrome(string s) {

        if (s.length() <=1 ) {
            return s;
        }

        string ret = s.substr(0, 1); //边界条件
        
        int strLen = s.length();

        for (int i = 0; i < strLen; i++) {
            for (int j = strLen - 1; j > 0; j--) { //两边向中间搜素，否则会TLE
                if (isPalindrome(s, i, j)) {
                    ret = (j-i+1) > ret.length() ? s.substr(i,j-i+1) : ret;
                    break;
                }
            }
        }

        return ret;
    }

    bool isPalindrome(string s, int start, int end) {
        int len = end - start + 1;

        int center = len / 2;

        for (int i = 0; i < center; i++) {
            if (s[start + i] != s[start + len - 1 - i]) {
                return false;
            }
        }

        return true;

    }
};