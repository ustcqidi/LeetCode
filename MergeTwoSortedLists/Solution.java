class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}
}

public class Solution {

	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode head = null;
		
		if(l1 == null && l2 == null)
			return null;
		
		if(l1 == null)
			return l2;
		
		if(l2 == null)
			return l1;
		
		if(l1.val < l2.val) {
			head = l1;
			l1 = l1.next;
		} else {
			head = l2;
			l2 = l2.next;
		}
		
		ListNode curr = head;
		
		while(l1 != null && l2 != null) {
			
			if(l1.val < l2.val) {
				curr.next = l1;
				
				ListNode tmp = l1.next;
				l1.next = null;
				l1 = tmp;
			} else {
				curr.next = l2;
				
				ListNode tmp = l2.next;
				l2.next = null;
				l2 = tmp;
			}
			
			curr = curr.next;
		}
		
		if(l1 != null) {
			curr.next = l1;
		} 
		
		if(l2 != null) {
			curr.next = l2;
		}
		
		return head;
	}

	public static void main(String[] args) {
		Solution soluton = new Solution();
	}

}
