//
//  main.cpp
//  MajorityElement
//
//  Created by 仓颉 on 16/2/24.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cadidate = nums[0];
        int count = 1;
        
        long len = nums.size();
        
        for (int i = 1; i < len; i++) {
            if (count == 0) {
                count = 1;
                cadidate = nums[i];
            } else if (cadidate == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        
        return cadidate;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
