//
//  main.cpp
//  CoinChange
//
//  Created by 仓颉 on 16/3/17.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //d(i) = min{ d(i-vj)+1 } , i - vj > 0;
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> minCnt;
        minCnt.push_back(0);
        
        for(int i = 1; i <= amount; i++) {
            
            int di = 100;
            
            for(int j = 0; j < coins.size(); j++) {
                int vj = coins.at(j);
                
                if (i-vj > 0) {
                    di = di > minCnt[i-vj]+1 ? minCnt[i-vj]+1:di;
                } else if (i-vj == 0) {
                    di = 1;
                    break;
                }
            }
            
            minCnt.push_back(di);
            
        }
        
        return minCnt[amount] == 100 ? -1 : minCnt[amount];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> v;
//    v.push_back(1);
    v.push_back(2);
//    v.push_back(5);

    
    Solution so;
    
//    so.coinChange(v, 3);
    
    std::cout << "Hello, World!\n" << so.coinChange(v, 3) << "\n";
    return 0;
}
