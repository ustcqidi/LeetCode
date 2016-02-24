//
//  main.cpp
//  ValidAnagram
//
//  Created by 仓颉 on 16/2/24.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            return false;
        }
        
        if (s.size() == 0 && t.size() == 0) {
            return true;
        }
        
        for (int i = 0 ; i < s.size(); i++) {
            char c = s.at(i);
            
            size_t c_index = t.find(c);
            
            if (c_index == string::npos) {
                return false;
            } else {
                t.erase(t.begin() + c_index);
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    
    
    std::cout << solution.isAnagram(s, t);
    return 0;
}
