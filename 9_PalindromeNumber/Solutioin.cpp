class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x<0  || x==10) return false;
        
        if (x<10) return true;
        
        vector<int> digits;
        
        while(x) {
            int a = x % 10;
            digits.push_back(a);
            x = x/10;
        }
        
        for(int i = 0; i < digits.size()/2; i++) {
            if (digits[i] != digits[digits.size()-1-i])
                return false;
        }
        
        return true;
    }
};
