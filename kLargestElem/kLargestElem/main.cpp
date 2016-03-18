//
//  main.cpp
//  kLargestElem
//
//  Created by 仓颉 on 16/2/27.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // int kmax = nums[0];
        
        long len = nums.size();
        
        for(int i = 0; i < k; i++) {
            for(int j = i+1; j < len; j++) {
                if(nums[i] < nums[j]) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        
        return nums[k-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    
    int n[] = {3,2,1,5,6,4};
    vector<int> nums(n, n + sizeof(n) / sizeof(int));
    
    
    
    std::cout << s.findKthLargest(nums, 5);
    return 0;
}
