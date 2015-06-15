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

	public TreeNode invertTree(TreeNode root) {
		
		if(root == null)
			return root;
		
		if(root.left == null && root.right == null)
			return root;
		
		
		TreeNode tmp = root.left;
		root.left = root.right;
		root.right = tmp;
		
		if(root.left != null)
			invertTree(root.left);
		
		if(root.right != null)
			invertTree(root.right);
		
		return root;

	}

	private void travelTree(TreeNode root) {
		if(root == null) 
			return;
		
		System.out.print(" " + root.val);
		
		travelTree(root.left);
		travelTree(root.right);
	}
	
	public static void main(String[] args) {
		
		Solution s = new Solution();
		
		TreeNode root = new TreeNode(4);
		TreeNode t1 = new TreeNode(2);
		TreeNode t2 = new TreeNode(7);
		TreeNode t3 = new TreeNode(1);
		TreeNode t4 = new TreeNode(3);
		TreeNode t5 = new TreeNode(6);
		TreeNode t6 = new TreeNode(9);
		
		root.left = t1;
		root.right = t2;
		
		t1.left = t3;
		t1.right = t4;
		
		t2.left = t5;
		t2.right = t6;
		
		s.travelTree(root);
		
		System.out.println();
		
		s.travelTree(s.invertTree(root));

	}

}
