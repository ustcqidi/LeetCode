/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *resultHeadNode = NULL;
        ListNode *resultP = NULL;

        ListNode *p1 = l1;
        ListNode *p2 = l2;

        int carry = 0;

        while (p1 || p2) {
            int sum = p1 != NULL ? p1->val : p2->val;
            
            if (p1 && p2) {
                sum = p1->val + p2->val;
            }

            if (carry != 0) {
                sum += carry;
                carry = 0;
            }

            if (sum >= 10) {
                carry += 1;
                sum = sum - 10;
            }

            ListNode *node = new ListNode(sum);
            
            if (resultHeadNode == NULL) {
                resultHeadNode = node;
                resultP = node;
            } else {
                resultP->next = node;
                resultP = node;
            }

            if (p1)
                p1 = p1->next;

            if (p2)    
                p2 = p2->next;
        }

        if (carry > 0) {
            ListNode *node = new ListNode(1);
            resultP->next = node;
            resultP = node;
        }

        return resultHeadNode;
        
    }
};