class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows <=1)
            return s;
        
        vector<string> zigzag(numRows, "");
        
        int circle = numRows*2 - 2;
        
        for (int i = 0; i < s.size(); i++) {
            if (i % circle < numRows)
                zigzag[i%circle] += s[i];
            else 
                zigzag[circle - i%circle] += s[i];
        }
        
        string ret="";
        
        for(auto a : zigzag) {
            ret += a;
        }
        
        return ret;
        
    }
};
