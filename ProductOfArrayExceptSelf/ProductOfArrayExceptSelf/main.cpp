//
//  main.cpp
//  ProductOfArrayExceptSelf
//
//  Created by 仓颉 on 16/2/24.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> pSeq(len);
        vector<int> qSeq(len);
        
        pSeq[0] = 1;
        for(int i = 1; i < len; i++) {
            pSeq[i] = pSeq[i-1] * nums[i-1];
        }
        
        qSeq[len-1] = 1;
        for(int j = len-2; j >=0; j--) {
            qSeq[j] = qSeq[j+1] * nums[j+1];
        }
        
        for(int i = 0; i < len; i++) {
            pSeq[i] *= qSeq[i];
        }
        
        return pSeq;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;
    vector<int> nums;
    nums.push_back(1);
    
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    
    solution.productExceptSelf(nums);
    return 0;
}
