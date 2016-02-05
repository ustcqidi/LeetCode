//
//  main.cpp
//  VerifyPreorder
//
//  Created by 仓颉 on 16/2/3.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class Solution {
public:
    
//    "9,3,4,#,#,1,#,#,2,#,6,#,#"
//    
//    0 -> null
//    1 -> node
//    2 -> #
    bool isValidSerialization(string preorder) {
        
        if (preorder.compare("#") == 0) {
            return true;
        }
        
        if (preorder.size() == 0  || preorder.size() < 3 )
            return false;
        
        int nodes[1024] = {0};
        int nodeCnt = 0;
        
        int last = 0;
        int index=preorder.find_first_of(",",last);
        
        while (index != std::string::npos)
        {
            string nodeValue = preorder.substr(last, index-last);
            last=index+1;
            
            if (nodeValue.compare("#") == 0) {
                if (nodeCnt <= 0) {
                    return false;
                }
                
                //update
                for (int i = nodeCnt-1; i >= 0; i--) {
                    int node = nodes[i];
                    
                    if(node == 0) {
                        nodes[i] = 20;
                        break;
                    } else if(node == 10) {
                        nodes[i] = 12;
                        break;
                    } else if(node == 20) {
                        //pop
                        nodes[i] = 0;
                        nodeCnt--;
                        break;
                    }
                }

            } else {
                
                            if (nodeCnt <= 0) {
                                index=preorder.find_first_of(",",last);
                                nodeCnt++;
                                continue;
                            }
                
                //update
                int i;
                for (i = nodeCnt-1; i >= 0; i--) {
                    int node = nodes[i];
                    
                    if (node == 0) {
                        nodes[i] = 10;
                        break;
                    } else if (node == 10) {
                        nodes[i] = 11;
                        break;
                    } else if (node == 20) {
                        nodes[i] = 21;
                        break;
                    }
                }
                
                if (i < 0)
                    return false;
                nodeCnt++;
            }
            
            index=preorder.find_first_of(",",last);
        }
        
        string nodeValue = preorder.substr(preorder.size()-1, 1);
        
        if (nodeValue.compare("#") == 0) {
            if (nodeCnt <= 0) {
                return false;
            }
            
            //update
            for (int i = nodeCnt-1; i >= 0; i--) {
                int node = nodes[i];
                
                if(node == 0) {
                    nodes[i] = 20;
                    break;
                } else if(node == 10) {
                    nodes[i] = 12;
                    break;
                } else if(node == 20) {
                    //pop
                    nodes[i] = 0;
                    nodeCnt--;
                    break;
                }
            }

        } else {
            

            //update
            int i;
            for (i = nodeCnt-1; i >= 0; i--) {
                int node = nodes[i];
                
                if (node == 0) {
                    nodes[i] = 10;
                    break;
                } else if (node == 10) {
                    nodes[i] = 11;
                    break;
                } else if (node == 20) {
                    nodes[i] = 21;
                    break;
                }
            }
            
            if (i < 0) {
                return false;
            }
            
            nodeCnt++;

        }
        
        for (int i = 0; i < nodeCnt; i++) {
            int node = nodes[i];
            
            if (node == 10 || node == 0 || node == 20) {
                return false;
            }
        }
        
        
        return true;

    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    std::cout << solution.isValidSerialization("#");
    std::cout << solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
    return 0;
}
