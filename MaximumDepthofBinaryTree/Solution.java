import sun.org.mozilla.javascript.internal.Node;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	
	TreeNode(int x) {
		val = x;
		
		left = null;
		right = null;
	}
}
public class Solution {

	public int maxDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		
		if(root.left == null && root.right == null)
			return 1;

		return Math.max(maxDepth(root.left) ,maxDepth(root.right)) + 1;
	}

	public static void main(String args[]) {

		TreeNode root = new TreeNode(1);
		
		TreeNode node1 = new TreeNode(2);
		TreeNode node2 = new TreeNode(3);
		
		root.left = node1;
		node1.right = node2;
		
		
		Solution solution = new Solution();
		
		System.out.println("" + solution.maxDepth(root));

	}

}
