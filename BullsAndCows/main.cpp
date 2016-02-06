//
//  main.cpp
//  BullsAndCows
//
//  Created by 仓颉 on 16/2/6.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

//1. unordered_map
//2. to_string

class Solution {
public:
    string getHint(string secret, string guess) {

        map<char, int> digitPos;
        
        int bullCnt = 0, cowsCnt = 0;
        
        for (int i = 0; i < secret.size(); i++) {
            char digit = secret.at(i);
            
            if (guess.at(i) == digit) {
                bullCnt++;
            } else {
                if (digitPos.find(digit) == digitPos.end()) {
                    digitPos[digit] = 1;
                } else {
                    digitPos[digit]++;
                }
            }
        }
        

        
        for (int i = 0; i < guess.size(); i++) {
            char guessDigit = guess.at(i);
            
            if(digitPos.find(guessDigit) != digitPos.end() && guessDigit != secret.at(i)) {
                
                if (digitPos[guessDigit] > 0) {
                    cowsCnt++;
                    digitPos[guessDigit]--;
                }
                
            }
        }
        
        string result = to_string(bullCnt) + "A" + to_string(cowsCnt) + "B";
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    std::cout << solution.getHint("11", "01");
    return 0;
}

