//
//  main.cpp
//  MergeSortedArray
//
//  Created by 仓颉 on 16/3/15.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums2Idx = 0;


        while (nums2Idx < n) {
            
            int i ;
            for ( i = 0; i < m+nums2Idx; i++) {
                if (nums2[nums2Idx] <= nums1[i]) {
                    nums1.insert(nums1.begin()+i, nums2[nums2Idx]);
                    break;
                }
            }
            
            if (i >= m+nums2Idx) {
                nums1.insert(nums1.begin()+m+nums2Idx, nums2[nums2Idx]);
            }
            
            nums2Idx++;
        }
        
        for (long i = nums1.size()-1; i >= nums1.size()-m-n-1; i--) {
            nums1.erase(nums1.begin()+i);
        }

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    int num1[] = {4, 5, 6, 0,0,0};
    int num2[] = {1, 2, 3};
    
    vector<int> n1(num1, num1+6);
    vector<int> n2(num2, num2+3);
    
    Solution solution;
    
    solution.merge(n1, 3, n2, 3);
    
    std::cout << "Hello, World!\n";
    
    return 0;
}
