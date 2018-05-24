class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

public class Solution {

	private ListNode findMidNode(ListNode head) {
		/**
		 * double pointer: 
		 * first pointer go 2 steps everytime, second pointer go 1 step everytime
		 * when the first pointer go to the end of list, the position of second pointer is the mid node 
		 */
		
		ListNode midNode = head, travelNode = head;
		
		while(travelNode != null && travelNode.next != null) {
			midNode = midNode.next;
			
			travelNode = travelNode.next;
			
			if(travelNode != null) {
				travelNode = travelNode.next;
			} else {
				break;
			}
		}
		
		return midNode;
	}

	
	private ListNode reverseList(ListNode head) {

		/**
		 * cool solution for reverse list
		 */
		
		if(head == null || head.next == null)
			return head;
		
		ListNode pre = head, curr = head.next;
		
		while(curr != null) {
			ListNode tmpNode = curr.next;
			
			curr.next = pre;
			
			pre = curr;
			curr = tmpNode;
		}
		
		head.next = null;
		
		return pre;
	}

	private ListNode mergeList(ListNode firstListHead, ListNode secondListHead) {

		ListNode firstListCurr = firstListHead;
		ListNode secondListCurr = secondListHead;
		
		while(secondListCurr != null)
		{
			ListNode firstNodeTmp = firstListCurr.next;
			ListNode secondNodeTmp = secondListCurr.next;
			
			secondListCurr.next = firstListCurr.next;
			firstListCurr.next = secondListCurr;
			
			firstListCurr = firstNodeTmp;
			secondListCurr = secondNodeTmp;
			
		}
		
		return firstListHead;
	}
	
	private static void printList(ListNode head)
	{
		while(head != null) {
			System.out.print(head.val + " ");
			head = head.next;
		}
	}

	public ListNode reorderList(ListNode head) {
		if (head == null || head.next == null)
		    return head;
		    
		ListNode midNode = findMidNode(head);
		ListNode firstListHead = head, secondListHead = midNode.next;
		midNode.next = null;
		
		return mergeList(firstListHead, reverseList(secondListHead));
	}
	
	
	public static void main(String[] args) {
		ListNode n1 = new ListNode(1);
//		ListNode n2 = new ListNode(2);
//		ListNode n3 = new ListNode(3);
//		ListNode n4 = new ListNode(4);
//		ListNode n5 = new ListNode(5);
//		ListNode n6 = new ListNode(6);
		
//		n1.next = n2;
//		n2.next = n3;
//		n3.next = n4;
//		n4.next = n5;
//		n5.next = n6;
		
		Solution solution = new Solution();
		
		printList(solution.reorderList(n1));
	}

}
