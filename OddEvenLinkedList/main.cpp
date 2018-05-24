//
//  main.cpp
//  OddEvenLinkedList
//
//  Created by 仓颉 on 16/2/5.
//  Copyright © 2016年 Aiyi. All rights reserved.
//

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *lastOddPosNode = NULL, *firstEvenPosNode = NULL, *lastEvenPosNode = NULL;
        
        lastOddPosNode = head;
        firstEvenPosNode = head->next;
        lastEvenPosNode = head->next;
        
        int posCount = 3;
        
        ListNode *travelNode = lastEvenPosNode->next;
        
        while (travelNode) {
            
            if (posCount % 2 != 0) {
                
                lastOddPosNode->next = travelNode;
                lastOddPosNode = lastOddPosNode->next;
                travelNode = travelNode->next;
                lastOddPosNode->next = firstEvenPosNode;
                
            } else {
                
                lastEvenPosNode->next = travelNode;
                lastEvenPosNode = lastEvenPosNode->next;
                travelNode = travelNode->next;
                
            }
            

            
            posCount++;
        }
        
        lastEvenPosNode->next = NULL;
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    
    
    ListNode *h1 = new ListNode(2);
    ListNode *h2 = new ListNode(1);
    ListNode *h3 = new ListNode(4);
//    ListNode *h4 = new ListNode(3);
//    ListNode *h5 = new ListNode(6);
//    ListNode *h6 = new ListNode(5);
//    ListNode *h7 = new ListNode(7);
//    ListNode *h8 = new ListNode(8);
    
    h1->next = h2;
    h2->next = h3;
//    h3->next = h4;
//    h4->next = h5;
//    h5->next = h6;
//    h6->next = h7;
//    h7->next = h8;
    
    Solution solution;
    
    ListNode *result = solution.oddEvenList(h1);
    
    return 0;
}
