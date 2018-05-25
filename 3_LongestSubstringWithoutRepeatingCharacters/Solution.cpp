class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.length() <= 1)
            return s.length();

        int maxLen = 0;
	    map<char, int> smap;
	    int start = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (smap.find(c) != smap.end()) {
                int idx = smap[c];
                if (start <= idx) {
                    start = idx + 1;
                }
            }

            smap[c] = i;

            maxLen = max(maxLen , i - start + 1);
        }

        return maxLen;
    }
};                     