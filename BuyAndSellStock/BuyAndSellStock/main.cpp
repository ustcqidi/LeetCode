//
//  main.cpp
//  BuyAndSellStock
//
//  Created by 仓颉 on 16/2/24.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 0) {
            return 0;
        }
        
        int profit = 0;
        int buyInPrice = prices.at(0);

        
        for (int i = 1; i < prices.size(); i++) {
            int todayPrice = prices.at(i);
            
            if (buyInPrice > todayPrice) {
                buyInPrice = todayPrice;
            } else {
                if (i+1 < prices.size()) {
                    int tommoryPrice = prices.at(i+1);
                    if (todayPrice > tommoryPrice) {
                        profit += (todayPrice - buyInPrice);
                        buyInPrice = prices.at(i+1);
                    }
                } else {
                    profit += (todayPrice - buyInPrice);
                }

            }
        }
        
        return profit;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> prices;
    
    prices.push_back(2);
    prices.push_back(1);
    
    std::cout << solution.maxProfit(prices);
    return 0;
}
