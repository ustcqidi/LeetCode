//
//  main.cpp
//  HappyNum
//
//  Created by 仓颉 on 16/2/17.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        vector<int> nums;
        
        
        
        while (std::find(nums.begin(), nums.end(), n) == nums.end()) {
            nums.push_back(n);
            n = getSquareSum(n);
        }
        
        return n == 1;
        
    }
    
    int getSquareSum(int n) {
        int sum = 0;
        
        while (n > 0) {
            int digit = n % 10;
            sum += digit*digit;
            
            n = n / 10;
        }
        
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solu;
    std::cout << solu.isHappy(7);
    return 0;
}
