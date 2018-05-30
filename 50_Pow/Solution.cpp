class Solution {
public:
    map<int, int> sMap;
    
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
    
        if (n > 0) {
            double ret = pow(x, n);
            return ret;
        } else {
            double ret = pow(x, -n);
            return 1/ret;
        }
    }
    
    double pow(double x, int n) {
        if (n == 0)
            return 1;
        
        if (n == 1) 
            return x;
        
        double ret = pow(x, n/2);
        
        return ret*ret*(n%2?x:1);
    }
};
