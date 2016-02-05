class Solution {
public:
    bool isPowerOfThree(int n) {
        double result = log10(n) / log10(3);
        
        if (result - (int) result == 0)
            return  true;
        else
            return false;
    }
};
