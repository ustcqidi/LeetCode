class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

public class Solution {

	public ListNode removeElements(ListNode head, int val) {
		if (head == null)
			return null;

		while (head.val == val) {

			if (head.next == null)
				return null;
			else {
				head = head.next;
			}
		}

		ListNode pre = head, curr = head.next;

		while (curr != null) {
			if (curr.val == val) {
				pre.next = curr.next;
				curr.next = null;
				curr = pre.next;
			} else {
				pre = curr;
				curr = curr.next;
			}
		}

		return head;
	}

	private static void printList(ListNode head) {
		while (head != null) {
			System.out.print(" " + head.val);
			head = head.next;
		}
	}

	public static void main(String args[]) {

		ListNode n1 = new ListNode(1);
		ListNode n2 = new ListNode(3);
		ListNode n3 = new ListNode(1);
		// ListNode n4 = new ListNode(3);

		n1.next = n2;
		n2.next = n3;
		// n3.next = n4;

		Solution solution = new Solution();

		printList(solution.removeElements(n1, 1));

	}

}
