//
//  main.cpp
//  ContainsDuplicateII
//
//  Created by 仓颉 on 16/3/6.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        for (int i = 0; i < nums.size(); i++) {
            
            int tmp = i + k;
            
            while (tmp < nums.size()) {
                
                if (nums[i] == nums[tmp]) {
                    return true;
                }
                
                tmp++;
            }
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
